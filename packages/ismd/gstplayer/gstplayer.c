#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <locale.h>
#include <glib.h> 

#include <gst/gst.h>
#include <gst/interfaces/navigation.h>


#define TARGET  "gstplayer"
#define VERSION "0.0.1"

//#define DEBUG_TAGS

/* event_loop return codes */
typedef enum _EventLoopResult {
    ELR_NO_ERROR = 0,
    ELR_ERROR,
    ELR_INTERRUPT
} EventLoopResult;

static GstElement *    gPipeline    = NULL;
static gboolean        gIsLive      = FALSE;
static gboolean        gWaitingEOS  = FALSE;
static gboolean        gBuffering   = FALSE;
static gboolean        gError       = FALSE;
static gboolean        gEOS         = FALSE;
static GstState        gState       = GST_STATE_VOID_PENDING;
static gint64          gPos         = 0;
static gint64          gDur         = 0;
static gdouble         gSpeed       = 1.0;
//Configuration
static gboolean gVerbose = FALSE;
static gboolean gVersion = FALSE;

GOptionEntry options[] = {
	{"verbose", 'v', 0, G_OPTION_ARG_NONE, &gVerbose, "Output status information and property notifications", NULL},
	{"version", 'V', 0, G_OPTION_ARG_NONE, &gVersion, "Output version information and exit", NULL },
	{NULL}};

static int process_cmdline(int argc, char **argv) {
	int ret = -1;
	GOptionContext *ctx;
	GError *err = NULL;
/*	if (!g_thread_supported ())
		g_thread_init (NULL);*/
	ctx = g_option_context_new(TARGET);
	g_option_context_add_main_entries(ctx, options, NULL);
	g_option_context_add_group (ctx, gst_init_get_option_group ());
	if (!g_option_context_parse (ctx, &argc, &argv, &err)) {
		if(err) {
			g_printerr ("ERROR: Failed to initialize: %s\n", err->message);
			g_error_free (err);
		} else
			g_printerr ("ERROR: Failed to initialize\n");
		goto cleanup;
	} // if
	ret = 0;
cleanup:
	g_option_context_free (ctx);
	return ret;
}

static GstBusSyncReply bus_sync_handler (GstBus * bus, GstMessage * message, gpointer data) {
	GstElement *pipeline = (GstElement *) data;
	switch (GST_MESSAGE_TYPE (message)) {
		case GST_MESSAGE_STATE_CHANGED:
			if (GST_MESSAGE_SRC (message) == GST_OBJECT_CAST (pipeline)) {
				GstState old, state, pending;
				gst_message_parse_state_changed (message, &old, &state, &pending);
				if((GST_STATE_VOID_PENDING == pending) || (GST_STATE_READY == state)) gState = state;
				g_print ("STATE_CHANGE: %s->%s(%s)\n", gst_element_state_get_name (old), gst_element_state_get_name (state), gst_element_state_get_name (pending));
			} // if
#if 0
      /* we only care about pipeline state change messages */
      if (GST_MESSAGE_SRC (message) == GST_OBJECT_CAST (pipeline)) {
        GstState old, new, pending;
        gchar *state_transition_name;
        gst_message_parse_state_changed (message, &old, &new, &pending);
        state_transition_name = g_strdup_printf ("%s_%s", gst_element_state_get_name (old), gst_element_state_get_name (new));
        /* dump graph for (some) pipeline state changes */
        {
          gchar *dump_name = g_strconcat ("gst-launch.", state_transition_name,
              NULL);
          GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (pipeline),
              GST_DEBUG_GRAPH_SHOW_ALL, dump_name);
          g_free (dump_name);
        }

        /* place a marker into e.g. strace logs */
        {
          gchar *access_name = g_strconcat (g_get_tmp_dir (), G_DIR_SEPARATOR_S,
              "gst-launch", G_DIR_SEPARATOR_S, state_transition_name, NULL);
          g_file_test (access_name, G_FILE_TEST_EXISTS);
          g_free (access_name);
        }

        g_free (state_transition_name);
      }
#endif
			break;
		default:
			break;
	} // switch
	return GST_BUS_PASS;
} // bus_sync_handler

/* Kids, use the functions from libgstpbutils in gst-plugins-base in your
 * own code (we can't do that here because it would introduce a circular
 * dependency) */
static gboolean
gst_is_missing_plugin_message (GstMessage * msg) {
  if (GST_MESSAGE_TYPE (msg) != GST_MESSAGE_ELEMENT
      || gst_message_get_structure (msg) == NULL)
    return FALSE;

  return gst_structure_has_name (gst_message_get_structure (msg),
      "missing-plugin");
}

static const gchar *
gst_missing_plugin_message_get_description (GstMessage * msg)
{
  return gst_structure_get_string (gst_message_get_structure (msg), "name");
}
/*************************************************************************/

