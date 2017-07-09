/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2009-2010, Diego Pierotto
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 * Italian translation by Diego Pierotto [ita.translations@tiscali.it]
 */

/* common.js */
Ext.xxv.MessageBox.prototype.szFailure = "Fallito!";
Ext.xxv.MessageBox.prototype.szSuccess = "Riuscito!";

Ext.xxv.Panel.prototype.title = "Connessione ...";
Ext.xxv.Panel.prototype.szLoading = "Caricamento ...";
Ext.xxv.Panel.prototype.szTitle = "Xtreme eXtension per VDR";

/* menus.js */
Ext.xxv.MainSearchField.prototype.emptyText = "Ricerca ...";

Ext.xxv.MainMenu.prototype.szMenuXXV = "XXV";
Ext.xxv.MainMenu.prototype.szMenuProgramming = "Programmazione";
Ext.xxv.MainMenu.prototype.szMenuMedia = "Supporto";
Ext.xxv.MainMenu.prototype.szMenuRemote = "Accesso remoto";
Ext.xxv.MainMenu.prototype.szMenuView = "Visualizza";
Ext.xxv.MainMenu.prototype.szMenuItemSetup = "Opzioni";
Ext.xxv.MainMenu.prototype.szGlobalSettings = "Impostazioni globali";
Ext.xxv.MainMenu.prototype.szOwnSettings = "Impostazioni proprie";
Ext.xxv.MainMenu.prototype.szMenuItemLogout	 = "Esci";
Ext.xxv.MainMenu.prototype.szMenuItemLogoutTooltip = "Fai click sul pulsante per uscire da XXV";
Ext.xxv.MainMenu.prototype.szSelectTheme = "Seleziona tema";
Ext.xxv.MainMenu.prototype.szPreviewPreviewPane = "Anteprima finestra";
Ext.xxv.MainMenu.prototype.szPreviewRight = "Destra";
Ext.xxv.MainMenu.prototype.szPreviewBottom = "Giu'";
Ext.xxv.MainMenu.prototype.szPreviewHide = "Nascondi";
Ext.xxv.MainMenu.prototype.szLogoutSuccess = "Disconnessione riuscita.\r\n{0}";
Ext.xxv.MainMenu.prototype.szLogoutFailure = "Impossibile disconnettersi!\r\n{0}";

/* form.js */
Ext.xxv.Question.prototype.szClose = "Chiudi";
Ext.xxv.Question.prototype.szApply = "Applica";
Ext.xxv.Question.prototype.szCommandDeny = "Comando '{0}' non permesso!";
Ext.xxv.Question.prototype.szLoadException = "Impossibile recuperare i dati!\r\n{0}";
Ext.xxv.Question.prototype.szFailure = "Impossibile salvare i dati!\r\n{0}";
Ext.xxv.Question.prototype.szSuccess = "Dati salvati con successo.\r\n{0}";
Ext.xxv.Question.prototype.szComboEmpty = "Selezione ...";

/* channelspanel.js */
Ext.xxv.channelsPanel.prototype.title = "Canali";
Ext.xxv.channelsPanel.prototype.refreshText = "Aggiorna";
Ext.xxv.channelsPanel.prototype.selectText = "Seleziona canale";
Ext.xxv.channelsPanel.prototype.webcastTTText = "Trasmissione web";
Ext.xxv.channelsPanel.prototype.webcastText = "Trasmissione web dal vivo di questo canale";
Ext.xxv.channelsPanel.prototype.switchTTText: "Cambia";
Ext.xxv.channelsPanel.prototype.switchText = "Cambia su questo canale";
Ext.xxv.channelsPanel.prototype.teleTextText = "Pagine teletext";
Ext.xxv.channelsPanel.prototype.teleTextTTText = "Mostra pagine teletext di questo canale";
Ext.xxv.channelsPanel.prototype.editTTText = "Modifica";
Ext.xxv.channelsPanel.prototype.editText = "Modifica questo canale";
Ext.xxv.channelsPanel.prototype.deleteText = "Elimina questo canale";
Ext.xxv.channelsPanel.prototype.szLoadException = "Impossibile recuperare i dati del canale!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchSuccess = "Cambio del canale riuscito.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szSwitchFailure = "Impossibile cambiare canale!\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteSuccess = "Eliminazione canale riuscita.\r\n{0}";
Ext.xxv.channelsPanel.prototype.szDeleteFailure = "Impossibile eliminare il canale!\r\n{0}";

