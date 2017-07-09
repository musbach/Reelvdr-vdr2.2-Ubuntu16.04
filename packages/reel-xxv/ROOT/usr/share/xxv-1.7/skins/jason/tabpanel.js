/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.tabPanel = function(){

    this.initPreview();
    var tab = createNowView(this,'n');
    if(!tab) return;
    Ext.xxv.tabPanel.superclass.constructor.call(this, {
         id:'main-tabs'
        ,activeTab:0
        ,region:'center'
        ,margins:'0 5 5 0'
        ,resizeTabs:true
        ,tabWidth:150
        ,minTabWidth: 100
        ,enableTabScroll: true
        ,loadMask: null
        //,defaults: {hideMode: 'offsets'}
        ,plugins: [ new Ext.ux.TabCloseMenu() ]
        ,items: [ tab ]
    });
    this.on('render', this.initPanel, this);
};

Ext.extend(Ext.xxv.tabPanel, Ext.TabPanel, {

    initPanel : function(){
      if(!this.loadMask)
        this.loadMask = new Ext.LoadMask(this.id, {msg: Ext.LoadMask.prototype.msg, msgCls:'x-mask-loading'});
    },
    initPreview : function(){
      XXV.BottomPreview = false;
      XXV.RightPreview = true;
      if(Ext.state.Manager.getProvider()) {
        var previewstate = Ext.state.Manager.get('preview-layout');
        if(previewstate) {
          switch(previewstate){
            case 'preview-bottom':
                XXV.BottomPreview = false;
                XXV.RightPreview = true;
                break;
            case 'preview-right':
                XXV.BottomPreview = true;
                XXV.RightPreview = false;
                break;
            case 'preview-hide':
                XXV.BottomPreview = true;
                XXV.RightPreview = true;
                break;
            }
          }
      }
    }
    ,movePreview : function(m, pressed){
        if(!m || m.group != 'rp-group'){ 
            return;
        }
        if(pressed){
            var pages = ['now','program','timer','search','recording','chronicle'];
            for(var i = 0, len = pages.length; i < len; i++){
                var page = pages[i];
                var right = Ext.getCmp(page + '-right-preview');
                var bot = Ext.getCmp(page + '-bottom-preview');
                if(right && bot) {
                  var preview;
                  if(page == 'now') {
                    preview  = this.gridNow.preview;
                  } else if(page == 'program') {
                    preview  = this.gridProgram.preview;
                  } else if(page == 'timer') {
                    preview  = this.gridTimer.preview;
                  } else if(page == 'search') {
                    preview  = this.gridSearch.preview;
                  } else if(page == 'recording') {
                    preview  = this.gridRecordings.preview;
                  } else if(page == 'chronicle') {
                    preview  = this.gridChronicle.preview;
                  } else {
                    continue;
                  }
                  switch(m.iconCls){
                    case 'preview-bottom':
                        right.hide();
                        bot.add(preview);
                        bot.show();
                        bot.ownerCt.doLayout();
                        XXV.BottomPreview = false;
                        XXV.RightPreview = true;
                        //btn.setIconClass('preview-bottom');
                        break;
                    case 'preview-right':
                        bot.hide();
                        right.add(preview);
                        right.show();
                        right.ownerCt.doLayout();
                        XXV.BottomPreview = true;
                        XXV.RightPreview = false;
                        //btn.setIconClass('preview-right');
                        break;
                    case 'preview-hide':
                        preview.ownerCt.hide();
                        right.hide();
                        bot.hide();
                        preview.ownerCt.ownerCt.doLayout();
                        XXV.BottomPreview = true;
                        XXV.RightPreview = true;
                        //btn.setIconClass('preview-hide');
                        break;
                    }
                }
            }
            if(Ext.state.Manager.getProvider()) {
                Ext.state.Manager.set('preview-layout', m.iconCls);
            }
        }
    }

    ,openNow : function(){
          var id = 'n';
          var tab;
          if(!(tab = this.getItem(id))){
            tab = this.createTab(id);
          } else {
            tab.LoadTitle();
            this.gridNow.reload();
          }
          this.setActiveTab(tab);
    }
    ,openProgram : function(data){
          var id = 'p';
          var tab;
          if(!(tab = this.getItem(id))){
            tab = createProgramView(this,id,data);
          } else {
            tab.LoadTitle();
            this.gridProgram.reload(data);
          }
          this.setActiveTab(tab);
    }
    ,openSearch : function(lookup){
        var id = 's';
        var tab;
        if(!(tab = this.getItem(id))){
          tab = createSearchView(this,id,lookup);
        }else {
          tab.LoadTitle();
          this.gridSearch.loadSearch(lookup);
        }
        this.setActiveTab(tab);
    }
    ,searchTab : function(record){
        if(!record || !record.data) return;
        var d = record.data;
        var Woerter = d.title.split("~");
        var title = Woerter[0];
        this.openSearch(title);
    }
    ,Record : function(record){
        if(!record || !record.data) return;
        this.gridNow.Record(record);
    }
    ,RecordID : function(id, callback, cbscope){
        if(!id) return;
        this.gridNow.RecordID(id, callback, cbscope);
    }
    ,openTeleText : function(name, data){
          var id = 'vt';
          var tab;
          if(!(tab = this.getItem(id))){
            tab = createTeleTextView(this,id,name,data);
          } else {
            //tab.LoadTitle();
            this.pageTeleText.reload(name, data);
          }
          this.setActiveTab(tab);
    }
    ,openTab : function(id){
        var tab;
        if(!(tab = this.getItem(id))){
          tab = this.createTab(id);
        }
        if(tab) {
          this.setActiveTab(tab);
          this.show();
        }
    }

    ,createTab : function(id){
          switch(id){
            case 'n':    return createNowView(this,id);
            case 'al':   return createAutoTimerView(this,id);
            case 'tl':   return createTimerView(this,id);
            case 'rl':   return createRecordingsView(this,id);
            case 'chrl': return createChronicleView(this,id);
            case 'mtl':  return createMoveTimersView(this,id);
            case 'vl':   return createVDRView(this,id);
            case 'ul':   return createUsersView(this,id);
            case 'ml':   return createMusicView(this,id);
          }
        
        return 0;
     }
});
