/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.MainSearchField = Ext.extend(Ext.form.TwinTriggerField, {
    initComponent : function(){
      Ext.xxv.MainSearchField.superclass.initComponent.call(this);
        this.on('specialkey', function(f, e){
            if(e.getKey() == e.ENTER){
                this.onTrigger2Click();
            }
        }, this);
    }
    ,emptyText:"Search ..."
    ,validationEvent:false
    ,validateOnBlur:false
    //,trigger1Class:'x-form-clear-trigger'
    ,trigger2Class:'x-form-search-trigger'
    ,hideTrigger1:true
    ,width:200
    ,hasSearch : false

    /*,onTrigger1Click : function(){
       if(this.hasSearch){
        this.hasSearch = false;
        this.setValue();
       }
    }*/
});

Ext.xxv.Menu = Ext.extend(Ext.menu.Menu, {
    initComponent : function(){
      Ext.xxv.Menu.superclass.initComponent.call(this);
      this.on('beforerender', function(menu) {
        menu.items.eachKey(function(key, f) { 
                        if(f.cmd && XXV.help.cmdAllowed(f.cmd)) 
                          f.enable();
                        },menu.items); 
      } , this);
    }
});

Ext.xxv.MainMenu = function(/*config*/){

    this.vdrStore = new Ext.xxv.vdrStore();

    var selTheme = this.initTheme();

    XXV.configMenu = new Ext.menu.Menu();
    var setupMenu = new Ext.xxv.Menu({
      defaults: {
        disabled:true
       ,handler: function(b,e) { XXV.tab.openTab(b.cmd); }
      }
      ,items:[{
            text:this.szOwnSettings
           ,iconCls: 'setup-icon'
           ,handler: XXV.help.Settings
           ,scope:XXV.help
           ,cmd: 'up'
        },{
            text:this.szGlobalSettings
           ,iconCls: 'setup-icon'
           ,menu: XXV.configMenu
           ,cmd: 'ce'
        },'-',{
           text: Ext.xxv.movetimersGrid.prototype.szTitle
          ,iconCls:"movetimers-icon"
          ,cmd: 'mtl'
        },{   
           text: Ext.xxv.vdrGrid.prototype.szTitle
          ,iconCls:"vdr-icon"
          ,cmd: 'vl'
        },{   
           text: Ext.xxv.usersGrid.prototype.szTitle
          ,iconCls:"users-icon"
          ,cmd: 'ul'
        }
       ]
    });

    var systemMenu = new Ext.menu.Menu({
      items:[{
            text:this.szMenuItemSetup
           ,iconCls: 'setup-icon'
           ,menu: setupMenu
        },'-',{
           text:this.szMenuItemLogout
           ,handler: this.Logout
          ,iconCls:"logout-icon"
          ,disabled:false
        }
       ]
    });

    var ProgrammingMenu = new Ext.xxv.Menu({
      defaults: {
        disabled:true
       ,handler: function(b,e) { XXV.tab.openTab(b.cmd); }
      }
      ,items:[{
           text: Ext.xxv.autotimerGrid.prototype.szTitle 
          ,iconCls:"autotimer-icon"
          ,cmd: 'al'
        }, 
        {
           text: Ext.xxv.timerGrid.prototype.szTitle
          ,iconCls:"timer-icon"
          ,cmd: 'tl'
        }
       ]
    });
    
    var MediaMenu = new Ext.xxv.Menu({
      defaults: {
        disabled:true
       ,handler: function(b,e) { XXV.tab.openTab(b.cmd); }
      }
      ,items:[{
           text: Ext.xxv.recordingsDataView.prototype.szTitle
          ,iconCls:"recordings-icon"
          ,cmd: 'rl'
        },{
           text: Ext.xxv.ChronicleGrid.prototype.szTitle
          ,iconCls:"chronicle-icon"
          ,cmd: 'chrl'
        },{
          text: Ext.xxv.musicGrid.prototype.szTitle
          ,iconCls:"music-icon"
          ,cmd: 'ml'
        }/*,{
          text: Ext.xxv.mediaDataView.prototype.szTitle, 
          iconCls:"media-icon",
          ,cmd: 'mll'
        }*/
       ]
    });

    var RemoteMenu = new Ext.xxv.Menu({
      defaults: {
        disabled:true
      }
      ,items:[{
          text: Ext.xxv.RemoteWindow.prototype.szTitle
          ,handler: function() { Ext.xxv.RemoteWindowOpen(); }
          ,iconCls:"remote-icon"
          ,cmd: 'r'
          ,scope:this
        },{
          text: Ext.xxv.MonitorWindow.prototype.szTitle
          ,handler: function() { Ext.xxv.MonitorWindowOpen(); }
          ,iconCls:"monitor-icon"
          ,cmd: 'r'
          ,scope:this
        }]
    });

    // see this.styles to enum themes
    var themes = new Array;
    for(var i = 0, len = this.styles.length; i < len; i++){
      themes.push({
      text: this.styles[i][1],
      checked: selTheme == i ? true : false,
      group: 'theme',
      checkHandler: this.onSelectTheme,
      scope: this
      });
    }

    Ext.xxv.MainMenu.superclass.constructor.call(this, {
      id:"MainMenu",
      region:"north",
      height:26, 
      items:[{ 
            text:this.szMenuXXV,
            menu:systemMenu,      
            iconCls:"xxv-icon" 
          },{ 
            text:this.szMenuProgramming, 
            menu:ProgrammingMenu, 
            iconCls:"edit-icon" 
          },{
            text:this.szMenuMedia,       
            menu:MediaMenu,       
            iconCls:"media-icon"  
          },{ 
            text:this.szMenuRemote,       
            menu:RemoteMenu,       
            iconCls:"remote-icon"  
          },{
            text:this.szMenuView,
            iconCls: 'view-icon',
            menu:{
                  items: [
                            {
                              text: this.szSelectTheme,
                              iconCls: 'preview-hide',
                              menu: {
                                  cls:'reading-menu',
                                  items: themes
                              }
                          }
                          ,
                          {   text:this.szPreviewPreviewPane,
                              iconCls: 'preview-icon',
                              menu:{
                                  id:'reading-menu',
                                  cls:'reading-menu',
                                  items: [
                                  {
                                      text:this.szPreviewBottom,
                                      checked:true,
                                      group:'rp-group',
                                      checkHandler:XXV.tab.movePreview,
                                      scope:XXV.tab,
                                      iconCls:'preview-bottom'
                                  },{
                                      text:this.szPreviewRight,
                                      checked:false,
                                      group:'rp-group',
                                      checkHandler:XXV.tab.movePreview,
                                      scope:XXV.tab,
                                      iconCls:'preview-right'
                                  },{
                                      text:this.szPreviewHide,
                                      checked:false,
                                      group:'rp-group',
                                      checkHandler:XXV.tab.movePreview,
                                      scope:XXV.tab,
                                      iconCls:'preview-hide'
                                  }]
                              }
                          }
                      ]}
          },
          "->", 
          new Ext.xxv.MainSearchField({   
                onTrigger2Click : function(){
                        var v = this.getRawValue();
                        if(v.length < 1){
                            this.onTrigger1Click();
                            return;
                        }
                        XXV.tab.openSearch(v);
                }
              })
        ]
    });

    this.vdrStore.on({
         'load' : this.onVDRLoad
//      ,'loadexception' : this.onVDRLoadException
        ,scope:this
    });
};