/* autotimers.js */
Ext.xxv.autotimerGrid.prototype.szTitle = "Cerca timer";
Ext.xxv.autotimerGrid.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.autotimerGrid.prototype.szNew = "Crea nuovo timer di ricerca";
Ext.xxv.autotimerGrid.prototype.szEdit = "Modifica timer di ricerca";
Ext.xxv.autotimerGrid.prototype.szDelete = "Elimina timer di ricerca";
Ext.xxv.autotimerGrid.prototype.szColSearch = "Cerca testo";
Ext.xxv.autotimerGrid.prototype.szColActive = "Attivo";
Ext.xxv.autotimerGrid.prototype.szColChannels = "Canali";
Ext.xxv.autotimerGrid.prototype.szColDirectory = "Directory";
Ext.xxv.autotimerGrid.prototype.szColStart = "Inizio";
Ext.xxv.autotimerGrid.prototype.szColStop = "Fine";
Ext.xxv.autotimerGrid.prototype.szColMinLength = "Durata minima";
Ext.xxv.autotimerGrid.prototype.szLoadException = "Impossibile recuperare dati del timer automatico!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteSuccess = "Eliminazione timer automatico riuscita.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szDeleteFailure = "Impossibile eliminare timer automatico!\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgrade = "Ricerca eventi desiderati";
Ext.xxv.autotimerGrid.prototype.szUpgradeWait = "Attendere prego...";
Ext.xxv.autotimerGrid.prototype.szUpgradeSuccess = "Ricerca eventi desiderati riuscita.\r\n{0}";
Ext.xxv.autotimerGrid.prototype.szUpgradeFailure = "Impossibile cercare eventi desiderati!\r\n{0}";

/* chronicle.js */
Ext.xxv.ChronicleGrid.prototype.szTitle = "Cronologia";
Ext.xxv.ChronicleGrid.prototype.szToolTip = "Mostra registrazioni in ordine cronologico";
Ext.xxv.ChronicleGrid.prototype.szColTitle = "Titolo";
Ext.xxv.ChronicleGrid.prototype.szColDay = "Giorno";
Ext.xxv.ChronicleGrid.prototype.szColChannel = "Canale";
Ext.xxv.ChronicleGrid.prototype.szColStart = "Inizio";
Ext.xxv.ChronicleGrid.prototype.szColStop = "Fine";
Ext.xxv.ChronicleGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.ChronicleGrid.prototype.szLoadException = "Impossibile recuperare dati della cronologia!\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteSuccess = "Eliminazione dati cronologia riuscita.\r\n{0}";
Ext.xxv.ChronicleGrid.prototype.szDeleteFailure = "Impossibile eliminare dati della cronologia!\r\n{0}";

/* now.js */
Ext.xxv.NowGrid.prototype.szTitle = "Guida programmi";
Ext.xxv.NowGrid.prototype.szPresent = "In esecuzione";
Ext.xxv.NowGrid.prototype.szFollowing = "Prossimi";
Ext.xxv.NowGrid.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.NowGrid.prototype.szProgram = "Mostra programma";
Ext.xxv.NowGrid.prototype.szRecord = "Registra";
Ext.xxv.NowGrid.prototype.szEditTimer = "Modifica timer";
/* TODO Ext.xxv.NowGrid.prototype.szToggleTimer = "Enable or disable timer"; */
Ext.xxv.NowGrid.prototype.szDeleteTimer = "Elimina timer";
Ext.xxv.NowGrid.prototype.szColPosition = "Posizione canale";
Ext.xxv.NowGrid.prototype.szColTitle = "Titolo";
Ext.xxv.NowGrid.prototype.szColChannel = "Canale";
Ext.xxv.NowGrid.prototype.szColGrpName = "Gruppo del canale";
Ext.xxv.NowGrid.prototype.szColStart = "Inizio";
Ext.xxv.NowGrid.prototype.szColStop = "Fine";
Ext.xxv.NowGrid.prototype.szLoadException = "Impossibile recuperare i dati!\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordSuccess = "Creazione timer riuscita.\r\n{0}";
Ext.xxv.NowGrid.prototype.szRecordFailure = "Impossibile creare timer!\r\n{0}";
/* TODO Ext.xxv.NowGrid.prototype.szToggleFailure = "Couldn't modify timer!\r\n{0}"; */
/* TODO Ext.xxv.NowGrid.prototype.szDeleteSuccess = "Timer deleted successful.\r\n{0}"; */
/* TODO Ext.xxv.NowGrid.prototype.szDeleteFailure = "Couldn't delete timer!\r\n{0}"; */
/* TODO Ext.xxv.NowGrid.prototype.szDetailsFailure = "Couldn't update details of event!\r\n{0}"; */