static struct termios gSavedTm;
static void InitKey() {
	tcgetattr(STDIN_FILENO, &gSavedTm);
	struct termios tm;
	if (tcgetattr(STDIN_FILENO, &tm) == 0) {
		tm.c_iflag = 0;
		tm.c_lflag &= ~(ICANON | ECHO);
		tm.c_cc[VMIN] = 0;
		tm.c_cc[VTIME] = 0;
		tcsetattr(STDIN_FILENO, TCSANOW, &tm);
	} // if
} // InitKey

static void DeInitKey() {
	tcsetattr(STDIN_FILENO, TCSANOW, &gSavedTm);
} // DeInitKey

static gboolean ReadKey(guchar *key) {
	return (1==read(STDIN_FILENO, key, 1));
} // ReadKey

static gboolean GetKey(guint64 *key) {
	*key = 0L;
	guchar key1;
	if (!ReadKey(&key1)) return FALSE;
	*key = key1;
	if (key1 == 0x1B) {
		// Start of escape sequence
		if (ReadKey(&key1)) {
			*key <<= 8;
			*key |= key1 & 0xFF;
			switch (key1) {
				case 0x4F: // 3-byte sequence
					if (ReadKey(&key1)) {
						*key <<= 8;
						*key |= key1 & 0xFF;
					} // if
					break;
				case 0x5B: // 3- or more-byte sequence
					if (ReadKey(&key1)) {
						*key <<= 8;
						*key |= key1 & 0xFF;
						switch (key1) {
							case 0x31 ... 0x3F: // more-byte sequence
							case 0x5B: // strange, may apparently occur
								do {
									if (!ReadKey(&key1))
										break; // Sequence ends here
									*key <<= 8;
									*key |= key1 & 0xFF;
								} while (key1 != 0x7E);
								break;
							default: ;
						} // switch
					} else {
					} // if
					break;
				default: ;
			} // switch
		} // if
	} // if
	return TRUE;
} // GetKey

static gboolean SendNavCmd(GstNavigationCommand cmd, GstElement * pipeline) {
	GstElement *nav = gst_bin_get_by_interface(GST_BIN(pipeline), GST_TYPE_NAVIGATION);
	if(!nav || !GST_IS_NAVIGATION(nav)) return FALSE;
	gst_navigation_send_command(GST_NAVIGATION(nav), cmd);
	g_object_unref(nav);
	return TRUE;
} // SendNavCmd


/* JumpChapterInDVD() skips current DVD chapter and jump to next or previous chapter.
 * This is a work around (?) as GST_NAVIGATION_COMMAND_UP does not jump chapters.
 */
static gboolean JumpChapterInDVD(GstElement *pipeline, gboolean up)
{
	GstFormat fmt = gst_format_get_by_nick("chapter");
	gint64 pos = 0;
	gint64 cnt = 0;

	// query position & duration (only for debugging)
	if (!gst_element_query_position(pipeline, &fmt, &pos))
	{
		g_print("\nquery position failed\n");
		return FALSE;
	}
	if (!gst_element_query_duration(pipeline, &fmt, &cnt)) // fails in DVD menu
	{
		g_print("\n pos:%lld query duration failed\n", pos);
		return FALSE;
	}

	g_print("chapter: %lld/%lld\n", pos, cnt);

	pos = up ? pos+1: pos-1;

	gboolean result = gst_element_seek(
				pipeline,
				1.0,
				fmt,
				GST_SEEK_FLAG_FLUSH,
				GST_SEEK_TYPE_SET,
				pos,
				GST_SEEK_TYPE_NONE,
				GST_CLOCK_TIME_NONE);
	g_print("seek result %d\n", result);
	return result;
}


/*
* Use fake text-sink when playing non-DVD uri.
* Use default text-sink when playing DVD,
*     else in DVD menu select-marker overlays are not shown.
*/
static void SetUnsetTextSink(GstElement* pipeline)
{
	gchar* uri=NULL;
	if (!pipeline || !GST_IS_PIPELINE(pipeline)) return;

	// get uri from pipeline/playbin2
	g_object_get(pipeline, "uri", &uri, NULL);

	if (uri) {
		if(strstr(uri,"dvd://")) {
			// playing a DVD, let the test-sink be the default
			GstElement* textsink=NULL;
			g_object_get(pipeline, "text-sink", &textsink, NULL);
			if (textsink) {
				gst_element_set_state(textsink, GST_STATE_NULL);
				gst_object_unref(textsink);
			}
			g_object_set(pipeline, "text-sink", NULL, NULL);  // let subtitle/overlays be shown
			g_print ("Playing DVD. Using default text-sink.\n");
		} // uri is DVD
		else {
			// uri is not DVD,disable subtitles
			// problem with pgs subtitle stream in some .MTS files
			GstElement *fakesink = gst_element_factory_make("fakesink", "fakesink");
			g_object_set(pipeline, "text-sink", fakesink, NULL);
			g_print ("Not playing DVD. Using fakesink as text-sink to avoid pgs problem.\n");
	    }
	} // uri
}

