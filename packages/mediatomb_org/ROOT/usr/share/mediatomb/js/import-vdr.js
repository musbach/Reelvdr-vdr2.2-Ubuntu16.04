// Default MediaTomb import script.
// see MediaTomb scripting documentation for more information

/*MT_F*
    
    MediaTomb - http://www.mediatomb.cc/
    
    import.js - this file is part of MediaTomb.
    
    Copyright (C) 2006-2007 Gena Batyan <bgeradz@mediatomb.cc>,
                            Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>,
                            Leonhard Wimmer <leo@mediatomb.cc>
    
    This file is free software; the copyright owners give unlimited permission
    to copy and/or redistribute it; with or without modifications, as long as
    this notice is preserved.
    
    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    
    $Id: import.js 1483 2007-09-12 19:52:02Z jin_eld $
*/

function addAudio(obj)
{
 
    var desc = '';
    var artist_full;
    var album_full;
    
    // first gather data
    var title = obj.meta[M_TITLE];
    if (!title) title = obj.title;
    
    var artist = obj.meta[M_ARTIST];
    if (!artist) 
    {
        artist = 'Unknown';
        artist_full = null;
    }
    else
    {
        artist_full = artist;
        desc = artist;
    }
    
    var album = obj.meta[M_ALBUM];
    if (!album) 
    {
        album = 'Unknown';
        album_full = null;
    }
    else
    {
        desc = desc + ', ' + album;
        album_full = album;
    }
    
    if (desc)
        desc = desc + ', ';
    
    desc = desc + title;
    
    var date = obj.meta[M_DATE];
    if (!date)
    {
        date = 'Unknown';
    }
    else
    {
        date = getYear(date);
        desc = desc + ', ' + date;
    }
    
    var genre = obj.meta[M_GENRE];
    if (!genre)
    {
        genre = 'Unknown';
    }
    else
    {
        desc = desc + ', ' + genre;
    }
    
    var description = obj.meta[M_DESCRIPTION];
    if (!description) 
    {
        obj.meta[M_DESCRIPTION] = desc;
    }

// uncomment this if you want to have track numbers in front of the title
// in album view
    
/*    
    var track = obj.meta[M_TRACKNUMBER];
    if (!track)
        track = '';
    else
    {
        if (track.length == 1)
        {
            track = '0' + track;
        }
        track = track + ' ';
    }
*/
    // comment the following line out if you uncomment the stuff above  :)
    var track = '';

    var UPNP_CLASS_CONTAINER_MUSIC = UPNP_CLASS_ITEM_MUSIC_TRACK;

    var chain = new Array('Audio', 'All audio');
    obj.title = title;
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC);
    
    chain = new Array('Audio', 'Artists', artist, 'All songs');
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC);
    
    chain = new Array('Audio', 'All - full name');
    var temp = '';
    if (artist_full)
        temp = artist_full;
    
    if (album_full)
        temp = temp + ' - ' + album_full + ' - ';
    else
        temp = temp + ' - ';
    
    obj.title = temp + title;
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC);
    
    chain = new Array('Audio', 'Artists', artist, 'All - full name');
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC);
    
    chain = new Array('Audio', 'Artists', artist, album);
    obj.title = track + title;
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC_ALBUM);
    
    chain = new Array('Audio', 'Albums', album);
    obj.title = track + title; 
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC_ALBUM);
    
    chain = new Array('Audio', 'Genres', genre);
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC_GENRE);
    
    chain = new Array('Audio', 'Year', date);
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER_MUSIC);
}

// currently no video metadata supported
function addVideo(obj)
{
    var chain = new Array('Other Videos');
    addCdsObject(obj, createContainerChain(chain));
}

function addImage(obj)
{
    var chain = new Array('Photos', 'All Photos');
    addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER);

    var date = obj.meta[M_DATE];
    if (date)
    {
        chain = new Array('Photos', 'Date', date);
        addCdsObject(obj, createContainerChain(chain), UPNP_CLASS_CONTAINER);
    }
}


/* **********************************************************
 *  Added to parse VDR recordings to a more pleasant listing
 * **********************************************************/