/* program.js */
Ext.xxv.programGrid.prototype.szTitle = "Guida programmi";
Ext.xxv.programGrid.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.programGrid.prototype.szRecord = "Registra";
Ext.xxv.programGrid.prototype.szColTitle = "Titolo";
Ext.xxv.programGrid.prototype.szColDay = "Giorno";
Ext.xxv.programGrid.prototype.szColStart = "Inizio";
Ext.xxv.programGrid.prototype.szColStop = "Fine";
Ext.xxv.programGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.programGrid.prototype.szLoadException = "Impossibile recuperare dati del programma!\r\n{0}";

/* search.js */
Ext.xxv.searchGrid.prototype.szTitle = "Cerca";
Ext.xxv.searchGrid.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.searchGrid.prototype.szRecord = "Registra";
Ext.xxv.searchGrid.prototype.szColTitle = "Titolo;
Ext.xxv.searchGrid.prototype.szColChannel = "Canale";
Ext.xxv.searchGrid.prototype.szColDay = "Giorno";
Ext.xxv.searchGrid.prototype.szColStart = "Inizio";
Ext.xxv.searchGrid.prototype.szColStop = "Fine";
Ext.xxv.searchGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.searchGrid.prototype.szLoadException = "Impossibile trovare i dati!\r\n{0}";

/* recordings.js */
Ext.xxv.recordingsDataView.prototype.szTitle = "Registrazioni";
Ext.xxv.recordingsDataView.prototype.szToolTip = "Mostra registrazioni";
Ext.xxv.recordingsDataView.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.recordingsDataView.prototype.szEdit = "Modifica";
Ext.xxv.recordingsDataView.prototype.szCut = "Taglia";
Ext.xxv.recordingsDataView.prototype.szConvert = "Converti";
Ext.xxv.recordingsDataView.prototype.szDelete = "Elimina";
Ext.xxv.recordingsDataView.prototype.szRecover = "Recupera registrazioni eliminate";
Ext.xxv.recordingsDataView.prototype.szStream = "Trasmetti registrazione";
Ext.xxv.recordingsDataView.prototype.szPlay = "Riproduci";
Ext.xxv.recordingsDataView.prototype.szLoadException = "Impossibile recuperare dati della registrazione!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutSuccess = "Avvio processo taglio registrazioni riuscito.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szCutFailure = "Impossibile avviare processo taglio registrazioni!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteSuccess = "Eliminazione registrazioni riuscita.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDeleteFailure = "Impossibile eliminare registrazioni!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackSuccess = "Avvio riproduzione registrazione riuscita.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szPlayBackFailure = "Impossibile avviare riproduzione registrazione!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgrade = "Aggiorna elenco registrazioni";
Ext.xxv.recordingsDataView.prototype.szUpgradeWait = "Attendere prego...";
Ext.xxv.recordingsDataView.prototype.szUpgradeSuccess = "Aggiornamento elenco registrazioni riuscito.\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szUpgradeFailure = "Impossibile aggiornare elenco registrazioni!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szDetailsFailure = "Impossibile aggiornare dettagli registrazioni!\r\n{0}";
Ext.xxv.recordingsDataView.prototype.szRecordingTip = "{0} {1} - {2} ({3})<br />{4}";
Ext.xxv.recordingsDataView.prototype.szFolderTip0 = "Esistono {0} registrazioni<br />Tempo totale {1}";
Ext.xxv.recordingsDataView.prototype.szFolderTip1 = "Esistono {0} registrazioni<br />Hai una nuova registrazione<br />Tempo totale {2}";
Ext.xxv.recordingsDataView.prototype.szFolderTip2 = "Esistono {0} registrazioni<br />Hai {1} nuove registrazioni<br />Tempo totale {2}";