static gboolean ProcessKey(guint64 key, GstElement * pipeline) {
	GstState state, pending;
	GstFormat fmt = GST_FORMAT_TIME;
	static char buf[1024]="";
	gint64 pos = 0;
	if(buf[0]) {
		if(0x1b == key) { // Esc
			buf[0]=0;
		} else if (0x0d == key) { // Enter
			printf("ProcessCommand '%s'\n", buf);
			switch(buf[0]) {
				case 's': { // Speed
					gdouble new_speed = atof(&buf[1]);
					if(0.0 != new_speed)
						if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
							if(gst_element_seek(pipeline, new_speed, fmt, GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_SKIP, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
								gSpeed = new_speed;
					break;
				} // 's'
				case 'j': {// Jump
					gint64 pos = 0;
					switch(buf[1]) {
						case 't': // Jump to
							pos = atoll(&buf[2]);
							if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
								gSpeed = 1.0;
							break;
						case 'r': // Jump relative
							if(gst_element_query_position(pipeline, &fmt, &pos) && pos) {
								pos += atoll(&buf[2]);
								if(pos < 0) pos = 0;
								if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
									gSpeed = 1.0;
							} // if
							break;
						default: g_printerr("Unknown jump command \"%s\"", buf);
					} // switch
					break;
				} // 'j'
				case 'u': // Uri
					gError = FALSE;
					gPos = gDur = 0;
//					gst_element_set_state (gPipeline, GST_STATE_PAUSED);
					gst_element_set_state (pipeline, GST_STATE_READY);
					g_object_set(pipeline, "uri", &buf[1], NULL);
					SetUnsetTextSink(pipeline);
					gst_element_set_state (pipeline, GST_STATE_PLAYING);
					break;
				case 'a': // Audio track
					g_object_set(pipeline, "current-audio", atof(&buf[1]), NULL);
					break;
				case 'v': // Video track
					g_object_set(pipeline, "current-video", atof(&buf[1]), NULL);
					break;
				case 't': // Text track
					g_object_set(pipeline, "current-text", atof(&buf[1]), NULL);
					break;
				default: g_printerr("Unknown command \"%s\"", buf);
			} // switch
			buf[0]=0;
		} else {
			int i=0;
			while(i<sizeof(buf) && buf[i]) i++;
			if(i<sizeof(buf)) {
				buf[i++] = (char)(key&0xFF);
				buf[i]=0;
			} else
				buf[0]=0;
		} // if
		return TRUE;
	} // if
	switch(key) {
		case 0x1b : // Esc
			break;
		case ' ': // toggle pause
			gst_element_get_state(pipeline, &state, &pending, GST_CLOCK_TIME_NONE);
			gst_element_set_state(pipeline, (GST_STATE_PAUSED==state) ? GST_STATE_PLAYING : GST_STATE_PAUSED);
			break;
		case 'p': // start playback
			if(1.0 != gSpeed)
				if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
					if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
						gSpeed = 1.0;
			gst_element_get_state(pipeline, &state, &pending, GST_CLOCK_TIME_NONE);
			if(GST_STATE_PLAYING!=state)
				gst_element_set_state(pipeline, GST_STATE_PLAYING);
			break;
		case 0x7f: // Back
			gst_element_set_state(pipeline, GST_STATE_NULL);
			break;
		case 'n':
		case 'u':
		case 'a':
		case 'v':
		case 't':
		case 'j':
		case 's':
			buf[0]=(char)(key&0xFF);
			buf[1]=0;
			break;
		case 'r': {
			gdouble new_speed = gSpeed;
			if(new_speed>1.0)
				new_speed/=2;
			else if (new_speed<-1.0)
				new_speed*=2;
			else
				new_speed=-2.0;
			if(new_speed<-8.0) new_speed=-8.0;
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, new_speed, fmt, GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_SKIP, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = new_speed;
			break;
		} // 'r'
		case 'f': {
			gdouble new_speed = gSpeed;
			if(new_speed>1.0)
				new_speed*=2;
			else if (new_speed<-1.0)
				new_speed/=2;
			else
				new_speed=2.0;
			if(new_speed>8.0) new_speed=8.0;
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, new_speed, fmt, GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_SKIP, GST_SEEK_TYPE_SET, pos, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = new_speed;
			break;
		} // 'f'
		case 0x1b5b32307ell: // F9
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos-60*GST_SECOND, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = 1.0;
			break;
		case 0x1b5b32317ell: // F10
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos-5*GST_SECOND, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = 1.0;
			break;
		case 0x1b5b32337ell: // F11
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos+5*GST_SECOND, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = 1.0;
			break;
		case 0x1b5b32347ell: // F12
			if(gst_element_query_position(pipeline, &fmt, &pos) && pos)
				if(gst_element_seek(pipeline, 1.0, fmt, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, pos+60*GST_SECOND, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
					gSpeed = 1.0;
			break;
		case 0xd: // Enter
			SendNavCmd(GST_NAVIGATION_COMMAND_ACTIVATE, pipeline);
			break;
		case 'c':
			g_print("Cursor Up: jump chapter\n");
			JumpChapterInDVD(pipeline, TRUE);
			break;
		case 'C':
			g_print("Cursor down: jump chapter\n");
			JumpChapterInDVD(pipeline, FALSE);
			break;
		case 0x1b5b41: // Cursor up
			SendNavCmd(GST_NAVIGATION_COMMAND_UP, pipeline);
			break;
		case 0x1b5b42: // Cursor down
			SendNavCmd(GST_NAVIGATION_COMMAND_DOWN, pipeline);
			break;
		case 0x1b5b43: // Cursor right
			SendNavCmd(GST_NAVIGATION_COMMAND_RIGHT, pipeline);
			break;
		case 0x1b5b44: // Cursor left
			SendNavCmd(GST_NAVIGATION_COMMAND_LEFT, pipeline);
			break;
		case '1':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_MENU, pipeline);
			break;
		case '2':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_TITLE_MENU, pipeline);
			break;
		case '3':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_ROOT_MENU, pipeline);
			break;
		case '4':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_SUBPICTURE_MENU, pipeline);
			break;
		case '5':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_AUDIO_MENU, pipeline);
			break;
		case '6':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_ANGLE_MENU, pipeline);
			break;
		case '7':
			SendNavCmd(GST_NAVIGATION_COMMAND_DVD_CHAPTER_MENU, pipeline);
			break;
		case '8':
			SendNavCmd(GST_NAVIGATION_COMMAND_PREV_ANGLE, pipeline);
			break;
		case '9':
			SendNavCmd(GST_NAVIGATION_COMMAND_NEXT_ANGLE, pipeline);
			break;
		default:
			printf("Ingored key 0x%llx '%c'         \n", key, (int)(key&0xFF));
			return FALSE;
	} // switch
	return TRUE;
} // ProcessKey

