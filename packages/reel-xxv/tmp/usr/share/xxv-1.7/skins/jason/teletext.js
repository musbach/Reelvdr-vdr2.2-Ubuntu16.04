/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2009-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */
/******************************************************************************/

Ext.xxv.TeleTextStore = function(name, channel) {

    // create the data store
    return new Ext.data.Store({
             title: name
            ,baseParams:{cmd:'vt','channel':channel}
            ,autoLoad:{params:{start:0, limit:99}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                       {name: 'id', type: 'string'}
                      ,{name: 'page', type: 'string'}
                      ,{name: 'subpage', type: 'string'}
                      ,{name: 'channel', type: 'string'}
                      ,{name: 'prev', type: 'string'}
                      ,{name: 'next', type: 'string'}
                      ,{name: 'mtime', type: 'string'}
                      ,{name: 'content', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'POST'
            })
    });
};

Ext.xxv.TeleTextView = function(viewer, store, config) {
    this.viewer = viewer;
    Ext.apply(this, config);
    this.store = store;
    var tpl = new Ext.XTemplate(
    '<tpl for=".">'
        ,'<div class="thumb-wrap" id="{id}">'
        ,'<div class="thumb">'
        ,'{content}'
        ,'</div>'
        ,'</div>'
    ,'</tpl>'
    ,'<div class="x-clear"></div>'
    );

    this.filter = new Ext.ux.grid.Search({
         position:'owner'
        ,shortcutKey:null
        ,paramNames: {
              fields:'cmd'
              ,all:'vt'
              ,cmd:'vs'
              ,query:'data'
        }
    });

    Ext.xxv.TeleTextView.superclass.constructor.call(this, {
                    region: 'center'
                    ,store: store
                    ,tpl: tpl
                    ,cls: 'x-panel-body' // workaround - add missing border
                    ,style: 'overflow:auto'
                    ,singleSelect: true
                    ,overClass:'x-view-over'
                    ,itemSelector:'div.thumb-wrap'
                    ,loadMask:null
                    ,listeners: {
                       'beforeselect'   : {fn:function(view){ return view.store.getRange().length > 0; } }
                      ,'selectionchange': {fn:this.doClick, scope:this, buffer:100}
                    }
                   ,plugins: [
                     this.filter
                   ]
                  }
  );
  this.store.on({
     'beforeload' : this.onBeforeLoad
    ,'load' : this.onLoad
    ,'loadexception' : this.onLoadException
    ,scope:this
  });
};


Ext.extend(Ext.xxv.TeleTextView,  Ext.DataView, {

     szTitle         : "Teletext"
    ,szToolTip       : "Display teletext pages"
    ,szLoadException : "Couldn't get teletext pages!\r\n{0}"

    ,onLoadException :  function( scope, o, arg, e) {
      this.viewer.loadMask.hide();
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
      var tb = this.ownerCt.getTopToolbar();
      tb.get('teletext-refresh').enable();
    }
    ,onBeforeLoad :  function( scope, params ) {
      if(this.filter.getValue())
        this.viewer.loadMask.show();
      if(this.DetailsTransaction) 
        Ext.Ajax.abort(this.DetailsTransaction);

        if(this.el && this.el.dom) {
          var elem = this.el.dom.getElementsByTagName('a');
          for (var j = 0; j < elem.length; j++) {
              var node = Ext.fly(elem[j]);
              node.removeAllListeners();
          }
        }
      var tb = this.ownerCt.getTopToolbar();
      tb.get('teletext-refresh').disable();
    }
    ,onLoad :  function( store, records, opt ) {
      // replace all anchor to pages with callback
      if(this.el && this.el.dom) {
        var elem = this.el.dom.getElementsByTagName('a');
        for (var j = 0; j < elem.length; j++) {
          var url = Ext.urlDecode(elem[j].href);
          if(url.page) {
            elem[j].href = '#';
            elem[j].id = url.page;

            var node = Ext.fly(elem[j]);
            node.on("click", function(e, ele){
              e.stopEvent();
              this.loadpage(ele.id);
            },this);
          }
        }
      }

      if(store.title) {
        this.ownerCt.SetPanelTitle(this.szTitle + " - " + store.title);
      } else {
        this.ownerCt.SetPanelTitle(this.szTitle);
      }

      var data = records[0].data;
      var tb = this.ownerCt.getTopToolbar();
      tb.get('teletext-number').setValue(data.page);
      tb.get('teletext-first').setDisabled(data.prev == 0);
      tb.get('teletext-prev').setDisabled(data.prev == 0);
      tb.get('teletext-next').setDisabled(data.next == 0);
      //tb.get('teletext-last').setDisabled(true);
      tb.get('teletext-refresh').enable();
      this.viewer.loadMask.hide();
    }
    ,doClick : function(){
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          var page = this.store.getById(selNode[0].id);
          if(page) {
            var tb = this.ownerCt.getTopToolbar();
            tb.get('teletext-number').setValue(page.data.page);
          }
        }
    }
    ,reload : function(name, channel) {
        this.store.title = name;
        this.store.baseParams.channel = channel;
        this.moveFirst();
    }
    ,loadpage : function(page) {
        var f = this.filter.field.getValue();
        if(f && f != '') {
          this.filter.field.setValue('');
          this.store.baseParams.cmd = 'vt';
        }
        if(page && page != 0)
          this.store.load({params:{'page':page, start:0, limit:99}});
    }
    ,moveFirst : function() {
        var f = this.filter.field.getValue();
        if(f && f != '') {
          this.filter.field.setValue('');
          this.store.baseParams.cmd = 'vt';
        }
        this.store.load({params:{start:0, limit:99}});
    }
    ,movePrev : function() {
        var node = this.getNode(0);
        if(node) {
          var record = this.store.getById(node.id);
          if(record) {
            this.loadpage(record.data.prev);
          }
        }
    }
    ,moveNext : function() {
        var node = this.getNode(0);
        if(node) {
          var record = this.store.getById(node.id);
          if(record) {
            this.loadpage(record.data.next);
          }
        }
    }
    ,moveLast : function() {

    }
   ,retryPage : function() {
      var node = this.getNode(0);
      if(node) {
        var record = this.store.getById(node.id);
        if(record) {
          this.store.load({params:{'page':record.data.page, start:0, limit:99}});
          return;
        }
      }
      moveFirst();
    }
    ,readPage : function(record){
        var tb = this.ownerCt.getTopToolbar();
        var input = tb.get('teletext-number');
        var v = input.getValue(), pageNum;
        if (!v || isNaN(pageNum = parseInt(v, 10))) {
          input.setValue(record.data.page);
          return false;
        }
        return pageNum;
    }
    ,onPagingBlur : function(e){
        var node = this.getNode(0);
        if(node) {
          var record = this.store.getById(node.id);
          if(record) {
            var tb = this.ownerCt.getTopToolbar();
            tb.get('teletext-number').setValue(record.data.page);
          }
        }
      }
    ,onPagingKeyDown : function(field, e){
        var node = this.getNode(0);
        if(!node) return;
        var record = this.store.getById(node.id);
        if(!record) return;

        var k = e.getKey(), pageNum;
        if (k == e.RETURN) {
            e.stopEvent();
            pageNum = this.readPage(record);
            if(pageNum !== false){
                this.loadpage(pageNum);
            }
        }else if (k == e.HOME) {
            e.stopEvent();
            this.moveFirst();
        }else if (k == e.END) {
            e.stopEvent();
            this.moveLast();
        }else if (k == e.UP || k == e.PAGEUP || k == e.DOWN || k == e.PAGEDOWN){
            e.stopEvent();
            if(k == e.DOWN || k == e.PAGEDOWN){
              this.moveNext();
            } else {
              this.movePrev();
            } 
        }
    }
});

