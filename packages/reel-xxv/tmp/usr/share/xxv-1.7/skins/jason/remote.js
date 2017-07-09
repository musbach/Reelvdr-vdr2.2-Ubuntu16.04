/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.RemoteWindow = function() {

    Ext.xxv.RemoteWindow.superclass.constructor.call(this, {
         title: this.szTitle
        ,iconCls: 'remote-icon'
        ,id: 'Remote-win'
        ,width: 225
        ,height: 265
        ,resizable: false
        ,plain: false
        ,modal: false
        ,autoScroll: false
        ,closeAction: 'hide'
        ,collapsible: false
        ,maximizable: false
        ,items: [ 
         new Ext.form.FormPanel({
           id: 'form-panel'
          ,stateful: false
          ,forceLayout: true
          ,baseCls: 'x-plain'
          ,cls: 'btn-panel'
          ,items: [
            {
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [ 
                { scale: 'medium', scope: this, width: 32, iconCls: 'remote-logout-icon', handler: function() { this.onRemote('Power'); } }
                ]
            },{
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [ 
                 { scale: 'medium', scope: this, width: 32, text: '1', handler: function() { this.onRemote('1'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '2', handler: function() { this.onRemote('2'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '3', handler: function() { this.onRemote('3'); } }
                ,{ xtype: 'spacer', width: 12 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-menu-icon', handler: function() { this.onRemote('Menu'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-up-icon', handler: function() { this.onRemote('Up'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-back-icon', handler: function() { this.onRemote('Back'); } }
                ]
            },{
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [ 
                 { scale: 'medium', scope: this, width: 32, text: '4', handler: function() { this.onRemote('4'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '5', handler: function() { this.onRemote('5'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '6', handler: function() { this.onRemote('6'); } }
                ,{ xtype: 'spacer', width: 12 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-left-icon', handler: function() { this.onRemote('Left'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: 'Ok', handler: function() { this.onRemote('Ok'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-right-icon', handler: function() { this.onRemote('Right'); } }

                ]
            },{
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [ 
                 { scale: 'medium', scope: this, width: 32, text: '7', handler: function() { this.onRemote('7'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '8', handler: function() { this.onRemote('8'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '9', handler: function() { this.onRemote('9'); } }
                ,{ scale: 'medium', scope: this, width: 32, text: '0', handler: function() { this.onRemote('Null'); } }
                ,{ xtype: 'spacer', width: 12 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-down-icon', handler: function() { this.onRemote('Down'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-back-icon', handler: function() { this.onRemote('Back'); } }
                ]
            },{
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [ 
                 { scale: 'medium', scope: this, width: 32, iconCls: 'remote-red-icon', handler: function() { this.onRemote('Red'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-green-icon', handler: function() { this.onRemote('Green'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-yellow-icon', handler: function() { this.onRemote('Yellow'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-blue-icon', handler: function() { this.onRemote('Blue'); } }
                ,{ xtype: 'spacer', width: 12 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-quiet-icon', handler: function() { this.onRemote('VolumeMinus'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-loud-icon', handler: function() { this.onRemote('VolumePlus'); } }
                ]
            },{
              xtype: 'buttongroup'
              ,baseCls: 'x-btn-group'
              ,items: [
                 { scale: 'medium', scope: this, width: 32, iconCls: 'remote-backward-icon', handler: function() { this.onRemote('FastRew'); } }
                ,{ xtype: 'spacer', width: 6 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-record-icon', handler: function() { this.onRemote('Record'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-playback-icon', handler: function() { this.onRemote('Play'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-pause-icon', handler: function() { this.onRemote('Pause'); } }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-stop-icon', handler: function() { this.onRemote('Stop'); } }
                ,{ xtype: 'spacer', width: 6 }
                ,{ scale: 'medium', scope: this, width: 32, iconCls: 'remote-forward-icon', handler: function() { this.onRemote('FastFwd'); } }
                ]
            }   
          ]
          })
       ]
    });

    Ext.xxv.RemoteWindow.superclass.show.apply(this, arguments);
};

Ext.extend(Ext.xxv.RemoteWindow, Ext.Window, {

    szTitle         : "Remote control"
    //,szRemoteSuccess : "Successful transmit remote control data.\r\n{0}"
    ,szRemoteFailure : "Couldn't transmit remote control data!\r\n{0}"
    ,hide : function(){
        if(this.task) {
          Ext.TaskMgr.stop(this.task);
          delete this.task;
        }

        Ext.xxv.RemoteWindow.superclass.hide.apply(this, arguments);
    }
    ,show : function(){
        Ext.xxv.RemoteWindow.superclass.show.apply(this, arguments);
    }
/******************************************************************************/
  ,onRemoteSuccess : function( response,options ) 
  { 
      var json = response.responseText;
      var o = eval("("+json+")");
      if(!o || !o.data || typeof(o.data) != 'string') {
        throw {message: "Ajax.read: Json message not found"};
      }
      if(!o.success) {
          new Ext.xxv.MessageBox().msgFailure(this.szRemoteFailure, o.data);
      }
  }
  ,onRemoteFailure : function( response,options ) 
  { 
      new Ext.xxv.MessageBox().msgFailure(this.szRemoteFailure, response.statusText);
  }
  ,onRemote : function( rc ) {
    if(this.Remotetid) Ext.Ajax.abort(this.Remotetid);
    this.Remotetid = Ext.Ajax.request({
        url: XXV.help.cmdAJAX('r',{ 'data': rc, '__vdr': XXV.menu.host })
       ,success: this.onRemoteSuccess
       ,failure: this.onRemoteFailure
       ,scope:   this
    });
  }
});

Ext.xxv.RemoteWindowOpen = function(){
    var viewer = Ext.getCmp('main-tabs');
    if(!viewer.Remote){
      viewer.Remote = new Ext.xxv.RemoteWindow();
    } else {
      viewer.Remote.show();
    }
};