Ext.extend(Ext.xxv.MainMenu, Ext.Toolbar, {

     szMenuXXV             : "XXV"
    ,szMenuProgramming     : "Programming"
    ,szMenuMedia           : "Media"
    ,szMenuRemote          : "Remote access"
    ,szMenuView            : "View"

    ,szMenuItemSetup       : "Setup"
    ,szGlobalSettings      : "Global settings"
    ,szOwnSettings         : "Own settings"
    ,szMenuItemLogout       : "Logout"    
    ,szMenuItemLogoutTooltip : "Click this button to logout from XXV"

    ,szSelectTheme         : "Select theme"
    ,szPreviewPreviewPane  : "Preview Pane"
    ,szPreviewRight        : "Right"
    ,szPreviewBottom       : "Bottom"
    ,szPreviewHide         : "Hide"

    ,szLogoutSuccess : "Successful logout.\r\n{0}"
    ,szLogoutFailure : "Couldn't logout!\r\n{0}"

    ,cssPath:'extjs/resources/css/'
    ,styles: [
               ['xtheme-default.css',   'Default Theme']
              ,['xtheme-gray.css',      'Gray']
              ,['xtheme-slate.css',     'Slate']
              ,['xtheme-darkgray.css',  'Dark Gray']
              ,['xtheme-black.css',     'Black']
              ,['xtheme-olive.css',     'Olive']
              ,['xtheme-purple.css',    'Purple']
          ]
    ,initTheme: function(){
        if(Ext.state.Manager.getProvider()) {
            var theme = Ext.state.Manager.get('theme');
            if(theme && theme != 'xtheme-default.css') {
                for(var i = 0, len = this.styles.length; i < len; i++){
                if(this.styles[i][0] == theme) {
                  Ext.util.CSS.swapStyleSheet('theme', this.cssPath + theme);
                  return i;
                }
              }
            }
        }
        return 0;
    }
    ,onSelectTheme: function(item, checked){
        if(checked) {
          for(var i = 0, len = this.styles.length; i < len; i++){
          if(this.styles[i][1] == item.text) {
            var theme = this.styles[i][0];
              Ext.util.CSS.swapStyleSheet('theme', this.cssPath + theme);

            if(Ext.state.Manager.getProvider()) {
                Ext.state.Manager.set('theme', theme);
            }
            return;
          }
        }
       }
    }
/******************************************************************************/
    ,Logout: function(){
        Ext.MessageBox.show({
                   title: this.szMenuItemLogout
                   ,msg: Ext.form.BasicForm.prototype.waitTitle
                   ,width:240
                   ,closable:false
               });
      Ext.Ajax.request({
          url: XXV.help.cmdAJAX('logout')
      });
      setTimeout(function(){
            XXV.viewport.container.fadeOut(
              {
                  remove:true
                  ,duration: 0.5
                  ,callback:function(){
                    Ext.MessageBox.updateText('Session closed!');
                  }
              }
            );
      }, 250);
    }

/******************************************************************************/
    ,onVDRLoad: function( store, records, opt ){

      var r = this.get(3).menu;
      if(store.data.length > 1) {
        r.removeAll(true);

        this.host = this.initHost(store);

        var e = !(XXV.help.cmdAllowed('r'));

        r.addItem({
            text: Ext.xxv.RemoteWindow.prototype.szTitle
            ,handler: function() { Ext.xxv.RemoteWindowOpen(); }
            ,iconCls:"remote-icon"
            ,cmd: 'r'
            ,disabled: e
            ,scope:this
          });
        r.addItem({
            text: Ext.xxv.MonitorWindow.prototype.szTitle
            ,handler: function() { Ext.xxv.MonitorWindowOpen(); }
            ,iconCls:"monitor-icon"
            ,cmd: 'r'
            ,disabled: e
            ,scope:this
          });

        r.addSeparator();
        for(var i = 0, len = store.data.length; i < len; i++){
          var rec = store.getAt(i);
          if(!this.host && rec.data.primary) {
            this.host = rec.data.id;
          }
          if(rec.data.active) {
            r.addItem({
              text: rec.data.host
              ,checked: this.host == rec.data.id ? true : false
              ,group: 'host'
               ,checkHandler: this.onSelectHost
              ,scope: this
              ,disabled: e
            });
          }
        }
      }
    }
    ,initHost: function(store){
        if(Ext.state.Manager.getProvider()) {
            var h = Ext.state.Manager.get('host');
            if(h) {
              for(var i = 0, len = store.data.length; i < len; i++){
                var rec = store.getAt(i);
                if(rec.data.id == h) {
                  this.host = h;
                  return rec.data.id;
                }
              }
            }
        }
        return 0;
    }
    ,onSelectHost: function(item, checked){
        if(checked) {
          for(var i = 0, len = this.vdrStore.data.length; i < len; i++){
            var rec = this.vdrStore.getAt(i);
            if(rec.data.host == item.text) {
              this.host = rec.data.id;

              if(Ext.state.Manager.getProvider()) {
                 Ext.state.Manager.set('host', this.host);
              }
              return;
            }
          }
       }
    }
});