/* timers.js */
Ext.xxv.timerGrid.prototype.szTitle = "Timer";
Ext.xxv.timerGrid.prototype.szFindReRun = "Cerca repliche";
Ext.xxv.timerGrid.prototype.szNew = "Crea nuovo timer";
Ext.xxv.timerGrid.prototype.szEdit = "Modifica timer";
Ext.xxv.timerGrid.prototype.szDelete = "Elimina timer";
Ext.xxv.timerGrid.prototype.szToggle = "Attiva o disattiva";
Ext.xxv.timerGrid.prototype.szColTitle = "Titolo";
Ext.xxv.timerGrid.prototype.szColActive = "Attivo";
Ext.xxv.timerGrid.prototype.szColPDC = "PDC";
Ext.xxv.timerGrid.prototype.szColDay = "Giorno";
Ext.xxv.timerGrid.prototype.szColChannel = "Canale";
Ext.xxv.timerGrid.prototype.szColStart = "Inizio";
Ext.xxv.timerGrid.prototype.szColStop = "Fine";
Ext.xxv.timerGrid.prototype.szColDuration = "Durata";
Ext.xxv.timerGrid.prototype.szHost = "Nome sistema";
Ext.xxv.timerGrid.prototype.szColDayFormat = "l, m/d/Y";
Ext.xxv.timerGrid.prototype.szSelChEmptyText = "Seleziona un canale...";
Ext.xxv.timerGrid.prototype.szLoadException = "Impossibile recuperare dati sul timer!\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteSuccess = "Eliminazione timer riuscita.\r\n{0}";
Ext.xxv.timerGrid.prototype.szDeleteFailure = "Impossibile eliminare timer!\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleSuccess = "Attivazione timer riuscita.\r\n{0}";
Ext.xxv.timerGrid.prototype.szToggleFailure = "Impossibile attivare timer!\r\n{0}";

/* movetimers.js */
Ext.xxv.movetimersGrid.prototype.szTitle = "Regole per spostamento timer";
Ext.xxv.movetimersGrid.prototype.szNew = "Nuova";
Ext.xxv.movetimersGrid.prototype.szEdit = "Modifica";
Ext.xxv.movetimersGrid.prototype.szDelete = "Elimina";
Ext.xxv.movetimersGrid.prototype.szColSource = "Sorgente";
Ext.xxv.movetimersGrid.prototype.szColDestination = "Destinazione";
Ext.xxv.movetimersGrid.prototype.szColMove = "Sposta timer";
Ext.xxv.movetimersGrid.prototype.szColOriginal = "Modifica timer originale";
Ext.xxv.movetimersGrid.prototype.szLoadException = "Impossibile recuperare dati sulla regola di spostamento timer!\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteSuccess = "Eliminazione regola per spostamento timer riuscita.\r\n{0}";
Ext.xxv.movetimersGrid.prototype.szDeleteFailure = "Impossibile eliminare regola per spostamento timer!\r\n{0}";

/* users.js */
Ext.xxv.usersGrid.prototype.szTitle = "Account utenti";
Ext.xxv.usersGrid.prototype.szNew = "Crea nuovo account";
Ext.xxv.usersGrid.prototype.szEdit = "Modifica";
Ext.xxv.usersGrid.prototype.szDelete = "Elimina";
Ext.xxv.usersGrid.prototype.szColTitle = "Account";
Ext.xxv.usersGrid.prototype.szColLevel = "Livello";
Ext.xxv.usersGrid.prototype.szUserPreferences = "Preferenze utente";
Ext.xxv.usersGrid.prototype.szAdminPreferences = "Preferenze";
Ext.xxv.usersGrid.prototype.szLoadException = "Impossibile recuperare dati account utente!\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteSuccess = "Eliminazione account utente riuscita.\r\n{0}";
Ext.xxv.usersGrid.prototype.szDeleteFailure = "Impossibile eliminare account utente!\r\n{0}";

