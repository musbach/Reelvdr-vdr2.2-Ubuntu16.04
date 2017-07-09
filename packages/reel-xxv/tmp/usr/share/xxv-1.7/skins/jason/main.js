/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

var XXV = {
};

Ext.Component.prototype.stateful = false;

Ext.onReady(function(){

    Ext.BLANK_IMAGE_URL = 'extjs/resources/images/default/s.gif';
    Ext.QuickTips.init();
    Ext.state.Manager.setProvider(new Ext.state.CookieProvider(
        {
           // state: Ext.appState,
           expires: new Date(new Date().getTime()+(1000*3600*24*365))
        }));
    Ext.History.init();

    var tpl = Ext.Template.from('preview-tpl', {
        compiled:true
        ,getTitle : function(v, all){
                        var title = v || all.title;
                        if(!all.subtitle) {
                          var Woerter = title.split("~");
                          if(Woerter.length > 1) {
                            /*var subtitle = */Woerter.pop();
                            return Woerter.join('~');
                          }
                        }
                        return title;
        }
        ,getSubtitle : function(v, all){
                        var subtitle = v || all.subtitle;
                        if(!subtitle) {
                          var Woerter = all.title.split("~");
                          if(Woerter.length > 1) {
                            return '&nbsp;-&nbsp;' + Woerter.pop();
                          }
                          return '&nbsp;';
                        }
                        return '&nbsp;-&nbsp;' + subtitle;
        }
        ,getChannel : function(v, all){
                        var channel = v || all.channel;
                        if(!channel) {
                          return '&nbsp;';
                        }
                        return channel;

        }
        ,getBody : function(v, all){
            return Ext.util.Format.stripScripts(v || all.description).replace(/\r\n/g, '<br />');
        }
        ,getFooter : function(v, all){
            return Ext.util.Format.stripScripts(v || all.footer || "").replace(/\r\n/g, '<br />');
        }
    });
    XXV.getTemplate = function(){
        return tpl;
    };

    XXV.help = new Ext.xxv.help();
    XXV.side = new Ext.xxv.channelsPanel();
    XXV.tab = new Ext.xxv.tabPanel();
    XXV.menu = new Ext.xxv.MainMenu();

    XXV.viewport = new Ext.Viewport({
        id:"masterlayout",
        layout:'border',
        items:[
            XXV.menu,
            XXV.side,
            XXV.tab
         ]
    });

    // Handle this change event in order to restore the UI to the appropriate history state
    Ext.History.on('change', function(token){
        if(!token){
          token = 'n';
        }
        XXV.tab.openTab(token);
    });

    XXV.tab.on('tabchange', function(tp, tab){
        Ext.xxv.Panel.prototype.DocumentTitle(tab.title);
        Ext.History.add(tab.id);
    });

    XXV.viewport.doLayout();

	  setTimeout(function(){
          var l = Ext.get('loading'); 
          if(l) {
            l.remove();
          }
          var m = Ext.get('loading-mask'); 
          if(m) {
            m.fadeOut({remove:true});
          }
    }, 250);


});
