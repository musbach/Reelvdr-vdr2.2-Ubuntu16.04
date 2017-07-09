/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2009-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.AudioWindow = function(item) {

    var width = 320;
    var height = 29;
    var marginHeight = 32;
    var marginWidth = 16;

    AudioPlayer.setup("audio-player/player.swf", { 
      width: 320  
      ,animation: "no"
      ,transparentpagebg: "yes"
    });

    this.item = item;
    Ext.xxv.AudioWindow.superclass.constructor.call(this, {
         title: this.szTitle
        ,iconCls: 'music-icon'
        ,id: 'audio-win'
        ,width: width + marginWidth
        ,height: height + marginHeight
        ,resizable: false
        ,plain: true
        ,modal: false
        ,autoScroll: false
        ,closeAction: 'hide'
        ,maximizable: false
        ,stateful: true
        ,tools:[
           {id:'save',   handler:this.save, scope:this, qtip:this.szSaveFile }
        ]
        ,items: [{
           width: width
          ,height: height
          ,html: "<div id='audio-player'><p>" + this.szNeedFlash +"</p></div>"
        }]
    });
    this.on('beforeshow', this.onBeforeShow, this);
    Ext.xxv.AudioWindow.superclass.show.apply(this, arguments);
};

Ext.extend(Ext.xxv.AudioWindow, Ext.Window, {
     szTitle: "Music playback"
    ,szNeedFlash: "You need to get the latest Flash Player to hear music with this player"
    ,szSaveFile: "Save file to disk"
    ,onBeforeShow : function(){
        if(!this.embed){
          var files = "";
          for(var i = 0, len = this.item.url.length; i < len; i++){
            files += escape(this.item.url[i]);
            if((i+1) < len) {
              files += ",";
            }
          }
          AudioPlayer.embed('audio-player', {
             soundFile: files
            ,titles: this.item.title.join(',')
            ,artists: this.item.artist.join(',')
            ,autostart: 'yes'
            ,loader:'404040'
          });
          this.embed = true;
        }
    }
    ,hide : function(){
        if(this.embed) {
          AudioPlayer.close('audio-player');
        }
        Ext.xxv.AudioWindow.superclass.hide.apply(this, arguments);
    }
    ,show : function(item){
        if(this.embed) {
          AudioPlayer.load('audio-player',item.url.join(','),item.title.join(','),item.artist.join(','));
          AudioPlayer.open('audio-player');
          this.item = item;
        }
        Ext.xxv.AudioWindow.superclass.show.apply(this, arguments);
    }
    ,save : function(){
          for(var i = 0, len = this.item.url.length; i < len; i++){
              window.open(this.item.url[i], '_blank');
          }
    }
});
