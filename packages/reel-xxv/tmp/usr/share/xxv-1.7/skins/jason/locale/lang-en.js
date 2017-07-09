/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2009-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 * Template for translation
 */

/* common.js */
Ext.xxv.MessageBox.prototype.szFailure = "Failure!";
Ext.xxv.MessageBox.prototype.szSuccess = "Success!";

Ext.xxv.Panel.prototype.title = "Connect ...";
Ext.xxv.Panel.prototype.szLoading = "Loading ...";
Ext.xxv.Panel.prototype.szTitle = "Xtreme eXtension for VDR";

/* menus.js */
Ext.xxv.MainSearchField.prototype.emptyText = "Search ...";

Ext.xxv.MainMenu.prototype.szMenuXXV = "XXV";
Ext.xxv.MainMenu.prototype.szMenuProgramming = "Programming";
Ext.xxv.MainMenu.prototype.szMenuMedia = "Media";
Ext.xxv.MainMenu.prototype.szMenuRemote = "Remote access";
Ext.xxv.MainMenu.prototype.szMenuView = "View";
Ext.xxv.MainMenu.prototype.szMenuItemSetup = "Setup";
Ext.xxv.MainMenu.prototype.szGlobalSettings = "Global settings";
Ext.xxv.MainMenu.prototype.szOwnSettings = "Own settings";
Ext.xxv.MainMenu.prototype.szMenuItemLogout	 = "Logout";
Ext.xxv.MainMenu.prototype.szMenuItemLogoutTooltip = "Click this button to logout from XXV";
Ext.xxv.MainMenu.prototype.szSelectTheme = "Select theme";
Ext.xxv.MainMenu.prototype.szPreviewPreviewPane = "Preview Pane";
Ext.xxv.MainMenu.prototype.szPreviewRight = "Right";
Ext.xxv.MainMenu.prototype.szPreviewBottom = "Bottom";
Ext.xxv.MainMenu.prototype.szPreviewHide = "Hide";
Ext.xxv.MainMenu.prototype.szLogoutSuccess = "Successful logout.\r\n{0}";
Ext.xxv.MainMenu.prototype.szLogoutFailure = "Couldn't logout!\r\n{0}";

/* form.js */
Ext.xxv.Question.prototype.szClose = "Close";
Ext.xxv.Question.prototype.szApply = "Apply";
Ext.xxv.Question.prototype.szCommandDeny = "Command '{0}' not allowed!";
Ext.xxv.Question.prototype.szLoadException = "Couldn't get data!\r\n{0}";
Ext.xxv.Question.prototype.szFailure = "Couldn't save data!\r\n{0}";
Ext.xxv.Question.prototype.szSuccess = "Data saved successful.\r\n{0}";
Ext.xxv.Question.prototype.szComboEmpty = "Select ...";

/* channelspanel.js */
Ext.xxv.channelsPanel.prototype.title = "Channels";
Ext.xxv.channelsPanel.prototype.refreshText = "Refresh";
Ext.xxv.channelsPanel.prototype.selectText = "Select channel";
Ext.xxv.channelsPanel.prototype.webcastTTText = "Web cast";
Ext.xxv.channelsPanel.prototype.webcastText = "Live web cast this channel";
Ext.xxv.channelsPanel.prototype.switchTTText: "Switch";
Ext.xxv.channelsPanel.prototype.switchText = "Switch to this channel";
Ext.xxv.channelsPanel.prototype.teleTextText = "Teletext pages";
Ext.xxv.channelsPanel.prototype.teleTextTTText = "Show teletext pages from this channel";
Ext.xxv.channelsPanel.prototype.editTTText = "Edit";
Ext.xxv.channelsPanel.prototype.editText = "Edit this channel";
Ext.xxv.channelsPanel.prototype.deleteText = "Delete this channel";
Ext.xxv.channelsPanel.prototype.szLoadException = "Couldn't get channels data!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchSuccess = "Successful switch to channel.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchFailure = "Couldn't switch to channel!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteSuccess = "Channel successful deleted.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteFailure = "Couldn't delete channel!\r\n{0}";