/* vdr.js */
Ext.xxv.vdrGrid.prototype.szTitle = "Video Disk Recorder";
Ext.xxv.vdrGrid.prototype.szNew = "Nuovo";
Ext.xxv.vdrGrid.prototype.szEdit = "Modifica";
Ext.xxv.vdrGrid.prototype.szDelete = "Elimina";
Ext.xxv.vdrGrid.prototype.szColHost = "Nome sistema";
Ext.xxv.vdrGrid.prototype.szColActive = "Attivo";
Ext.xxv.vdrGrid.prototype.szColPrimary = "Primario";
Ext.xxv.vdrGrid.prototype.szColDirectory = "Directory";
Ext.xxv.vdrGrid.prototype.szDVBTyp = "Tipo di schede DVB";
Ext.xxv.vdrGrid.prototype.szLoadException = "Impossibile recuperare dati su Video Disk Recorder!\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteSuccess = "Eliminazione Video Disk Recorder riuscita.\r\n{0}";
Ext.xxv.vdrGrid.prototype.szDeleteFailure = "Impossibile eliminare Video Disk Recorder!\r\n{0}";

/* audio.js */
Ext.xxv.AudioWindow.prototype.szTitle = "Riproduci musica";
Ext.xxv.AudioWindow.prototype.szNeedFlash = "Devi avere una versione aggiornata di Flash Player per ascoltare la musica con questo lettore";
/*** Need translate */ Ext.xxv.AudioWindow.prototype.szSaveFile = "Save file to disk";

/* music.js */
Ext.xxv.musicGrid.prototype.szTitle = "Musica";
Ext.xxv.musicGrid.prototype.szToolTip = "Mostra elenco titoli musicali";
Ext.xxv.musicGrid.prototype.szFindTitle = "Cerca tracce con stesso titolo";
Ext.xxv.musicGrid.prototype.szFindArtist = "Cerca tracce con stesso artista";
Ext.xxv.musicGrid.prototype.szFindAlbum = "Cerca tracce con stesso album";
Ext.xxv.musicGrid.prototype.szFindGenre = "Cerca tracce con stesso genere";
Ext.xxv.musicGrid.prototype.szFindYear = "Cerca tracce con stesso anno";
Ext.xxv.musicGrid.prototype.szPlaying = "Riproduci";
Ext.xxv.musicGrid.prototype.szColAlbum	 = "Album";
Ext.xxv.musicGrid.prototype.szColArtist = "Artista";
Ext.xxv.musicGrid.prototype.szColTitle = "Titolo";
Ext.xxv.musicGrid.prototype.szColDuration = "Durata";
Ext.xxv.musicGrid.prototype.szColTrack = "Traccia";
Ext.xxv.musicGrid.prototype.szColYear = "Anno";
Ext.xxv.musicGrid.prototype.szColGenre = "Genere";
Ext.xxv.musicGrid.prototype.szColComment = "Commento";
Ext.xxv.musicGrid.prototype.szLoadException = "Impossibile recuperare titoli elenco musicale!\r\n{0}";

/* teletext */
Ext.xxv.TeleTextView.prototype.szTitle = "Teletext";
Ext.xxv.TeleTextView.prototype.szToolTip = "Mostra pagine teletext";
Ext.xxv.TeleTextView.prototype.szLoadException = "Impossibile recuperare pagine teletext!\r\n{0}";

/* monitor.js */
Ext.xxv.MonitorWindow.prototype.szTitle = "Schermo";
Ext.xxv.MonitorWindow.prototype.szAspect = "Ripristina risoluzione adeguata";
Ext.xxv.MonitorWindow.prototype.szUpdate = "Aggiorna schermo";
Ext.xxv.MonitorWindow.prototype.szUpdateFast = "Aggiorna schermo piu' veloce";
Ext.xxv.MonitorWindow.prototype.szUpdateSlow = "Aggiorna schermo piu' lento";

/* stream.js */
Ext.xxv.StreamWindow.prototype.szTitle = "Trasmissione";
Ext.xxv.StreamWindow.prototype.szAspect = "Ripristina risoluzione adeguata";

/* remote.js */
Ext.xxv.RemoteWindow.prototype.szTitle = "Telecomando";
Ext.xxv.RemoteWindow.prototype.szRemoteFailure = "Impossibile trasmettere dati telecomando!\r\n{0}";

/* ux/multiselect.js */
Ext.ux.Multiselect.prototype.minLengthText = "Minimo {0} voci richieste";
Ext.ux.Multiselect.prototype.maxLengthText = "Massimo {0} voci permesse";

/* ux/filter.js */
Ext.ux.grid.Search.prototype.searchTipText = "Digita il testo da cercare e premi Invio";


