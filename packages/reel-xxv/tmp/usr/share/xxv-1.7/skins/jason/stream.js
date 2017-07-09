/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.StreamWindow = function(item) {

    var tpl = new Ext.XTemplate(
        '<object id="player_obj" width="{width}" height="{height}"',
          'classid="CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95"',
          'codebase="http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701"',
          'standby="Loading Microsoft Windows Media Player components..." type="application/x-oleobject">',
          '<param name="fileName" value="{url}" />',
          '<param name="animationatStart" value="false" />',
          '<param name="transparentatStart" value="false" />',
          '<param name="autoStart" value="true" />',
          '<param name="showControls" value="false" />',
          '<param name="loop" value="false" />',
          '<embed id="player_emb" width="{width}" height="{height}" src="{url}" ',
            'type="application/x-mplayer2" ',
            'pluginspage="http://microsoft.com/windows/mediaplayer/en/download/" ',
            'autosize="-1" showcontrols="false" showtracker="-1" ',
            'showdisplay="0" showstatusbar="-1" videoborder3d="-1" ',
            'autostart="true" loop="false" />',
        '</object>'
    );


    var marginHeight = 33;
    var marginWidth = 16;
    var t = this.szTitle;
    if(item.title) {
      t = item.title;
    }
    Ext.xxv.StreamWindow.superclass.constructor.call(this, {
         title: t
        ,streamtpl:tpl
        ,iconCls: 'stream-icon'
        ,id: 'stream-win'
        ,minWidth: 160
        ,minHeight: 120
        ,marginWidth: marginWidth
        ,marginHeight: marginHeight
        ,width: item.width
        ,height: item.height
        ,resizable: true
        ,plain: true
        ,modal: false
        ,autoScroll: false
        ,closeAction: 'hide'
        ,maximizable: true
        ,tools:[
          {id:'gear',handler:this.aspect, scope:this, qtip:this.szAspect }
        ]
        ,items: [{
           id: 'video'
          ,region: 'center'
          ,width: item.width - marginWidth
          ,height: item.height - marginHeight
          ,html: tpl.apply({
                width : item.width - marginWidth,
                height : item.height - marginHeight,
                url: item.url
              })
        }]
    });

    Ext.xxv.StreamWindow.superclass.show.apply(this, arguments);

    this.on('resize', this.onresize, this);
};

Ext.extend(Ext.xxv.StreamWindow, Ext.Window, {

    szTitle         : "Streaming"
    ,szAspect        : "Restore aspect ratio correctly"

    ,aspect : function() {
        var size = this.getSize();
        this.setSize(size.width, Math.round((size.width * 3) / 4));
    }
    ,onresize : function(window, width, height ){
        width -= this.marginWidth;
        height -= this.marginHeight;

        var video = Ext.getCmp('video');
        video.setWidth(width);
        video.setHeight(height);

        var style = {width:width+"px",height:height+"px"};
        Ext.DomHelper.applyStyles('player_obj', style);
        Ext.DomHelper.applyStyles('player_emb', style);

    }
    ,hide : function(){
        var video = Ext.getCmp('video');
        if(video) {
          video.destroy();
          if(video.body)
            video.body.update('');
        }
        Ext.xxv.StreamWindow.superclass.hide.apply(this, arguments);
    }
    ,show : function(item){
        if(this.rendered){
          var video = Ext.getCmp('video');
          var size = this.getSize();
          video.body.hide();
          this.streamtpl.overwrite(video.body, {
                width : size.width - this.marginWidth,
                height : size.height - this.marginHeight,
                url: item.url
              });
          video.body.show();
          this.setTitle(item.title);
        }
        Ext.xxv.StreamWindow.superclass.show.apply(this, arguments);
    }
});


Ext.xxv.createStream = function(item,widget) {
    item.width = configuration.streamWidth;
    item.height = configuration.streamHeight;
    if(Ext.state.Manager.getProvider()) {
        var streamwin = Ext.state.Manager.get('stream-win');
        if(streamwin && streamwin.width && streamwin.width >= 160 && streamwin.width <= 4096) {
          item.width = streamwin.width;
        }
        if(streamwin && streamwin.height && streamwin.height >= 120 && streamwin.height <= 2048) {
          item.height = streamwin.height;
        }
    }
    if(configuration.streamWidget 
        && configuration.streamWidget == 'external') {
        window.open(item.url, '_blank', "width=" + item.width + ",height="+ item.height);
        return null;
    }
    if(!widget){
      return new Ext.xxv.StreamWindow(item);
    } else {
      widget.show(item);
    }
};
