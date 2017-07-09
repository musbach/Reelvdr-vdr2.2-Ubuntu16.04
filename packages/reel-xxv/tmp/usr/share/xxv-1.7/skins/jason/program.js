/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.programStore = function(data) {
    return new Ext.data.GroupingStore({
             title:data.name
            ,baseParams:{cmd:'p',data: data.id}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                          fields: [
                                     {name: 'id', type: 'string'}
                                    ,{name: 'title', type: 'string'}
                                    ,{name: 'subtitle', type: 'string'}
                                    ,{name: 'start', type: 'string' }
                                    ,{name: 'stop', type: 'string' }
                                    ,{name: 'day', type:'date', dateFormat:'timestamp'}
                                    ,{name: 'description', type: 'string'}
                                    ,{name: 'vps', type:'date', dateFormat:'timestamp'}
                                    ,{name: 'timerid', type: 'string'}
                                    ,{name: 'timeractiv', type: 'string'}
                                    ,{name: 'running', type: 'string'}
                                    ,{name: 'level', type: 'int'}
                                    //*** filled later by display ***
                                    ,{name: 'image', type: 'string'}
                                    ,{name: 'audio', type: 'string'}
                                    ,{name: 'video', type: 'string'}
                                    ,{name: 'contents', type: 'string'}
                                  ]
                      }),
            proxy : new Ext.data.HttpProxy({
                url: XXV.help.baseURL()
                ,method: 'GET'
            }),
            sortInfo:{field:'day', direction:'ASC'},
            groupField:'day'
    });
};

Ext.xxv.programGrid = function(viewer, record) {
    this.viewer = viewer;

    // create the data store
    this.store = new Ext.xxv.programStore(record);

    this.preview = new Ext.xxv.programPreview(viewer, this.store);

    this.store.setDefaultSort('day', "ASC");

    this.columns = [{
           id:'expand'
           ,header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 150
           ,renderer: { fn: this.viewer.gridNow.formatTitle, scope: this.viewer.gridNow }
        },{
           header: this.szColDay,
           dataIndex: 'day',
           width: 50,
           hidden: true,
           renderer: Ext.util.Format.dateRenderer(this.szColDayFormat)
        },{
           header: this.szColStart,
           dataIndex: 'start',
           width: 50
        },{
           header: this.szColStop,
           dataIndex: 'stop',
           width: 50
    }];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;

    this.filter = new Ext.ux.grid.Search({
             position:'top'
            ,shortcutKey:null
            ,paramNames: {
                     fields:'cmd'
                    ,all:'p'
                    ,cmd:'p'
                    ,query:'filter'
                }
        });

    Ext.xxv.programGrid.superclass.constructor.call(this, {
        region: 'center'
        ,id: 'program-grid'
        ,loadMask: false
        ,autoExpandColumn:'expand'
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:false
        })
        ,view: new Ext.xxv.GroupingView({
            enableGroupingMenu:false,
            forceFit:true,
            showGroupName: false,
            enableGrouping:true
        })
        ,tbar:new Ext.PagingToolbar({
             pageSize: configuration.pageSize
            ,store: this.store
            ,displayInfo: true
        })
        ,plugins:[this.filter]
    });

    this.store.on({
         'load' :          this.onLoad
        ,'beforeload'    : this.onBeforeLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });
    this.on('rowcontextmenu', this.onContextClick, this);
    this.getSelectionModel().on('rowselect', this.showDetails, this, {buffer:50});
};

