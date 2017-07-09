/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 * German translation
 */

/* common.js */
Ext.xxv.Panel.prototype.title = "Verbinde ...";
Ext.xxv.Panel.prototype.szLoading = "Lade ...";
Ext.xxv.Panel.prototype.szTitle = "Xtreme eXtension für VDR";

Ext.xxv.MessageBox.prototype.szFailure = "Fehlgeschlagen!";
Ext.xxv.MessageBox.prototype.szSuccess = "Erfolgreich!";

/* menus.js */
Ext.xxv.MainSearchField.prototype.emptyText = "Suche ...";

Ext.xxv.MainMenu.prototype.szMenuXXV = "XXV";
Ext.xxv.MainMenu.prototype.szMenuProgramming = "Programmierung";
Ext.xxv.MainMenu.prototype.szMenuMedia = "Medien";
Ext.xxv.MainMenu.prototype.szMenuRemote = "Fernzugriff";
Ext.xxv.MainMenu.prototype.szMenuView = "Anzeige";
Ext.xxv.MainMenu.prototype.szMenuItemSetup = "Einstellungen";
Ext.xxv.MainMenu.prototype.szGlobalSettings = "Globale Einstellungen";
Ext.xxv.MainMenu.prototype.szOwnSettings = "Eigene Einstellungen";
Ext.xxv.MainMenu.prototype.szMenuItemLogout = "Abmelden";
Ext.xxv.MainMenu.prototype.szMenuItemLogoutTooltip = "Wähle diesen Button um sich von XXV abzumelden";
Ext.xxv.MainMenu.prototype.szSelectTheme = "Wähle Thema";
Ext.xxv.MainMenu.prototype.szPreviewPreviewPane = "Vorschau";
Ext.xxv.MainMenu.prototype.szPreviewRight = "Rechts";
Ext.xxv.MainMenu.prototype.szPreviewBottom = "Unten";
Ext.xxv.MainMenu.prototype.szPreviewHide = "Ausgeblendet";
Ext.xxv.MainMenu.prototype.szLogoutSuccess = "Erfolgreich abgemeldet.\r\n{0}";
Ext.xxv.MainMenu.prototype.szLogoutFailure = "Abmeldung fehlgeschlagen!\r\n{0}";

/* form.js */
Ext.xxv.Question.prototype.szClose = "Schliessen";
Ext.xxv.Question.prototype.szApply = "Übernehmen";
Ext.xxv.Question.prototype.szCommandDeny = "Kommando '{0}' ist nicht erlaubt!";
Ext.xxv.Question.prototype.szLoadException = "Konnte keine Daten holen!\r\n{0}";
Ext.xxv.Question.prototype.szFailure = "Konnte Daten nicht speichern!\r\n{0}";
Ext.xxv.Question.prototype.szSuccess = "Daten erfolgreich gespeichert.\r\n{0}";
Ext.xxv.Question.prototype.szComboEmpty = "Wähle ...";

/* channelspanel.js */
Ext.xxv.channelsPanel.prototype.title = "Kanäle";
Ext.xxv.channelsPanel.prototype.refreshText = "Aktualisieren";
Ext.xxv.channelsPanel.prototype.selectText = "Wähle Kanal";
Ext.xxv.channelsPanel.prototype.webcastTTText = "Live TV";
Ext.xxv.channelsPanel.prototype.webcastText = "Diesen Kanal als Live TV streamen";
Ext.xxv.channelsPanel.prototype.switchTTText = "Umschalten";
Ext.xxv.channelsPanel.prototype.switchText = "Auf diesen Kanal umschalten";
Ext.xxv.channelsPanel.prototype.teleTextText = "Videotext";
Ext.xxv.channelsPanel.prototype.teleTextTTText = "Zeigt den Videotext dieses Kanals";
Ext.xxv.channelsPanel.prototype.editTTText = "Bearbeiten";
Ext.xxv.channelsPanel.prototype.editText = "Diesen Kanal bearbeiten";
Ext.xxv.channelsPanel.prototype.deleteText = "Diesen Kanal löschen";
Ext.xxv.channelsPanel.prototype.szLoadException = "Konnte keine Daten zu den Kanälen holen!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchSuccess = "Erfolgreich zum Kanal umgeschaltet.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchFailure = "Konnte nicht zum Kanal umgeschalten!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteSuccess = "Kanal erfolgreich gelöscht.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteFailure = "Konnte Kanal nicht löschen!\r\n{0}";