#ifdef DEBUG_TAGS
static void print_tag (const GstTagList * list, const gchar * tag, gpointer unused) {
	gint i, count;
	count = gst_tag_list_get_tag_size (list, tag);
	for (i = 0; i < count; i++) {
		gchar *str;
		if (gst_tag_get_type (tag) == G_TYPE_STRING) {
			if (!gst_tag_list_get_string_index (list, tag, i, &str))
				g_assert_not_reached ();
		} else if (gst_tag_get_type (tag) == GST_TYPE_BUFFER) {
			GstBuffer *img;
			img = gst_value_get_buffer (gst_tag_list_get_value_index (list, tag, i));
			if (img) {
				gchar *caps_str;
				caps_str = GST_BUFFER_CAPS (img) ? gst_caps_to_string (GST_BUFFER_CAPS (img)) : g_strdup ("unknown");
				str = g_strdup_printf ("buffer of %u bytes, type: %s",
				GST_BUFFER_SIZE (img), caps_str);
				g_free (caps_str);
			} else {
				str = g_strdup ("NULL buffer");
			}
		} else {
			str = g_strdup_value_contents (gst_tag_list_get_value_index (list, tag, i));
		}
		if (i == 0) {
			g_print (">>>>>>>>>>%16s: %s\n", gst_tag_get_nick (tag), str);
		} else {
			g_print (">>>>>>>>>>%16s: %s\n", "", str);
		}
		g_free (str);
	}
}
#endif

#define ESCAPEINFO(x) { for(p=x;  *p; p++) if((':' == *p) || (',' == *p) || ('/' == *p)) *p = ' '; }