/* autotimers.js */
Ext.xxv.autotimerGrid.prototype.szTitle = "Search timer";
Ext.xxv.autotimerGrid.prototype.szFindReRun = "Find rerun";
Ext.xxv.autotimerGrid.prototype.szNew = "Create new search timer";
Ext.xxv.autotimerGrid.prototype.szEdit = "Edit search timer";
Ext.xxv.autotimerGrid.prototype.szDelete = "Delete search timer";
Ext.xxv.autotimerGrid.prototype.szColSearch = "Search text";
Ext.xxv.autotimerGrid.prototype.szColActive = "Active";
Ext.xxv.autotimerGrid.prototype.szColChannels = "Channels";
Ext.xxv.autotimerGrid.prototype.szColDirectory = "Directory";
Ext.xxv.autotimerGrid.prototype.szColStart = "Start";
Ext.xxv.autotimerGrid.prototype.szColStop = "Stop";
Ext.xxv.autotimerGrid.prototype.szColMinLength = "Min. Length";
Ext.xxv.autotimerGrid.prototype.szLoadException = "Couldn't get data about autotimer!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteSuccess = "Autotimer deleted successful.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteFailure = "Couldn't delete autotimer!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgrade = "Lookup for wanted events";
Ext.xxv.autotimerGrid.prototype.szUpgradeWait = "Please wait...";
Ext.xxv.autotimerGrid.prototype.szUpgradeSuccess = "Lookup for wanted events successful.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgradeFailure = "Couldn't lookup for wanted events!\r\n{0}";

/* chronicle.js */
Ext.xxv.ChronicleGrid.prototype.szTitle = "Chronicle";
Ext.xxv.ChronicleGrid.prototype.szToolTip = "Display recordings in chronological order";
Ext.xxv.ChronicleGrid.prototype.szColTitle = "Title";
Ext.xxv.ChronicleGrid.prototype.szColDay = "Day";
Ext.xxv.ChronicleGrid.prototype.szColChannel = "Channel";
Ext.xxv.ChronicleGrid.prototype.szColStart = "Start";
Ext.xxv.ChronicleGrid.prototype.szColStop = "Stop";
Ext.xxv.ChronicleGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.ChronicleGrid.prototype.szLoadException = "Couldn't get data from chronicle!\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteSuccess = "Data from chronicle deleted successful.\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteFailure = "Couldn't delete data from chronicle!\r\n{0}";

/* now.js */
Ext.xxv.NowGrid.prototype.szTitle = "Program guide";
Ext.xxv.NowGrid.prototype.szPresent = "Present";
Ext.xxv.NowGrid.prototype.szFollowing = "Following";
Ext.xxv.NowGrid.prototype.szFindReRun = "Find rerun";
Ext.xxv.NowGrid.prototype.szProgram = "Show program";
Ext.xxv.NowGrid.prototype.szRecord = "Record";
Ext.xxv.NowGrid.prototype.szEditTimer = "Edit timer";
Ext.xxv.NowGrid.prototype.szToggleTimer = "Enable or disable timer";
Ext.xxv.NowGrid.prototype.szDeleteTimer = "Delete timer";
Ext.xxv.NowGrid.prototype.szColPosition = "Channel position";
Ext.xxv.NowGrid.prototype.szColTitle = "Title";
Ext.xxv.NowGrid.prototype.szColChannel = "Channel";
Ext.xxv.NowGrid.prototype.szColGrpName = "Group of channel";
Ext.xxv.NowGrid.prototype.szColStart = "Start";
Ext.xxv.NowGrid.prototype.szColStop = "Stop";
Ext.xxv.NowGrid.prototype.szLoadException = "Couldn't get data!\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordSuccess = "Timer created successful.\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordFailure = "Couldn't create timer!\r\n{0}";
Ext.xxv.NowGrid.prototype.szToggleFailure = "Couldn't modify timer!\r\n{0}";
Ext.xxv.NowGrid.prototype.szDeleteSuccess = "Timer deleted successful.\r\n{0}";
Ext.xxv.NowGrid.prototype.szDeleteFailure = "Couldn't delete timer!\r\n{0}";
Ext.xxv.NowGrid.prototype.szDetailsFailure = "Couldn't update details of event!\r\n{0}";

/* program.js */
Ext.xxv.programGrid.prototype.szTitle = "Program guide";
Ext.xxv.programGrid.prototype.szFindReRun = "Find rerun";
Ext.xxv.programGrid.prototype.szRecord = "Record";
Ext.xxv.programGrid.prototype.szColTitle = "Title";
Ext.xxv.programGrid.prototype.szColDay = "Day";
Ext.xxv.programGrid.prototype.szColStart = "Start";
Ext.xxv.programGrid.prototype.szColStop = "Stop";
Ext.xxv.programGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.programGrid.prototype.szLoadException = "Couldn't get program data!\r\n{0}";

/* search.js */
Ext.xxv.searchGrid.prototype.szTitle = "Search";
Ext.xxv.searchGrid.prototype.szFindReRun = "Find rerun";
Ext.xxv.searchGrid.prototype.szRecord = "Record";
Ext.xxv.searchGrid.prototype.szColTitle = "Title";
Ext.xxv.searchGrid.prototype.szColChannel = "Channel";
Ext.xxv.searchGrid.prototype.szColDay = "Day";
Ext.xxv.searchGrid.prototype.szColStart = "Start";
Ext.xxv.searchGrid.prototype.szColStop = "Stop";
Ext.xxv.searchGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.searchGrid.prototype.szLoadException = "Couldn't find data!\r\n{0}";

