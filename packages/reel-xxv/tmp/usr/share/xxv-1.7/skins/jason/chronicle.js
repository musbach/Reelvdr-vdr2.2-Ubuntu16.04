/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.chronicleStore = function() {

    // create the data store
    return new Ext.data.Store({
             baseParams:{cmd:'chrl'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                      {name: 'id', type: 'int'},
                      {name: 'title', type: 'string'},
                      {name: 'channel', type: 'string'},
                      {name: 'day', type:'date', dateFormat:'timestamp'},
                      {name: 'start', type: 'string'},
                      {name: 'stop', type: 'string'},
                      {name: 'description', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'day', direction:'ASC'}
    });
};

Ext.xxv.ChronicleGrid = function(viewer) {
    this.viewer = viewer;
    this.preview = new Ext.xxv.ChroniclePreview(viewer);

    // create the data store
    this.store = new Ext.xxv.chronicleStore();
    this.store.setDefaultSort('title', "ASC");

    this.columns = [
        {
           id:'expand'
           ,header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 200
           ,renderer: this.formatTitle
        },
        {           header: this.szColChannel
           ,dataIndex: 'channel'
           ,width: 130
        },{
           header: this.szColDay
           ,dataIndex: 'day'
           ,width: 50
           ,renderer: Ext.util.Format.dateRenderer(this.szColDayFormat)
        },{
           header: this.szColStart
           ,dataIndex: 'start'
           ,width: 50
        },{
           header: this.szColStop
           ,dataIndex: 'stop'
           ,width: 50
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;
    this.filter = new Ext.ux.grid.Search({
             position:'top'
            ,shortcutKey:null
            ,paramNames: {
                  fields:'cmd'
                  ,all:'chrl'
                  ,cmd:'chrs'
                  ,query:'data'
              }
        });
    Ext.xxv.ChronicleGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'chronicle-view-grid'
        ,loadMask: true
        ,clicksToEdit:1
        ,autoExpandColumn:'expand'
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:false
        })
        ,tbar:new Ext.PagingToolbar({
              pageSize: this.store.autoLoad.params.limit,
              store: this.store,
              displayInfo: true })
        ,plugins:[this.filter]
    });

    this.store.on({
         'load' : this.onLoad
        ,'beforeload'    : this.onBeforeLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });

    this.on('rowcontextmenu', this.onContextClick, this);
    this.getSelectionModel().on('rowselect', this.select, this, {buffer:50});
    this.on('rowdblclick', this.onEditItem, this);
};

