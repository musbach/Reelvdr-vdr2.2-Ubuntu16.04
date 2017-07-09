/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.MonitorWindow = function() {

    this.UpdateRate = 2;
    this.UpdateRateInv = [1000,2000,5000,10000,15000,30000,60000];


//    '<img id="monitor_img" src="?cmd=gdisplay&amp;width={width}&amp;height={height}&amp;_dc={random}" width="{width}" height="{height}" />'
    var tpl = new Ext.XTemplate(
      '<img id="monitor_img" style="background:black" src="extjs/resources/images/default/s.gif" width="{width}" height="{height}" />'
    );

    var width = configuration.monitorWidth;
    var height = configuration.monitorHeight;
    if(Ext.state.Manager.getProvider()) {
        var monitorwin = Ext.state.Manager.get('monitor-win');
        if(monitorwin && monitorwin.width && monitorwin.width >= 160 && monitorwin.width <= 4096) {
          width = monitorwin.width;
        }
        if(monitorwin && monitorwin.height && monitorwin.height >= 120 && monitorwin.height <= 2048) {
          height = monitorwin.height;
        }
    }
    var marginHeight = 33;
    var marginWidth = 16;
    
    Ext.xxv.MonitorWindow.superclass.constructor.call(this, {
         title: this.szTitle
        ,monitortpl:tpl
        ,iconCls: 'monitor-icon'
        ,id: 'monitor-win'
        ,minWidth: 160
        ,minHeight: 120
        ,marginWidth: marginWidth
        ,marginHeight: marginHeight
        ,width: width
        ,height: height
        ,resizable: true
        ,plain: true
        ,modal: false
        ,autoScroll: false
        ,closeAction: 'hide'
        ,maximizable: true
        ,tools:[
           {id:'gear',   handler:this.aspect, scope:this, qtip:this.szAspect }
          ,{id:'plus',   handler:this.upFast, scope:this, qtip:this.szUpdateFast }
          ,{id:'refresh',handler:this.update, scope:this, qtip:this.szUpdate  }
          ,{id:'minus',  handler:this.upSlow, scope:this, qtip:this.szUpdateSlow }
        ]
        ,items: [{
           id: 'monitor'
          ,region: 'center'
          ,width: width - marginWidth
          ,height: height - marginHeight
          ,html: tpl.apply({
                width : width - marginWidth,
                height : height - marginHeight
              })
        }]
    });

    Ext.xxv.MonitorWindow.superclass.show.apply(this, arguments);

    this.on('resize', this.onresize, this);
    this.update();
};

Ext.extend(Ext.xxv.MonitorWindow, Ext.Window, {

    szTitle         : "Monitor"
    ,szAspect       : "Restore aspect ratio correctly"
    ,szUpdate       : "Update monitor"
    ,szUpdateFast   : "Faster update monitor"
    ,szUpdateSlow   : "Slower update monitor"

    ,aspect : function() {
        var size = this.getSize();
        this.setSize(size.width, Math.round((size.width * 3) / 4));
    }
    ,onresize : function(window, width, height ){
        width -= this.marginWidth;
        height -= this.marginHeight;

        var monitor = Ext.getCmp('monitor');
        monitor.setWidth(width);
        monitor.setHeight(height);

        var style = {width:width+"px",height:height+"px"};
        Ext.DomHelper.applyStyles('monitor_img', style);
    }
    ,hide : function(){
        if(this.timer) {
          clearTimeout(this.timer);
          delete this.timer;
        }

        Ext.xxv.MonitorWindow.superclass.hide.apply(this, arguments);
    }
    ,upFast : function(){
      if(this.UpdateRate > 0) {
        this.UpdateRate -= 1;
        this.update();
        //var tool = Ext.getCmp(this.tools.minus.id);
        //tool.enable();
      } /*else {
        //var tool = Ext.getCmp(this.tools.plus.id);
        //tool.disable();
      } */
   }
   ,upSlow : function(){
      if(this.UpdateRate < this.UpdateRateInv.length) {
        this.UpdateRate += 1;
        this.update();
        //var tool = Ext.getCmp(this.tools.plus.id);
        //tool.enable();
      } /*else {
        //var tool = Ext.getCmp(this.tools.minus.id);
        //tool.disable();
      } */
   }
   ,update : function(){
          var monitor = Ext.getCmp('monitor');
          if(!monitor || this.hidden) {  
            return;
          }
          var size = monitor.getSize();
          if(!size) {  
            return;
          }
          var img = Ext.get('monitor_img');
          if(!img) {  
            return;
          }

          img.un('load', this.onupdate , this);
          img.on('load', this.onupdate , this);
          //img.hide();
          img.dom.src = XXV.help.cmdHTML('gdisplay', {
                  'width': size.width
                 ,'height': size.height
                 ,'_dc': (new Date().getTime())
                 ,'__vdr': XXV.menu.host });
    }
   ,onupdate : function(){
      if(this.timer) {
        clearTimeout(this.timer);
        delete this.timer;
      }
      this.timer = setTimeout(function(){
          Ext.getCmp('monitor-win').update();
      }, this.UpdateRateInv[this.UpdateRate]);
   }
});

Ext.xxv.MonitorWindowOpen = function(){
    var viewer = Ext.getCmp('main-tabs');
    if(!viewer.monitor){
      viewer.monitor = new Ext.xxv.MonitorWindow();
    } else {
      viewer.monitor.show();
      viewer.monitor.update();
    }
};