/* autotimers.js */
Ext.xxv.autotimerGrid.prototype.szTitle = "Suchtimer";
Ext.xxv.autotimerGrid.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.autotimerGrid.prototype.szNew = "Neuen Suchtimer erstellen";
Ext.xxv.autotimerGrid.prototype.szEdit = "Bearbeiten Suchtimer";
Ext.xxv.autotimerGrid.prototype.szDelete = "Löschen Suchtimer";
Ext.xxv.autotimerGrid.prototype.szColSearch = "Suchtext";
Ext.xxv.autotimerGrid.prototype.szColActive = "Aktiv";
Ext.xxv.autotimerGrid.prototype.szColChannels = "Kanäle";
Ext.xxv.autotimerGrid.prototype.szColDirectory = "Verzeichnis";
Ext.xxv.autotimerGrid.prototype.szColStart = "Beginn";
Ext.xxv.autotimerGrid.prototype.szColStop = "Ende";
Ext.xxv.autotimerGrid.prototype.szColMinLength = "Min. Länge";
Ext.xxv.autotimerGrid.prototype.szLoadException = "Konnte keine Daten über Autotimer holen!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteSuccess = "Autotimer erfolgreich gelöscht.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteFailure = "Konnte Autotimer nicht löschen!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgrade = "Suche nach gewünschten Programmeinträgen";
Ext.xxv.autotimerGrid.prototype.szUpgradeWait = "Bitte warten...";
Ext.xxv.autotimerGrid.prototype.szUpgradeSuccess = "Suche nach gewünschten Programmeinträgen erfolgreich.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgradeFailure = "Suche nach gewünschten Programmeinträgen fehlgeschlagen!\r\n{0}";

/* chronicle.js */
Ext.xxv.ChronicleGrid.prototype.szTitle = "Chronik";
Ext.xxv.ChronicleGrid.prototype.szToolTip = "Zeigt Aufnahmen in chronologischer Anordnung";
Ext.xxv.ChronicleGrid.prototype.szColTitle = "Titel";
Ext.xxv.ChronicleGrid.prototype.szColDay = "Datum";
Ext.xxv.ChronicleGrid.prototype.szColChannel = "Kanal";
Ext.xxv.ChronicleGrid.prototype.szColStart = "Beginn";
Ext.xxv.ChronicleGrid.prototype.szColStop = "Ende";
Ext.xxv.ChronicleGrid.prototype.szColDayFormat = "l, d.m.Y";
Ext.xxv.ChronicleGrid.prototype.szLoadException = "Konnte keine Daten der Chronik holen!\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteSuccess = "Eintrag der Chronik erfolgreich gelöscht.\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteFailure = "Konnte Eintrag der Chronik nicht löschen!\r\n{0}";

/* now.js */
Ext.xxv.NowGrid.prototype.szTitle = "Programmführer";
Ext.xxv.NowGrid.prototype.szPresent = "Jetzt";
Ext.xxv.NowGrid.prototype.szFollowing = "Folgend";
Ext.xxv.NowGrid.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.NowGrid.prototype.szProgram = "Zeige Programm";
Ext.xxv.NowGrid.prototype.szRecord = "Aufnehmen";
Ext.xxv.NowGrid.prototype.szEditTimer = "Timer bearbeiten";
Ext.xxv.NowGrid.prototype.szToggleTimer = "Timer de- bzw. aktivieren";
Ext.xxv.NowGrid.prototype.szDeleteTimer = "Timer löschen";
Ext.xxv.NowGrid.prototype.szColPosition = "Position des Kanal";
Ext.xxv.NowGrid.prototype.szColTitle = "Titel";
Ext.xxv.NowGrid.prototype.szColChannel = "Kanal";
Ext.xxv.NowGrid.prototype.szColGrpName = "Gruppe der Kanäle";
Ext.xxv.NowGrid.prototype.szColStart = "Beginn";
Ext.xxv.NowGrid.prototype.szColStop = "Ende";
Ext.xxv.NowGrid.prototype.szLoadException = "Konnte keine Daten holen!\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordSuccess = "Timer erfolgreich erstellt.\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordFailure = "Konnte Timer nicht erstellen!\r\n{0}";
Ext.xxv.NowGrid.prototype.szToggleFailure = "Konnte Timer nicht verändern!\r\n{0}";
Ext.xxv.NowGrid.prototype.szDeleteSuccess = "Timer erfolgreich gelöscht.\r\n{0}";
Ext.xxv.NowGrid.prototype.szDeleteFailure = "Konnte Timer nicht löschen!\r\n{0}";
Ext.xxv.NowGrid.prototype.szDetailsFailure = "Konnte Details der Sendung nicht aktualisieren!\r\n{0}";