/* recordings.js */
Ext.xxv.recordingsDataView.prototype.szTitle = "Recordings";
Ext.xxv.recordingsDataView.prototype.szToolTip = "Display recordings";
Ext.xxv.recordingsDataView.prototype.szFindReRun = "Find rerun";
Ext.xxv.recordingsDataView.prototype.szEdit = "Edit";
Ext.xxv.recordingsDataView.prototype.szCut = "Cut";
Ext.xxv.recordingsDataView.prototype.szConvert = "Convert";
Ext.xxv.recordingsDataView.prototype.szDelete = "Delete";
Ext.xxv.recordingsDataView.prototype.szRecover = "Recover deleted recordings";
Ext.xxv.recordingsDataView.prototype.szStream = "Stream recording";
Ext.xxv.recordingsDataView.prototype.szPlay = "Playback";
Ext.xxv.recordingsDataView.prototype.szLoadException = "Couldn't get data about recording!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutSuccess = "Recordings started cutting process successful.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutFailure = "Couldn't start cutting process recordings!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteSuccess = "Recordings deleted successful.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteFailure = "Couldn't delete recordings!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackSuccess = "Recording started playback successful.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackFailure = "Couldn't started playback recording!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgrade = "Update list of recordings";
Ext.xxv.recordingsDataView.prototype.szUpgradeWait = "Please wait...";
Ext.xxv.recordingsDataView.prototype.szUpgradeSuccess = "List of recordings update successful.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgradeFailure = "Couldn't update list of recordings!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDetailsFailure = "Couldn't update details of recording!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szRecordingTip = "{0} {1} - {2} ({3})<br />{4}";
Ext.xxv.recordingsDataView.prototype.szFolderTip0 = "There are {0} recordings<br />Total time {1}";
Ext.xxv.recordingsDataView.prototype.szFolderTip1 = "There are {0} recordings<br />Have a new recording<br />Total time {2}";
Ext.xxv.recordingsDataView.prototype.szFolderTip2 = "There are {0} recordings<br />Have {1} new recordings<br />Total time {2}";

/* timers.js */
Ext.xxv.timerGrid.prototype.szTitle = "Timer";
Ext.xxv.timerGrid.prototype.szFindReRun = "Find rerun";
Ext.xxv.timerGrid.prototype.szNew = "Create new timer";
Ext.xxv.timerGrid.prototype.szEdit = "Edit timer";
Ext.xxv.timerGrid.prototype.szDelete = "Delete timer";
Ext.xxv.timerGrid.prototype.szToggle = "Enable or disable";
Ext.xxv.timerGrid.prototype.szColTitle = "Title";
Ext.xxv.timerGrid.prototype.szColActive = "Active";
Ext.xxv.timerGrid.prototype.szColPDC = "PDC";
Ext.xxv.timerGrid.prototype.szColDay = "Day";
Ext.xxv.timerGrid.prototype.szColChannel = "Channel";
Ext.xxv.timerGrid.prototype.szColStart = "Start";
Ext.xxv.timerGrid.prototype.szColStop = "Stop";
Ext.xxv.timerGrid.prototype.szColDuration = "Duration";
Ext.xxv.timerGrid.prototype.szHost = "Host";
Ext.xxv.timerGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.timerGrid.prototype.szSelChEmptyText = "Select a channel...";
Ext.xxv.timerGrid.prototype.szLoadException = "Couldn't get data about timer!\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteSuccess = "Timer deleted successful.\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteFailure = "Couldn't delete timer!\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleSuccess = "Timer toggled successful.\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleFailure = "Couldn't toggle timer!\r\n{0}";

/* movetimers.js */
Ext.xxv.movetimersGrid.prototype.szTitle = "Rules to move timers";
Ext.xxv.movetimersGrid.prototype.szNew = "New";
Ext.xxv.movetimersGrid.prototype.szEdit = "Edit";
Ext.xxv.movetimersGrid.prototype.szDelete = "Delete";
Ext.xxv.movetimersGrid.prototype.szColSource = "Source";
Ext.xxv.movetimersGrid.prototype.szColDestination = "Destination";
Ext.xxv.movetimersGrid.prototype.szColMove = "Move timer";
Ext.xxv.movetimersGrid.prototype.szColOriginal = "Change original timer";
Ext.xxv.movetimersGrid.prototype.szLoadException = "Couldn't get data about rule to move timer!\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteSuccess = "Rule to move timer deleted successful.\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteFailure = "Couldn't delete rule to move timer!\r\n{0}";