#define GETSTREAMINFO(x) {                                                                          \
	gint cur = 0;                                                                               \
	gint num = 0;                                                                               \
	gint i;                                                                                     \
	g_object_get (pipeline, "current-"#x, &cur, NULL);                                          \
	g_object_get (pipeline, "n-"#x, &num, NULL);                                                \
	g_string_append_printf(ret, ":%d/%d", cur, num);                                            \
	for(i = 0; i < num; i++) {                                                                  \
		GstTagList *tags = NULL;                                                            \
		g_signal_emit_by_name (pipeline, "get-"#x"-tags", i, &tags);                        \
		if(tags) {                                                                          \
			gchar *p;                                                                   \
			gchar *lang="";                                                             \
			gchar *codec="";                                                            \
			gst_tag_list_get_string(tags, GST_TAG_LANGUAGE_CODE, &lang);                \
			if(!gst_tag_list_get_string(tags, GST_TAG_CODEC, &codec))                   \
				if(!gst_tag_list_get_string(tags, GST_TAG_AUDIO_CODEC, &codec))     \
					gst_tag_list_get_string(tags, GST_TAG_VIDEO_CODEC, &codec); \
			ESCAPEINFO(lang);                                                           \
			ESCAPEINFO(codec);                                                          \
			g_string_append_printf(ret, ",%s/%s", lang, codec);                         \
			if(!title && gst_tag_list_get_string(tags, GST_TAG_TITLE, &p)) {            \
				title = g_string_new(p);                                            \
				ESCAPEINFO(title->str);                                             \
			}                                                                           \
			if(!album && gst_tag_list_get_string(tags, GST_TAG_ALBUM, &p)) {            \
				album = g_string_new(p);                                            \
				ESCAPEINFO(album->str);                                             \
			}                                                                           \
			if(!artist && gst_tag_list_get_string(tags, GST_TAG_ARTIST, &p)) {          \
				artist = g_string_new(p);                                           \
				ESCAPEINFO(artist->str);                                            \
			}                                                                           \
			gst_tag_list_free (tags);                                                   \
		}                                                                                   \
	}                                                                                           \
}

static gchar *GetStreamInfo(GstElement * pipeline) {
	GString *ret    = g_string_sized_new(256);
	GString *title  = NULL;
	GString *album  = NULL;
	GString *artist = NULL;
	GETSTREAMINFO(audio);
	GETSTREAMINFO(video);
	GETSTREAMINFO(text);
	gint64 cnt = 0;
	gint64 pos = 0;
	GstFormat fmt = gst_format_get_by_nick("title");
	if(GST_FORMAT_UNDEFINED != fmt) {
		gst_element_query_duration(pipeline, &fmt, &cnt);
		gst_element_query_position(pipeline, &fmt, &pos);
	} // if
	g_string_append_printf(ret, ":%lld/%lld", pos, cnt);
	cnt = 0;
	pos = 0;
	fmt = gst_format_get_by_nick("chapter");
	if(GST_FORMAT_UNDEFINED != fmt) {
		gst_element_query_duration(pipeline, &fmt, &cnt);
		gst_element_query_position(pipeline, &fmt, &pos);
	} // if
	g_string_append_printf(ret, ",%lld/%lld", pos, cnt);
	g_string_append_printf(ret, ",%s/%s/%s", title?title->str:"", album?album->str:"", artist?artist->str:"");
	if(title) g_string_free(title, TRUE);
	if(album) g_string_free(album, TRUE);
	if(artist) g_string_free(artist, TRUE);
	g_string_append_c(ret, ':');
	gchar *uri = NULL;
	g_object_get(pipeline, "uri", &uri, NULL);
	if(uri) {
		g_string_append(ret, uri);
		g_free(uri);
	} // if
	return g_string_free(ret, FALSE);
} // GetStreamInfo

static gboolean stream_info (GstElement *pipeline) {
	GstFormat fmt = GST_FORMAT_TIME;
	if(gBuffering) {
		gDur = -1;
	} else if (gError) {
		gPos = -1;
	} else if(GST_STATE_READY==gState) {
		gPos = gDur = 0;
	} else {
		gst_element_query_position(pipeline, &fmt, &gPos);
		gst_element_query_duration(pipeline, &fmt, &gDur);
		if(gEOS && gPos <= gDur) gPos = gDur+1;
		if(!gEOS && (gPos > gDur)) gPos = gDur - 1; // EOS is not reached, so don't allow pos > dur
	} // if
	setlocale(LC_NUMERIC, "C");
	gchar *info = GetStreamInfo(pipeline);

	// remove line feeds
	g_strdelimit(info, "\n", ' ');

	printf("%s:%lld/%lld:%lld:%lf%s\r", gst_element_state_get_name (gState), gPos, gDur, GST_SECOND, gSpeed, info); fflush(stdout);
	g_free(info);
	return TRUE;
} // stream_info

static EventLoopResult event_loop (GstElement * pipeline, gboolean blocking, GstState target_state) {
	GstMessage *message = NULL;
	EventLoopResult res = ELR_NO_ERROR;
	
	GstBus *bus = gst_element_get_bus (GST_ELEMENT (pipeline));
	gulong timeout_id = g_timeout_add (500, (GSourceFunc) stream_info, pipeline);
	while (TRUE) {
		guint64 key;
		if(blocking && GetKey(&key))
			while(ProcessKey(key, pipeline) && GetKey(&key))
				;
		message = gst_bus_poll (bus, GST_MESSAGE_ANY, 0);
		if (message == NULL) {
			if(!blocking) goto cleanup;
			usleep(50000);
			continue;
		}
		/* check if we need to dump messages to the console */
		if (FALSE) {
			guint32 seqnum = gst_message_get_seqnum (message);
			const GstStructure *s = gst_message_get_structure (message);
			GstObject *src_obj = GST_MESSAGE_SRC (message);
			if (GST_IS_ELEMENT (src_obj)) {
				g_print ("Got message #%u from element \"%s\" (%s): ", (guint) seqnum, GST_ELEMENT_NAME (src_obj), GST_MESSAGE_TYPE_NAME (message));
			} else if (GST_IS_PAD (src_obj)) {
				g_print ("Got message #%u from pad \"%s:%s\" (%s): ", (guint) seqnum, GST_DEBUG_PAD_NAME (src_obj), GST_MESSAGE_TYPE_NAME (message));
			} else if (GST_IS_OBJECT (src_obj)) {
				g_print ("Got message #%u from object \"%s\" (%s): ", (guint) seqnum, GST_OBJECT_NAME (src_obj), GST_MESSAGE_TYPE_NAME (message));
			} else {
				g_print ("Got message #%u (%s): ", (guint) seqnum, GST_MESSAGE_TYPE_NAME (message));
			} // if
			if (s) {
				gchar *sstr = gst_structure_to_string (s);
				g_print ("%s\n", sstr);
				g_free (sstr);
			} else {
				g_print ("no message details\n");
			} // if
		} // if
		switch (GST_MESSAGE_TYPE (message)) {
			case GST_MESSAGE_NEW_CLOCK: {
				GstClock *clock = NULL;
				gst_message_parse_new_clock (message, &clock);
				g_print ("New clock: %s\n", (clock ? GST_OBJECT_NAME (clock) : "NULL"));
				break;
			} // GST_MESSAGE_NEW_CLOCK
			case GST_MESSAGE_CLOCK_LOST:
				g_print ("Clock lost, selecting a new one\n");
				gst_element_set_state (pipeline, GST_STATE_PAUSED);
				gst_element_set_state (pipeline, GST_STATE_PLAYING);
				break;
			case GST_MESSAGE_EOS:{
				gWaitingEOS = FALSE;
				gEOS = TRUE;
				g_print ("Got EOS from element \"%s\".\n", GST_MESSAGE_SRC_NAME (message));
				if (!blocking) goto cleanup;
				if(gSpeed < 0)
					if(gst_element_seek(pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, 0, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE))
						gSpeed = 1.0;
				break;
			} // GST_MESSAGE_EOS
#if DEBUG_TAGS
			case GST_MESSAGE_TAG:
				if (TRUE) {
					GstTagList *tag_list;
					if (GST_IS_ELEMENT (GST_MESSAGE_SRC (message))) {
						g_print ("\nFOUND TAG      : found by element \"%s\".\n", GST_MESSAGE_SRC_NAME (message));
					} else if (GST_IS_PAD (GST_MESSAGE_SRC (message))) {
						g_print ("\nFOUND TAG      : found by pad \"%s:%s\".\n", GST_DEBUG_PAD_NAME (GST_MESSAGE_SRC (message)));
					} else if (GST_IS_OBJECT (GST_MESSAGE_SRC (message))) {
						g_print ("\nFOUND TAG      : found by object \"%s\".\n", GST_MESSAGE_SRC_NAME (message));
					} else {
						g_print ("\nFOUND TAG\n");
					} // if
					gst_message_parse_tag (message, &tag_list);
					gst_tag_list_foreach (tag_list, print_tag, NULL);
					gst_tag_list_free (tag_list);
				} // if
				break;
#endif
#if 0
			case GST_MESSAGE_TOC:
				if (TRUE) {
					GstToc *toc_msg;
					gboolean updated;
					if (GST_IS_ELEMENT (GST_MESSAGE_SRC (message))) {
						g_print ("FOUND TOC      : found by element \"%s\".\n", GST_MESSAGE_SRC_NAME (message));
					} else if (GST_IS_OBJECT (GST_MESSAGE_SRC (message))) {
						g_print ("FOUND TOC      : found by object \"%s\".\n", GST_MESSAGE_SRC_NAME (message));
					} else {
						g_print ("FOUND TOC\n");
					} // if
					gst_message_parse_toc (message, &toc_msg, &updated);
					/* recursively loop over toc entries */
					g_list_foreach (toc_msg->entries, print_toc_entry, GUINT_TO_POINTER (0));
					gst_toc_free (toc_msg);
				} // if
				break;
#endif
			case GST_MESSAGE_INFO:{
				GError *gerror;
				gchar *debug;
				gchar *name = gst_object_get_path_string (GST_MESSAGE_SRC (message));
				gst_message_parse_info (message, &gerror, &debug);
				if (debug) g_print ("INFO:\n%s\n", debug);
				g_error_free (gerror);
				g_free (debug);
				g_free (name);
				break;
			} // GST_MESSAGE_INFO
			case GST_MESSAGE_WARNING:{
				GError *gerror;
				gchar *debug;
				gchar *name = gst_object_get_path_string (GST_MESSAGE_SRC (message));
				/* dump graph on warning */
//				GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "gst-launch.warning");
				gst_message_parse_warning (message, &gerror, &debug);
				g_print ("WARNING: from element %s: %s\n", name, gerror->message);
				if (debug) g_print ("Additional debug info:\n%s\n", debug);
				g_error_free (gerror);
				g_free (debug);
				g_free (name);
				break;
			} // GST_MESSAGE_WARNING
			case GST_MESSAGE_ERROR:{
				GError *gerror;
				gchar *debug;
				gchar *name = gst_object_get_path_string (GST_MESSAGE_SRC (message));
				/* dump graph on error */
//				GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "gst-launch.error");
				gst_message_parse_error (message, &gerror, &debug);
				g_printerr ("ERROR: from element %s: %s\n", name, gerror->message);
				if (debug) g_printerr ("Additional debug info:\n%s\n", debug);
				g_error_free (gerror);
				g_free (debug);
				g_free (name);
				res = ELR_ERROR;
				gError = TRUE;
				if (!blocking) goto cleanup;
				break;
			} // GST_MESSAGE_ERROR
			case GST_MESSAGE_STATE_CHANGED:{
				gEOS = FALSE;
				GstState old, new, pending;
				/* we only care about pipeline state change messages */
				if (GST_MESSAGE_SRC (message) != GST_OBJECT_CAST (pipeline))
					break;
				/* ignore when we are buffering since then we mess with the states ourselves. */
				if (gBuffering) {
					g_print ("Prerolled, waiting for buffering to finish...\n");
					break;
				} // if
				gst_message_parse_state_changed (message, &old, &new, &pending);
				/* if we reached the final target state, exit */
				if (target_state == GST_STATE_PAUSED && new == target_state)
					goto cleanup;
				/* else not an interesting message */
				break;
			} // GST_MESSAGE_STATE_CHANGED
			case GST_MESSAGE_BUFFERING:{
				gint percent;
				gst_message_parse_buffering (message, &percent);
				g_print ("%s %d%%  \r", "buffering...", percent);
				/* no state management needed for live pipelines */
				if (gIsLive)
					break;
				if (percent == 100) {
					/* a 100% message means buffering is done */
					gBuffering = FALSE;
					/* if the desired state is playing, go back */
					if (target_state == GST_STATE_PLAYING) {
						g_print ("Done buffering, setting pipeline to PLAYING ...\n");
						gst_element_set_state (pipeline, GST_STATE_PLAYING);
					} else
						goto cleanup;
				} else {
					/* buffering busy */
					if (gBuffering == FALSE && target_state == GST_STATE_PLAYING) {
						/* we were not buffering but PLAYING, PAUSE  the pipeline. */
						g_print ("Buffering, setting pipeline to PAUSED ...\n");
						gst_element_set_state (pipeline, GST_STATE_PAUSED);
					} // if
					gBuffering = TRUE;
				} // if
				break;
			} // GST_MESSAGE_BUFFERING
			case GST_MESSAGE_LATENCY: {
				g_print ("Redistribute latency...\n");
				gst_bin_recalculate_latency (GST_BIN (pipeline));
				break;
			} // GST_MESSAGE_LATENCY
			case GST_MESSAGE_REQUEST_STATE: {
				GstState state;
				gchar *name = gst_object_get_path_string (GST_MESSAGE_SRC (message));
				gst_message_parse_request_state (message, &state);
				g_print ("Setting state to %s as requested by %s...\n", gst_element_state_get_name (state), name);
				gst_element_set_state (pipeline, state);
				g_free (name);
				break;
			} // GST_MESSAGE_REQUEST_STATE
			case GST_MESSAGE_APPLICATION:{
				const GstStructure *s = gst_message_get_structure (message);
				if (gst_structure_has_name (s, "GstLaunchInterrupt")) {
					/* this application message is posted when we caught an interrupt and we need to stop the pipeline. */
					g_print ("Interrupt: Stopping pipeline ...\n");
					res = ELR_INTERRUPT;
					goto cleanup;
				} // if
				break;
			} // GST_MESSAGE_REQUEST_STATE
			case GST_MESSAGE_ELEMENT:{
				if (gst_is_missing_plugin_message (message)) {
					const gchar *desc = gst_missing_plugin_message_get_description (message);
					g_print ("Missing element: %s\n", desc ? desc : "(no description)");
				} // if
				break;
			} // GST_MESSAGE_ELEMENT
			default:
				/* just be quiet by default */
				break;
		} // switch
		if (message)
			gst_message_unref (message);
	} // while
	g_assert_not_reached ();
cleanup:
	if (message)
		gst_message_unref (message);
	gst_object_unref (bus);
	g_source_remove (timeout_id);
	return res;
} // event_loop

int main(int argc, char **argv) {
	int ret = EXIT_FAILURE;
	EventLoopResult caught_error = ELR_NO_ERROR;
	if(process_cmdline(argc, argv)) goto cleanup;
	InitKey();
	if(gVersion) {
		printf("Version: %s gstreamer: %s\n", VERSION, gst_version_string());
		ret = EXIT_SUCCESS;
		goto cleanup;
	} // if
	/* make a null-terminated version of argv */
	GstState state, pending;
	GError *err = NULL;
	gchar **argvn = g_new0 (char *, argc);
	memcpy (argvn, argv + 1, sizeof (char *) * (argc - 1));
	gPipeline = (GstElement *) gst_parse_launchv ((const gchar **) argvn, &err);
	g_free (argvn);
	if (!gPipeline) {
		if (err) {
			g_printerr ("ERROR: pipeline could not be constructed: %s.\n", GST_STR_NULL (err->message));
			g_error_free (err);
		} else
			g_printerr ("ERROR: pipeline could not be constructed.\n");
		goto cleanup;
	} else if (err) {
		g_printerr ("WARNING: erroneous pipeline: %s\n", GST_STR_NULL (err->message));
		g_error_free (err);
	} // if
	if (gVerbose) g_signal_connect (gPipeline, "deep-notify", G_CALLBACK (gst_object_default_deep_notify), NULL);
	/* If the top-level object is not a pipeline, place it in a pipeline. */
	if (!GST_IS_PIPELINE (gPipeline)) {
		GstElement *real_pipeline = gst_element_factory_make ("pipeline", NULL);
		if (real_pipeline == NULL) {
			g_printerr ("ERROR: the 'pipeline' element wasn't found.\n");
			goto cleanup;
		} // if
		gst_bin_add (GST_BIN (real_pipeline), gPipeline);
		gPipeline = real_pipeline;
	} // if
	GstBus *bus = gst_element_get_bus (gPipeline);
	gst_bus_set_sync_handler (bus, bus_sync_handler, (gpointer)gPipeline);
	gst_object_unref (bus);
	GstStateChangeReturn scr = gst_element_set_state (gPipeline, GST_STATE_PAUSED);
	SetUnsetTextSink(gPipeline);
	switch (scr) {
		case GST_STATE_CHANGE_FAILURE:
			g_printerr ("ERROR: Pipeline doesn't want to pause.\n");
			event_loop (gPipeline, FALSE, GST_STATE_VOID_PENDING);
			goto cleanup;
		case GST_STATE_CHANGE_NO_PREROLL:
			g_print ("Pipeline is live and does not need PREROLL ...\n");
			gIsLive = TRUE;
			break;
		case GST_STATE_CHANGE_ASYNC:
			g_print ("Pipeline is PREROLLING ...\n");
			caught_error = event_loop (gPipeline, TRUE, GST_STATE_PAUSED);
			if (caught_error) {
				g_printerr ("ERROR: pipeline doesn't want to preroll.\n");
#if 0
				goto cleanup;
#endif
			} // if
			state = GST_STATE_PAUSED;
			/* no break */
		case GST_STATE_CHANGE_SUCCESS:
			g_print ("Pipeline is PREROLLED ...\n");
			break;
	} // switch
	caught_error = event_loop (gPipeline, FALSE, GST_STATE_PLAYING);
#if 0
	if (caught_error) {
		g_printerr ("ERROR: pipeline doesn't want to preroll.\n");
	} else {
#else
	if (caught_error)
		g_printerr ("ERROR: pipeline didn't want to preroll.\n");
#endif
		GstClockTime tfthen, tfnow;
		GstClockTimeDiff diff;
		g_print ("Setting pipeline to PLAYING ...\n");
		if (gst_element_set_state (gPipeline, GST_STATE_PLAYING) == GST_STATE_CHANGE_FAILURE) {
			GstMessage *err_msg;
			g_printerr ("ERROR: pipeline doesn't want to play.\n");
			GstBus *bus = gst_element_get_bus (gPipeline);
			if ((err_msg = gst_bus_poll (bus, GST_MESSAGE_ERROR, 0))) {
//				print_error_message (err_msg);
				gst_message_unref (err_msg);
			} // if
			gst_object_unref (bus);
			goto cleanup;
		} // if
		tfthen = gst_util_get_timestamp ();
		caught_error = event_loop (gPipeline, TRUE, GST_STATE_PLAYING);
#if 0
		if (eos_on_shutdown && caught_error == ELR_INTERRUPT) {
			g_print ("EOS on shutdown enabled -- Forcing EOS on the pipeline\n");
			waiting_eos = TRUE;
			gst_element_send_event (gPipeline, gst_event_new_eos ());
			g_print ("Waiting for EOS...\n");
			caught_error = event_loop (gPipeline, TRUE, GST_STATE_PLAYING);
			if (caught_error == ELR_NO_ERROR) {
				/* we got EOS */
				g_print ("EOS received - stopping pipeline...\n");
			} else if (caught_error == ELR_ERROR) {
				g_print ("An error happened while waiting for EOS\n");
			} // if
		}
#endif
		tfnow = gst_util_get_timestamp ();
		diff = GST_CLOCK_DIFF (tfthen, tfnow);
		g_print ("Execution ended after %" G_GUINT64_FORMAT " ns.\n", diff);
#if 0
	} // if
#endif
	g_print ("Setting pipeline to PAUSED ...\n");
	gst_element_set_state (gPipeline, GST_STATE_PAUSED);
	if (caught_error == ELR_NO_ERROR) {
		gst_element_get_state (gPipeline, &state, &pending, GST_CLOCK_TIME_NONE);
	} // if
	/* iterate mainloop to process pending stuff */
	while (g_main_context_iteration (NULL, FALSE));
	g_print ("Setting pipeline to READY ...\n");
	gst_element_set_state (gPipeline, GST_STATE_READY);
	gst_element_get_state (gPipeline, &state, &pending, GST_CLOCK_TIME_NONE);
	ret = EXIT_SUCCESS;
cleanup:
	if(gPipeline) {
		g_print ("Setting pipeline to NULL ...\n");
		gst_element_set_state (gPipeline, GST_STATE_NULL);
		gst_element_get_state (gPipeline, &state, &pending, GST_CLOCK_TIME_NONE);
		g_print ("Freeing pipeline ...\n");
		gst_object_unref (gPipeline);
	} // if
	gst_deinit ();
	DeInitKey();
	return ret;
} // main