Ext.extend(Ext.xxv.programGrid, Ext.grid.GridPanel, {

     szTitle         : "Program guide"
    ,szFindReRun     : "Find rerun"
    ,szRecord        : "Record"
    ,szColTitle      : "Title"
    ,szColDay        : "Day"
    ,szColStart      : "Start"
    ,szColStop       : "Stop"
    ,szColDayFormat  : "l, m/d/Y"
    ,szLoadException : "Couldn't get program data!\r\n{0}"

    ,stateful:  true

    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onBeforeLoad : function(  store, opt ) {
      this.preview.clear();
    }
    ,onLoad : function( store, records, opt ) {
      if(this.view.keepSelection)
        this.getSelectionModel().selectRows(this.view.keepSelection,false);
      else
        this.getSelectionModel().selectFirstRow();

      this.ownerCt.SetPanelTitle(store.title);
    }
    ,showDetails : function(sm, index, record){
      this.preview.showDetails(record, record.data.id, this.filter.getValue());
    } 
    ,onContextClick : function(grid, index, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [{
                     itemId:'s'
                    ,text: this.szFindReRun
                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.viewer.searchTab(this.ctxRecord); }
                    },'-',{
                     itemId:'tn'
                    ,text: this.szRecord
                    ,iconCls: 'record-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.Record(null); }
                    },{
                     itemId:'te'
                    ,text: this.viewer.gridNow.szEditTimer
                    ,iconCls: 'timer-edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditTimer(this.ctxRecord); }
                    },{
                     itemId:'tt'
                    ,text: this.viewer.gridNow.szToggleTimer
                    ,iconCls: 'timer-toggle-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.ToggleTimer(this.ctxRecord); }
                    },{
                     itemId:'td'
                    ,text: this.viewer.gridNow.szDeleteTimer
                    ,iconCls: 'timer-delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteTimer(this.ctxRecord); }
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
        var timerid = this.ctxRecord.data.timerid;
        var items = this.menu.items;
        if(items) { items.eachKey(function(key, f) { 
                      if(f.itemId == 'tn') { if(timerid) f.hide(); else f.show(); }
                      else if(f.itemId == 'te') { if(timerid) f.show(); else f.hide(); }
                      else if(f.itemId == 'tt') { if(timerid) f.show(); else f.hide(); }
                      else if(f.itemId == 'td') { if(timerid) f.show(); else f.hide(); }
                      if(XXV.help.cmdAllowed(f.itemId)) 
                        f.enable();
                      },items); 
                  }

        this.menu.showAt(e.getXY());
    }

    ,onContextHide : function(){
        if(this.ctxRow){
            Ext.fly(this.ctxRow).removeClass('x-node-ctx');
            this.ctxRow = null;
        }
        if(this.menu) {
          this.menu.destroy();
          delete this.menu;
          this.menu = null;
        }
    }

    ,reload : function(data) {
        if(this.filter.field.isValid()) {
          this.filter.field.setValue('');
        }
        this.store.baseParams = {
             cmd: 'p'
            ,data: data.id
        };
        this.store.title = data.name;
        this.store.load({params:{start:0, limit:configuration.pageSize}});
    }
    ,Record : function( record ) {
      var gsm = this.getSelectionModel();
      var sel = gsm.getSelections();
      if(sel.length <= 0) {
       gsm.selectRecords([record]);
       sel.push(record);
      }
      var ids = "";
      for(var i = 0, len = sel.length; i < len; i++){
        if(i !== 0)
           ids += ',';
           ids += sel[i].data.id;
      }
      this.viewer.RecordID(ids, this.updateTimer, this);
    }
    ,updateTimer : function() {
      var gsm = this.getSelectionModel();
      if(gsm.hasSelection()) {
        this.view.keepSelection = new Array();
        for(var i = 0, len = this.store.getCount(); i < len; i++){
          if(gsm.isSelected(i)) {
            this.view.keepSelection.push(i);
          }
        }
      }
      this.store.reload();
      if(this.viewer.gridTimer) {
        this.viewer.gridTimer.dataDirty = true;
      }
    }
    ,EditTimer : function(record) {
        this.viewer.gridNow.EditTimer(record, this.updateTimer, this);
    }
    ,SelectedTimer : function(record) {
        var gsm = this.getSelectionModel();
        var sel = gsm.getSelections();
        if(sel.length <= 0) {
         gsm.selectRecords([record]);
         sel.push(record);
        }
        var items = "";
        for(var i = 0, len = sel.length; i < len; i++){
          if(i)
            items += ',';
          if(!sel[i].data.timerid) {
            continue;
          }
          items += sel[i].data.timerid;
        }
        return items;
    }
    ,ToggleTimer : function(record) {
        this.viewer.gridNow.ToggleTimerId(this.SelectedTimer(record), this.store);
    }
    ,DeleteTimer : function(record) {
        this.viewer.gridNow.DeleteTimerId(this.SelectedTimer(record), this.store);
    }
});

Ext.xxv.programPreview = function(viewer,store) {
    return new Ext.xxv.EPGPreview(viewer,store, {
        id: 'program-preview',
        region: 'south',
        cls:'preview',
        autoScroll: true,
        stateful:false,
        tbar: [ {
            id:'s',
            tooltip: Ext.xxv.NowGrid.prototype.szFindReRun,
            iconCls: 'find-icon',
            disabled:true,
            scope: viewer,
            handler: function(){ this.searchTab(this.gridProgram.getSelectionModel().getSelected()); }
        } ,{
            id:'tn',
            tooltip: Ext.xxv.NowGrid.prototype.szRecord,
            iconCls: 'record-icon',
            disabled:true,
            scope: viewer,
            handler: function(){ this.Record(this.gridProgram.getSelectionModel().getSelected()); }
        },{
            id:'te',
            tooltip: Ext.xxv.NowGrid.prototype.szEditTimer,
            iconCls: 'timer-edit-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridProgram.EditTimer(this.gridProgram.getSelectionModel().getSelected()); 
            }
        },{
            id:'tt',
            tooltip: Ext.xxv.NowGrid.prototype.szToggleTimer,
            iconCls: 'timer-toggle-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridProgram.ToggleTimer(this.gridProgram.getSelectionModel().getSelected()); 
            }
        },{
            id:'td',
            tooltip: Ext.xxv.NowGrid.prototype.szDeleteTimer,
            iconCls: 'timer-delete-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridProgram.DeleteTimer(this.gridProgram.getSelectionModel().getSelected()); 
            }
        } ]
    });
};

function createProgramView(viewer,id, record) {

    viewer.gridProgram = new Ext.xxv.programGrid(viewer, record);

    var tab = new Ext.xxv.Panel({
            id:id,
            iconCls: 'channel-icon',
            layout:'border',
            stateful:true,
            closable:true,
            items:[
                viewer.gridProgram,
            {
                id:'program-bottom-preview',
                layout:'fit',
                items:XXV.BottomPreview ? 0 : viewer.gridProgram.preview,
                height: 250,
                split: true,
                border:false,
                region:'south',
                hidden:XXV.BottomPreview
            }, {
                id:'program-right-preview',
                layout:'fit',
                items:XXV.RightPreview ? 0 : viewer.gridProgram.preview,
                border:false,
                region:'east',
                width:350,
                split: true,
                hidden:XXV.RightPreview
            }]
    });

    viewer.add(tab);
    return tab;
}