Ext.extend(Ext.xxv.ChronicleGrid,  Ext.grid.EditorGridPanel, {

     szTitle         : "Chronicle"
    ,szToolTip       : "Display recordings in chronological order"
    ,szDelete        : "Delete"
    ,szColTitle      : "Title"
    ,szColDay        : "Day"
    ,szColChannel    : "Channel"
    ,szColStart      : "Start"
    ,szColStop       : "Stop"
    ,szColDayFormat  : "l, m/d/Y"
    ,szLoadException : "Couldn't get data from chronicle!\r\n{0}"
    ,szDeleteSuccess : "Data from chronicle deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete data from chronicle!\r\n{0}"
 
    ,stateful:  true

    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onBeforeLoad : function(  store, opt ) {
      this.preview.clear();
    }
    ,onLoad : function( store, records, opt ) {
      this.ownerCt.SetPanelTitle(this.szTitle);
      this.getSelectionModel().selectFirstRow();
    }
    ,onContextClick : function(grid, index, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [{
                     itemId:'s'
                    ,text:  Ext.xxv.timerGrid.prototype.szFindReRun
                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.viewer.searchTab(this.ctxRecord);}
                   },{
                     itemId:'chrd'
                    ,text:  Ext.xxv.timerGrid.prototype.szDelete
                    ,iconCls: 'delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteItem(this.ctxRecord); }
                  }
                ]
            });
            this.menu.on('hide', this.onContextHide, this);
        }
        e.stopEvent();
        if(this.ctxRow){
            Ext.fly(this.ctxRow).removeClass('x-node-ctx');
            this.ctxRow = null;
        }
        this.ctxRow = this.view.getRow(index);
        this.ctxRecord = this.store.getAt(index);
        Ext.fly(this.ctxRow).addClass('x-node-ctx');

        var items = this.menu.items;
        if(items) { items.eachKey(function(key, f) {
                      if(XXV.help.cmdAllowed(f.itemId)) 
                        f.enable();
                      },items); 
                  }

        this.menu.showAt(e.getXY());
    },

    onContextHide : function(){
        if(this.ctxRow){
            Ext.fly(this.ctxRow).removeClass('x-node-ctx');
            this.ctxRow = null;
        }
        if(this.menu) {
          this.menu.destroy();
          delete this.menu;
          this.menu = null;
        }
    },

    formatTitle: function(value, p, record) {
        return String.format(
              '<div class="topic"><b>{0}</b></div>',
              value
              );
    }
  /******************************************************************************/
    ,onDeleteSuccess : function( response,options ) 
    { 
        this.loadMask.hide(); 

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szDeleteSuccess, o.data);

            var gsm = this.getSelectionModel();
            var sel = options.params.data.split(",");
            sel.sort(function (a, b) { return b - a; });
            for(var i = 0, len = sel.length; i < len; i++){
              if(gsm.isIdSelected(sel[i])) {
                if(gsm.hasPrevious()) {
                  gsm.selectPrevious();
                } else {
                  gsm.selectNext();
                }
              }
              var record = this.store.getById(sel[i]);
              this.store.remove(record);
            }
        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, msg);
        }
    }
    ,onDeleteFailure : function( response,options ) { 
        this.loadMask.hide(); 
        new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, response.statusText);
    }
    ,DeleteItem : function( record ) {
      this.stopEditing();
      this.loadMask.show(); 

      var gsm = this.getSelectionModel();
      var sel = gsm.getSelections();
      if(sel.length <= 0) {
       gsm.selectRecords([record]);
       sel.push(record);
      }
      var todel = "";
      for(var i = 0, len = sel.length; i < len; i++){
        if(i !== 0)
          todel += ',';
        todel += sel[i].data.id;
      }
      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('chrd')
         ,timeout: 15000
         ,success: this.onDeleteSuccess
         ,failure: this.onDeleteFailure
         ,params:{ data: todel }
      });
    }
    ,select : function(sm, index, record){
      this.preview.select(record, this.filter.getValue());
    }
});

Ext.xxv.ChroniclePreview = function(viewer) {
    this.viewer = viewer;
    Ext.xxv.ChroniclePreview.superclass.constructor.call(this, {
        id: 'chronicle-preview',
        region: 'south',
        cls:'preview',
        autoScroll: true,
        stateful:true,
        tbar: [ {
            id:'s',
            tooltip: Ext.xxv.timerGrid.prototype.szFindReRun,
            iconCls: 'find-icon',
            disabled:true,
            scope: viewer,
            handler: function(){ this.searchTab(this.gridChronicle.getSelectionModel().getSelected()); }
        } ]
    });
};

Ext.extend(Ext.xxv.ChroniclePreview, Ext.Panel, {
  select : function(record, lookup){
    if(this.body)
      XXV.getTemplate().overwrite(this.body, record.data);
    if(lookup)
      highlightText(this.body.dom,lookup,'x-highlight',1);
    // Enable all toolbar buttons
    var items = this.topToolbar.items;
    if(items) { 
        items.eachKey(function(key, f) {
                  if(XXV.help.cmdAllowed(key)) f.enable();
          },items); 
      }
  }
  ,clear: function(){
      if(this) {
        if(this.body)
           this.body.update('');
        // Disable all items
        var items = this.topToolbar.items;
        if(items) { items.eachKey(function(key, f){f.disable();},items); }
      }
   }
});

function createChronicleView(viewer,id) {

    viewer.gridChronicle = new Ext.xxv.ChronicleGrid(viewer);
  
    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"chronicle-icon",
      closable:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[ viewer.gridChronicle
             ,{
                id:'chronicle-bottom-preview',
                layout:'fit',
                items:XXV.BottomPreview ? 0 : viewer.gridChronicle.preview,
                height: 250,
                split: true,
                border:false,
                region:'south',
                hidden:XXV.BottomPreview
            }, {
                id:'chronicle-right-preview',
                layout:'fit',
                items:XXV.RightPreview ? 0 : viewer.gridChronicle.preview,
                border:false,
                region:'east',
                width:350,
                split: true,
                hidden:XXV.RightPreview
            }
          ]
    });


    viewer.add(tab);
    return tab;
}