/* program.js */
Ext.xxv.programGrid.prototype.szTitle = "Programführer";
Ext.xxv.programGrid.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.programGrid.prototype.szRecord = "Aufnehmen";
Ext.xxv.programGrid.prototype.szColTitle = "Titel";
Ext.xxv.programGrid.prototype.szColDay = "Datum";
Ext.xxv.programGrid.prototype.szColStart = "Beginn";
Ext.xxv.programGrid.prototype.szColStop = "Ende";
Ext.xxv.programGrid.prototype.szColDayFormat = "l, d.m.Y";
Ext.xxv.programGrid.prototype.szLoadException = "Konnte keine Programmdaten holen!\r\n{0}";

/* search.js */
Ext.xxv.searchGrid.prototype.szTitle = "Suche";
Ext.xxv.searchGrid.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.searchGrid.prototype.szRecord = "Aufnehmen";
Ext.xxv.searchGrid.prototype.szColTitle = "Titel";
Ext.xxv.searchGrid.prototype.szColChannel = "Kanal";
Ext.xxv.searchGrid.prototype.szColDay = "Datum";
Ext.xxv.searchGrid.prototype.szColStart = "Beginn";
Ext.xxv.searchGrid.prototype.szColStop = "Ende";
Ext.xxv.searchGrid.prototype.szColDayFormat = "l, d.m.Y";
Ext.xxv.searchGrid.prototype.szLoadException = "Konnte keine Wiederholung finden!\r\n{0}";

/* recordings.js */
Ext.xxv.recordingsDataView.prototype.szTitle = "Aufnahmen";
Ext.xxv.recordingsDataView.prototype.szToolTip = "Zeigt Aufnahmen";
Ext.xxv.recordingsDataView.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.recordingsDataView.prototype.szEdit = "Bearbeiten";
Ext.xxv.recordingsDataView.prototype.szCut = "Schneiden";
Ext.xxv.recordingsDataView.prototype.szConvert = "Konvertieren";
Ext.xxv.recordingsDataView.prototype.szDelete = "Löschen";
Ext.xxv.recordingsDataView.prototype.szRecover = "Gelöschte Aufnahmen wiederherstellen";
Ext.xxv.recordingsDataView.prototype.szStream = "Aufnahme streamen";
Ext.xxv.recordingsDataView.prototype.szPlay = "Wiedergabe";
Ext.xxv.recordingsDataView.prototype.szLoadException = "Konnte keine Daten über Aufnahme holen!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutSuccess = "Schnittprozess der Aufnahme erfolgreich gestartet.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutFailure = "Konnte Schnittprozess der Aufnahme nicht starten!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteSuccess = "Aufnahme erfolgreich gelöscht.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteFailure = "Konnte Aufnahme nicht löschen!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackSuccess = "Wiedergabe der Aufnahme erfolgreich gestartet.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackFailure = "Konnte Wiedergabe der Aufnahme nicht starten!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgrade = "Aktualisiere Liste der Aufnahmen";
Ext.xxv.recordingsDataView.prototype.szUpgradeWait = "Bitte warten...";
Ext.xxv.recordingsDataView.prototype.szUpgradeSuccess = "Liste der Aufnahmen erfolgreich aktualisieren!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgradeFailure = "Konnte Liste der Aufnahmen nicht aktualisieren!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDetailsFailure = "Konnte Details der Aufnahme nicht aktualisieren!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szRecordingTip = "{0} {1} - {2} ({3})<br />{4}";
Ext.xxv.recordingsDataView.prototype.szFolderTip0 = "Enthält {0} Aufnahmen<br />Gesamtzeit {1}";
Ext.xxv.recordingsDataView.prototype.szFolderTip1 = "Enthält {0} Aufnahmen<br />Eine neue Aufnahme<br />Gesamtzeit {2}";
Ext.xxv.recordingsDataView.prototype.szFolderTip2 = "Enthält {0} Aufnahmen<br />{1} neue Aufnahmen<br />Gesamtzeit {2}";