function addVdrVideo(obj)
{
         
        var fullpath = obj.location;
        var _fileName = fullpath.substring(fullpath.lastIndexOf('/') + 1, fullpath.length); // file name
        var filepath = fullpath.substring(0,fullpath.lastIndexOf('/')); // full path of the file without filename and without last '/'
        var _dirs = filepath.split(/\//g); // list of directories
        
        if (_fileName.match(/^\d{3}\.vdr/) || _fileName.match(/^\d{5}\.ts/)) // match any file name of the form xxx.vdr OR xxxxx.ts where x=[0-9]
        {

            
            // loop to remove null strings and parse directory names such as BBC_World -> "BBC World" or 2007-11-12.12:23.50.99.rec etc
            
            var newChain = new Array();  
            var byDate   = new Array();

            newChain[0] = 'ReelBox'; newChain[1] = 'By Channels';
            byDate [0]  = 'ReelBox'; byDate[1]   = 'By Date';
            
            var j = 2; // newChain counter
            var k = 2; // byDate counter

            var pwDir;
            if(_dirs.length > 0)
		    pwDir = _dirs[_dirs.length-1]; // get dir in which this file resides
	    //print( "rec dir: " + pwDir);
	    if( /\.rec$/.test(pwDir) ) // do we have a vdr recording
	    {
		    var dateStr = pwDir.substring(0, 10);
		    var timeStr = pwDir.substring(11, 16).replace(/\./g, ':');


		    byDate[k] = dateStr ;
		    k++;
		    byDate[k] = timeStr;
		    k++;

		    for (var i=0; i< _dirs.length; i++)
		    {
			    if (_dirs[i] == "" || _dirs[i] == 'media' || _dirs[i] == 'hd'|| _dirs[i] == 'recordings')
				    ;  // Do nothing, Skip these
			    else 
				    if( /\.rec$/.test(_dirs[i])) // 2007-11-29.16.13.50.99.rec// rename directories like these
				    {
				    	    newChain[j] = dateStr + ' ' + timeStr;
					    break; // already added date and time for byDate container
				    }
				    else
				    {
					    byDate[k] = _dirs[i].replace(/_/g, ' ');
					    newChain[j] = byDate[k];
					    j++;
					    k++;
				    }
		    }

            obj.mimetype = 'video/mpeg';
            var ccChain = createContainerChain(byDate);
            print ('ccChain = '+ ccChain + ' /' + obj.title);
            addCdsObject(obj, ccChain, UPNP_CLASS_CONTAINER);

            ccChain = createContainerChain(newChain);
            addCdsObject(obj, ccChain, UPNP_CLASS_CONTAINER);

	    } // if pwDir ends in '.rec'

            /*
            for (var i=0; i< _dirs.length; i++)
            {
                if (_dirs[i] == "" || _dirs[i] == 'media' || _dirs[i] == 'hd'|| _dirs[i] == 'recordings')
                    ;  // Do nothing, Skip these
                else 
                    if( /\.rec$/.test(_dirs[i])) // 2007-11-29.16.13.50.99.rec// rename directories like these
                    { 
                        //var dateStr =  _dirs[i].substring( 0,_dirs[i].search(/\.\d\d\.rec$/) );
                        // directory name is always YYYY-MM-DD.HH.mm.ss.xx.rec and x=0-9
                        var dateStr = _dirs[i].substring(0, 10); 
                        var timeStr = _dirs[i].substring(11,19).replace(/\./g,':');

                        // 2011-01-31.18.08.92-0.rec
                        //  YYYY-MM-DD-hh.mm.ch-ri.rec (ch=channel, ri=resumeId) // from vdr 1.7.3
                        if ( _fileName.match(/^\d{5}\.ts/) )
                        {
				timeStr = _dirs[i].substring(11,16).replace(/\./g,':');
                        }
                        
                        newChain[j] = dateStr + ' ' + timeStr;
                        j++;
                        
                        byDate[k] = byDate [k-1]; // earlier string was the channel name
                        byDate[k-1] = dateStr;
                        k++;
                        byDate[k] = timeStr;
                        k++; 
                    }
                    else
                    { 
                        newChain[j] = _dirs[i].replace(/_/g,' ');
                        byDate[k] = newChain[j];
                        k++;
                        //newChain[j] = _dirs[i];
                        j++;
                    }
                
                
            }*/
            //obj.mimetype = 'video/mpeg';
             
            //var ccChain = createContainerChain(newChain);
            //print ('ccChain = '+ ccChain + ' /' + obj.title);
            //addCdsObject(obj, ccChain, UPNP_CLASS_CONTAINER);
            
        } // if .vdr OR .ts
} // end addVdrVideo()


/***********************************
 *  main script part
 **********************************/


var type = getPlaylistType(orig.mimetype);

//print ('import.js/orig ' + orig.location + '       type:' + type + '       orig.mimetype:' + orig.mimetype);


if (type == '')
{
    var arr = orig.mimetype.split('/');
    var mime = arr[0];
    //print('mime:' + mime);
    
    // var obj = copyObject(orig);
    
    var obj = orig; 
    obj.refID = orig.id;
    
    if (mime == 'audio')
    {
        addAudio(obj);
    }
    
    if (orig.mimetype == 'application/octet-stream' || mime == 'video')
       // Ubuntu 10.04 file -i <path to recording>/00001.ts gives 'application/octet-stream'
    {
       // if ( arr[1] == 'vdr') 
    //var regExpVar = new RegExp('');
        //var str = obj.title;
        if (/\.vdr$/.test(obj.title) || /\.ts$/.test(obj.title))
            addVdrVideo(obj);
        else
            addVideo(obj);
    }
    
    if (mime == 'image')
    {
        addImage(obj);
    }

    if (orig.mimetype == 'application/ogg')
    {
        if (orig.theora == 1)
            addVideo(obj);
        else
            addAudio(obj);
    }
}