function createTeleTextView(viewer,id,name, channel) {

    viewer.pageTeleText = new Ext.xxv.TeleTextView(
                            viewer,
                            new Ext.xxv.TeleTextStore(name, channel),
                            { id: 'teletext-view-page' });

    var tab = new Ext.xxv.Panel({
       id: id
      ,iconCls:"teletext-icon"
      ,closable:true
      ,border:false
      ,layout:'border'
      ,stateful:true
      ,items:[ viewer.pageTeleText ]
      ,tbar:new Ext.Toolbar({
        items: [
              {    
                   id: 'teletext-first'                  ,iconCls: 'x-tbar-page-first'
                  ,tooltip: Ext.PagingToolbar.prototype.firstText
                  ,scope: viewer.pageTeleText                  ,disabled:true
                  ,handler: viewer.pageTeleText.moveFirst
              },{
                   id: 'teletext-prev'                  ,iconCls: 'x-tbar-page-prev'
                  ,tooltip: Ext.PagingToolbar.prototype.prevText
                  ,scope: viewer.pageTeleText                  ,disabled:true
                  ,handler: viewer.pageTeleText.movePrev
              },'-',{
                   xtype: 'tbtext', text: Ext.PagingToolbar.prototype.beforePageText
              },{
                    id: 'teletext-number'
                   ,cls: "x-tbar-page-number"
                   ,xtype: 'numberfield'
                   ,allowDecimals: false
                   ,allowNegative: false
                   ,emptyText: Ext.PagingToolbar.prototype.emptyMsg
                   ,enableKeyEvents: true
                   ,selectOnFocus: true
                   ,listeners: {
                        scope: viewer.pageTeleText,
                        keydown: viewer.pageTeleText.onPagingKeyDown,
                        blur: viewer.pageTeleText.onPagingBlur
                   }
              },'-',{
                   id: 'teletext-next'
                  ,iconCls: 'x-tbar-page-next'
                  ,tooltip: Ext.PagingToolbar.prototype.nextText
                  ,scope: viewer.pageTeleText                  ,disabled:true
                  ,handler: viewer.pageTeleText.moveNext
              },{
                   id: 'teletext-last'
                  ,iconCls: 'x-tbar-page-last'
                  ,tooltip: Ext.PagingToolbar.prototype.lastText
                  ,scope: viewer.pageTeleText                  ,disabled:true
                  ,handler: viewer.pageTeleText.moveLast
              },'-',{
                   id: 'teletext-refresh'
                  ,iconCls: 'x-tbar-loading'
                  ,tooltip: Ext.PagingToolbar.prototype.refreshText
                  ,scope: viewer.pageTeleText                  ,disabled:false
                  ,handler: viewer.pageTeleText.retryPage
              },'->'
            ]
       })
    });

    viewer.add(tab);
    return tab;
}