/* timers.js */
Ext.xxv.timerGrid.prototype.szTitle = "Timer";
Ext.xxv.timerGrid.prototype.szFindReRun = "Suche Wiederholung";
Ext.xxv.timerGrid.prototype.szNew = "Neuen Timer anlegen";
Ext.xxv.timerGrid.prototype.szEdit = "Bearbeiten";
Ext.xxv.timerGrid.prototype.szDelete = "Löschen";
Ext.xxv.timerGrid.prototype.szToggle = "De- bzw. Aktivieren";
Ext.xxv.timerGrid.prototype.szColTitle = "Titel";
Ext.xxv.timerGrid.prototype.szColActive = "Aktiv";
Ext.xxv.timerGrid.prototype.szColPDC = "VPS";
Ext.xxv.timerGrid.prototype.szColDay = "Tag";
Ext.xxv.timerGrid.prototype.szColChannel = "Kanal";
Ext.xxv.timerGrid.prototype.szColStart = "Beginn";
Ext.xxv.timerGrid.prototype.szColStop = "Ende";
Ext.xxv.timerGrid.prototype.szColDuration = "Dauer";
Ext.xxv.timerGrid.prototype.szSelChEmptyText = "Kanal wählen...";
Ext.xxv.timerGrid.prototype.szColDayFormat = "l, d.m.Y";
Ext.xxv.timerGrid.prototype.szLoadException = "Konnte keine Daten über Timer holen!\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteSuccess = "Timer erfolgreich gelöscht.\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteFailure = "Konnte Timer nicht löschen!\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleSuccess = "Timer erfolgreich umgeschaltet.\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleFailure = "Konnte Timer nicht umgeschalten!\r\n{0}";

/* movetimers.js */
Ext.xxv.movetimersGrid.prototype.szTitle = "Regeln zum Verschieben von Timern";
Ext.xxv.movetimersGrid.prototype.szNew = "Neu";
Ext.xxv.movetimersGrid.prototype.szEdit = "Bearbeiten";
Ext.xxv.movetimersGrid.prototype.szDelete = "Löschen";
Ext.xxv.movetimersGrid.prototype.szColSource = "Quelle";
Ext.xxv.movetimersGrid.prototype.szColDestination = "Ziel";
Ext.xxv.movetimersGrid.prototype.szColMove = "Verschieben von Timern";
Ext.xxv.movetimersGrid.prototype.szColOriginal = "Verändere Original";
Ext.xxv.movetimersGrid.prototype.szLoadException = "Konnte keine Daten über Regel zum Verschieben von Timern holen!\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteSuccess = "Regel zum Verschieben von Timern erfolgreich gelöscht.\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteFailure = "Konnte Regel zum Verschieben von Timern nicht löschen!\r\n{0}";

/* users.js */
Ext.xxv.usersGrid.prototype.szTitle = "Anwenderzugänge";
Ext.xxv.usersGrid.prototype.szNew = "Neuen Anwenderzugang anlegen";
Ext.xxv.usersGrid.prototype.szEdit = "Bearbeiten";
Ext.xxv.usersGrid.prototype.szDelete = "Löschen";
Ext.xxv.usersGrid.prototype.szColTitle = "Zugang";
Ext.xxv.usersGrid.prototype.szColLevel = "Ebene";
Ext.xxv.usersGrid.prototype.szUserPreferences = "Anwender Einstellungen";
Ext.xxv.usersGrid.prototype.szAdminPreferences = "Einstellungen";
Ext.xxv.usersGrid.prototype.szLoadException = "Konnte keine Daten über die Anwenderzugänge holen!\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteSuccess = "Anwenderzugang erfolgreich gelöscht.\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteFailure = "Konnte Anwenderzugang nicht löschen!\r\n{0}";