/* users.js */
Ext.xxv.usersGrid.prototype.szTitle = "User accounts";
Ext.xxv.usersGrid.prototype.szNew = "Create new account";
Ext.xxv.usersGrid.prototype.szEdit = "Edit";
Ext.xxv.usersGrid.prototype.szDelete = "Delete";
Ext.xxv.usersGrid.prototype.szColTitle = "Account";
Ext.xxv.usersGrid.prototype.szColLevel = "Level";
Ext.xxv.usersGrid.prototype.szUserPreferences = "User Preferences";
Ext.xxv.usersGrid.prototype.szAdminPreferences = "Preferences";
Ext.xxv.usersGrid.prototype.szLoadException = "Couldn't get data about user accounts!\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteSuccess = "User account deleted successful.\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteFailure = "Couldn't delete user account!\r\n{0}";

/* vdr.js */
Ext.xxv.vdrGrid.prototype.szTitle = "Video disk recorder";
Ext.xxv.vdrGrid.prototype.szNew = "New";
Ext.xxv.vdrGrid.prototype.szEdit = "Edit";
Ext.xxv.vdrGrid.prototype.szDelete = "Delete";
Ext.xxv.vdrGrid.prototype.szColHost = "Host computer";
Ext.xxv.vdrGrid.prototype.szColActive = "Active";
Ext.xxv.vdrGrid.prototype.szColPrimary = "Primary";
Ext.xxv.vdrGrid.prototype.szColDirectory = "Directory";
Ext.xxv.vdrGrid.prototype.szDVBTyp = "Type of DVB-cards";
Ext.xxv.vdrGrid.prototype.szLoadException = "Couldn't get data about video disk recorder!\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteSuccess = "Video disk recorder deleted successful.\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteFailure = "Couldn't delete video disk recorder!\r\n{0}";

/* audio.js */
Ext.xxv.AudioWindow.prototype.szTitle = "Music playback";
Ext.xxv.AudioWindow.prototype.szNeedFlash = "You need to get the latest Flash Player to hear music with this player";
Ext.xxv.AudioWindow.prototype.szSaveFile = "Save file to disk";

/* music.js */
Ext.xxv.musicGrid.prototype.szTitle = "Music";
Ext.xxv.musicGrid.prototype.szToolTip = "Display list of music title";
Ext.xxv.musicGrid.prototype.szFindTitle = "Search tracks with same title";
Ext.xxv.musicGrid.prototype.szFindArtist = "Search tracks by same artist";
Ext.xxv.musicGrid.prototype.szFindAlbum = "Search tracks from same album";
Ext.xxv.musicGrid.prototype.szFindGenre = "Search tracks by same genre";
Ext.xxv.musicGrid.prototype.szFindYear = "Search tracks from same year";
Ext.xxv.musicGrid.prototype.szPlaying = "Playing";
Ext.xxv.musicGrid.prototype.szColAlbum	 = "Album";
Ext.xxv.musicGrid.prototype.szColArtist = "Artist";
Ext.xxv.musicGrid.prototype.szColTitle = "Title";
Ext.xxv.musicGrid.prototype.szColDuration = "Duration";
Ext.xxv.musicGrid.prototype.szColTrack = "Track";
Ext.xxv.musicGrid.prototype.szColYear = "Year";
Ext.xxv.musicGrid.prototype.szColGenre = "Genre";
Ext.xxv.musicGrid.prototype.szColComment = "Comment";
Ext.xxv.musicGrid.prototype.szLoadException = "Couldn't get tracks from music list!\r\n{0}";

/* teletext */
Ext.xxv.TeleTextView.prototype.szTitle = "Teletext";
Ext.xxv.TeleTextView.prototype.szToolTip = "Display teletext pages";
Ext.xxv.TeleTextView.prototype.szLoadException = "Couldn't get teletext pages!\r\n{0}";

/* monitor.js */
Ext.xxv.MonitorWindow.prototype.szTitle = "Monitor";
Ext.xxv.MonitorWindow.prototype.szAspect = "Restore aspect ratio correctly";
Ext.xxv.MonitorWindow.prototype.szUpdate = "Update monitor";
Ext.xxv.MonitorWindow.prototype.szUpdateFast = "Faster update monitor";
Ext.xxv.MonitorWindow.prototype.szUpdateSlow = "Slower update monitor";

/* stream.js */
Ext.xxv.StreamWindow.prototype.szTitle = "Streaming";
Ext.xxv.StreamWindow.prototype.szAspect = "Restore aspect ratio correctly";

/* remote.js */
Ext.xxv.RemoteWindow.prototype.szTitle = "Remote control";
Ext.xxv.RemoteWindow.prototype.szRemoteFailure = "Couldn't transmit remote control data!\r\n{0}";

/* ux/multiselect.js */
Ext.ux.Multiselect.prototype.minLengthText = "Minimum {0} item(s) required";
Ext.ux.Multiselect.prototype.maxLengthText = "Maximum {0} item(s) allowed";

/* ux/filter.js */
Ext.ux.grid.Search.prototype.searchTipText = "Type a text to search and press Enter";