/* vdr.js */
Ext.xxv.vdrGrid.prototype.szTitle = "Video Disk Rekorder";
Ext.xxv.vdrGrid.prototype.szEdit = "Bearbeiten";
Ext.xxv.vdrGrid.prototype.szDelete = "Löschen";
Ext.xxv.vdrGrid.prototype.szColHost = "Hostrechner";
Ext.xxv.vdrGrid.prototype.szColActive = "Aktiv";
Ext.xxv.vdrGrid.prototype.szColPrimary = "Primär";
Ext.xxv.vdrGrid.prototype.szColDirectory = "Verzeichnis";
Ext.xxv.vdrGrid.prototype.szDVBTyp = "Typ der DVB-Karten";
Ext.xxv.vdrGrid.prototype.szLoadException = "Konnte keine Daten über Video Disk Rekorder holen!\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteSuccess = "Video Disk Rekorder erfolgreich gelöscht.\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteFailure = "Konnte Video Disk Rekorder nicht löschen!\r\n{0}";

/* audio.js */
Ext.xxv.AudioWindow.prototype.szTitle = "Musikwiedergabe";
Ext.xxv.AudioWindow.prototype.szNeedFlash = "Es wird ein aktueller Flash Player benötigt, damit die Musikwiedergabe funktioniert";
Ext.xxv.AudioWindow.prototype.szSaveFile = "Datei abspeichern";

/* music.js */
Ext.xxv.musicGrid.prototype.szTitle = "Musik";
Ext.xxv.musicGrid.prototype.szToolTip = "Liste von Musiktitel anzeigen";
Ext.xxv.musicGrid.prototype.szFindTitle = "Suche gleiche Titel";
Ext.xxv.musicGrid.prototype.szFindArtist = "Suche Titel vom selben Künstler";
Ext.xxv.musicGrid.prototype.szFindAlbum = "Suche Titel vom selben Album";
Ext.xxv.musicGrid.prototype.szFindGenre = "Suche Titel vom selben Genre";
Ext.xxv.musicGrid.prototype.szFindYear = "Suche Titel aus dem selben Jahr";
Ext.xxv.musicGrid.prototype.szPlaying = "Wiedergabe";
Ext.xxv.musicGrid.prototype.szColAlbum = "Album";
Ext.xxv.musicGrid.prototype.szColArtist = "Künstler";
Ext.xxv.musicGrid.prototype.szColTitle = "Titel";
Ext.xxv.musicGrid.prototype.szColDuration = "Länge";
Ext.xxv.musicGrid.prototype.szColTrack = "Track";
Ext.xxv.musicGrid.prototype.szColYear = "Jahr";
Ext.xxv.musicGrid.prototype.szColGenre = "Genre";
Ext.xxv.musicGrid.prototype.szColComment = "Kommentar";
Ext.xxv.musicGrid.prototype.szLoadException = "Konnte keine Titel der Musikliste holen!\r\n{0}";

/* teletext */
Ext.xxv.TeleTextView.prototype.szTitle = "Videotext";
Ext.xxv.TeleTextView.prototype.szToolTip = "Zeigt Videotextseiten";
Ext.xxv.TeleTextView.prototype.szLoadException = "Konnte keine Seite des Videotext holen!\r\n{0}";

/* monitor.js */
Ext.xxv.MonitorWindow.prototype.szTitle = "Monitorbild";
Ext.xxv.MonitorWindow.prototype.szAspect = "Wiederherstellen des korrekten Seitenverhältnis";
Ext.xxv.MonitorWindow.prototype.szUpdate = "Aktualisiere Monitorbild";
Ext.xxv.MonitorWindow.prototype.szUpdateFast = "Schneller Aktualisierung des Monitorbild";
Ext.xxv.MonitorWindow.prototype.szUpdateSlow = "Langsamere Aktualisierung des Monitorbild";

/* stream.js */
Ext.xxv.StreamWindow.prototype.szTitle = "Streaming";
Ext.xxv.StreamWindow.prototype.szAspect = "Wiederherstellen des korrekten Seitenverhältnis";

/* remote.js */
Ext.xxv.RemoteWindow.prototype.szTitle = "Fernbedienung";
Ext.xxv.RemoteWindow.prototype.szRemoteFailure = "Konnte Daten der Fernbedienung nicht übertragen!\r\n{0}";

/* ux/multiselect.js */
Ext.ux.Multiselect.prototype.minLengthText = "Mindestens sind {0} Einträge notwendig";
Ext.ux.Multiselect.prototype.maxLengthText = "Maximal sind {0} Einträge erlaubt";

/* ux/filter.js */
Ext.ux.grid.Search.prototype.searchTipText = "Bitte geben Sie einen Text für die Suche ein";


