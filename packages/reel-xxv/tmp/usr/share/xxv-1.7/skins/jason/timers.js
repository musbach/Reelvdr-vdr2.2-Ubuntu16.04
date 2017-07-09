/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.timerStore = function() {

    // create the data store
    return new Ext.data.GroupingStore({
             baseParams:{cmd:'tl'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                       {name: 'id', type: 'string'}
                      ,{name: 'flags', type: 'int'}
                      ,{name: 'channel', type: 'string'}
                      ,{name: 'pos', type: 'string'}
                      ,{name: 'day', type:'date', dateFormat:'timestamp'}
                      ,{name: 'start', type: 'string'}
                      ,{name: 'stop', type: 'string'}
                      ,{name: 'title', type: 'string'}
                      ,{name: 'priority', type: 'int'}
                      ,{name: 'collision', type: 'string'}
                      ,{name: 'eventid', type: 'string'}
                      ,{name: 'autotimerid', type: 'int'}
                      ,{name: 'duration', type: 'int'}
                      ,{name: 'description', type: 'string'}
                      ,{name: 'running', type: 'bool'}
                      ,{name: 'host', type: 'string'}
                      //*** filled later by display ***
                      ,{name: 'image', type: 'string'}
                      ,{name: 'audio', type: 'string'}
                      ,{name: 'video', type: 'string'}
                      ,{name: 'contents', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'day', direction:'ASC'}
            ,groupField:'day'
    });
};

Ext.xxv.timerGrid = function(viewer) {

    this.viewer = viewer;
    // create primary data store
    this.store = new Ext.xxv.timerStore();

    this.preview = new Ext.xxv.timerPreview(viewer, this.store);

    this.store.setDefaultSort('day', "ASC");

    // create the channels store
    var channels = new Ext.xxv.storeChannels();

    // custom columns as plugins
    this.activeColumn = new Ext.grid.CheckColumn({
        header: this.szColActive
       ,dataIndex: 'flags'
       ,width: 50
       ,bitmask: 1
       ,editable: false
       ,hidden: true
    });
    this.vpsColumn = new Ext.grid.CheckColumn({
       header: this.szColPDC
       ,dataIndex: 'flags'
       ,width: 50
       ,bitmask: 4
       ,editable: false
       ,hidden: false
    });

    this.ChannelsCombo = new Ext.xxv.ChannelsCombo({
           header: this.szColChannel,
           dataIndex: 'pos',
           width: 200,
           store: channels,
           editor: new Ext.form.ComboBox({
                tpl: new Ext.XTemplate('<tpl for=".">',
                            '<tpl if="this.isNewGroup(grpname)"><div class="x-combo-list-hd">{grpname}</div></tpl>',
                            '<div class="x-combo-list-item">{name}</div>',
                            '</tpl>', { 
                          isNewGroup: function(grpname){
                              if(!this.lastgroups || grpname != this.lastgroups) { this.lastgroups = grpname; return 1; }
                              return 0;
                           }
                        }),
                store: channels,
                displayField:'name',
                valueField:'position',
                triggerAction: 'all',
                lazyRender:true,
                listClass: 'x-combo-list-small',
                mode: 'remote',
                emptyText:this.szSelChEmptyText,
                selectOnFocus:true,
                editable: false
            })
        }
    );

    this.columns = [
        {
           id:'expand'
           ,header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 250
           ,renderer: this.formatTitle
        },
        this.activeColumn,
        this.vpsColumn,
        this.ChannelsCombo,
        {
            header: this.szColDay
           ,dataIndex: 'day'
           ,width: 50
           ,renderer: Ext.util.Format.dateRenderer(this.szColDayFormat)
           ,hidden: true
        },{
            header: this.szColStart
           ,dataIndex: 'start'
           ,width: 50
        },{
            header: this.szColStop
           ,dataIndex: 'stop'
           ,width: 50
        },{
            header: this.szColDuration
           ,dataIndex: 'duration'
           ,width: 50
           ,renderer: this.formatDuration
        },{
            header: this.szHost
           ,dataIndex: 'host'
           ,width: 190
           ,hidden: true
        }
    ];
    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = false;
    this.filter = new Ext.ux.grid.Search({
             position:'top'
            ,shortcutKey:null
            ,paramNames: {
                    fields:'cmd'
                    ,all:'tl'
                    ,cmd:'ts'
                    ,query:'data'
                }
        });

    Ext.xxv.timerGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'timer-view-grid'
        ,loadMask: false
        ,plugins:[this.activeColumn,this.vpsColumn,this.ChannelsCombo,this.filter]
        ,clicksToEdit:1
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
              pageSize: this.store.autoLoad.params.limit
              ,store: this.store
              ,displayInfo: true 
              ,items: [
              {
                   id:'tn'
                  ,iconCls: 'timer-new-icon'
                  ,tooltip: this.szNew
                  ,scope: this
                  ,disabled:false
                  ,handler: function(){ this.EditItem(null); }
              }
              ]})
    });

    this.store.on({
         'load' : this.onLoad
        ,'beforeload'    : this.onBeforeLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });
    this.on('rowcontextmenu', this.onContextClick, this);
    this.on('rowdblclick', this.onEditItem, this);
    this.getSelectionModel().on('rowselect', this.showDetails, this, {buffer:50});
};

Ext.extend(Ext.xxv.timerGrid,  Ext.grid.GridPanel, { // Ext.grid.EditorGridPanel

     szTitle         : "Timer"
    ,szFindReRun     : "Find rerun"
    ,szNew           : "Create new timer"
    ,szEdit          : "Edit timer"
    ,szDelete        : "Delete timer"
    ,szToggle        : "Enable or disable"
    ,szColTitle      : "Title"
    ,szColActive     : "Active"
    ,szColPDC        : "PDC"
    ,szColDay        : "Day"
    ,szColChannel    : "Channel"
    ,szColStart      : "Start"
    ,szColStop       : "Stop"
    ,szColDuration   : "Duration"
    ,szHost          : "Host"
    ,szColDayFormat  : "l, m/d/Y"
    ,szSelChEmptyText: "Select a channel..."
    ,szLoadException : "Couldn't get data about timer!\r\n{0}"
    ,szDeleteSuccess : "Timer deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete timer!\r\n{0}"
    ,szToggleSuccess : "Timer toggled successful.\r\n{0}"
    ,szToggleFailure : "Couldn't toggle timer!\r\n{0}"

    ,stateful:  true
    ,dataDirty: false
    ,onLoadException :  function( scope, o, arg, e) {
      this.dataDirty = false;
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onBeforeLoad : function(  store, opt ) {
      this.preview.clear();
    }
    ,onLoad : function( store, records, opt ) {
      this.dataDirty = false;

      if(this.view.keepSelection)
        this.getSelectionModel().selectRows(this.view.keepSelection,false);
      else
        this.getSelectionModel().selectFirstRow();

      this.ownerCt.SetPanelTitle(this.szTitle);
    }
    ,showDetails : function(sm, index, record){
      this.preview.showDetails(record, record.data.eventid, this.filter.getValue());
    }
    ,refreshPanel : function(panel){
      if(this.dataDirty)
        this.store.reload();
    }
    ,onContextClick : function(grid, index, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [{
                     itemId:'te'
                    ,text: this.szEdit
                    ,iconCls: 'edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditItem(this.ctxRecord); }
                   },{
                     itemId:'tt'
                    ,text: this.szToggle
                    ,iconCls: 'timer-toggle-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.ToggleItem(this.ctxRecord); }
                   },{
                     itemId:'td'
                    ,text: this.szDelete
                    ,iconCls: 'timer-delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteItem(this.ctxRecord); }
                   },'-',{
                     itemId:'ae'
                    ,text: Ext.xxv.autotimerGrid.prototype.szEdit
                    ,iconCls: 'autotimer-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditAutoTimerItem(this.ctxRecord); }
                   },{
                     itemId:'s'
                    ,text: this.szFindReRun
                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.viewer.searchTab(this.ctxRecord);}
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

        var hasAutotimer = (this.ctxRecord.data.autotimerid <= 0) ? 0 : 1;
        var items = this.menu.items;
        if(items) { items.eachKey(function(key, f) {
                      if(f.itemId == 'ae') { if(hasAutotimer) f.show(); else f.hide(); }
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
    ,formatTitle: function(value, p, record) {
        var Woerter = value.split("~");
        var title = Woerter[0];
        var subtitle = '';
        for(var i = 1, len = Woerter.length; i < len; i++){
          if(subtitle.length) {
            subtitle += '~';
          }
          subtitle += Woerter[i];
        }
        var style = "";
        if((record.data.flags & 1) == 0) {
          style = " deactive";
        } else if(record.data.collision != '0') {
          style = " problem";
        } else if(record.data.running) {
          style = " running";
        }
        if(subtitle) {
          return String.format(
                '<div class="topic{2}"><b>{0}</b> <span class="subtitle{2}">{1}</span></div>',
                title, subtitle, style
                );
        }
        return String.format(
              '<div class="topic{1}"><b>{0}</b></div>',
              title, style
              );
    }
    ,formatDuration: function(value, p, record) {
        return new Date(minTime().getTime()+(value * 1000)).dateFormat('H:i');
    }
/******************************************************************************/
   ,onToggleSuccess : function( response,options ) {
        this.viewer.loadMask.hide(); 

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'object' 
             && o.param && o.param.state && o.param.state == 'success' ) {
            new Ext.xxv.MessageBox().msgSuccess(this.szToggleSuccess,'');
            //{ "data" : [ [ ID, ON, RUN, CONFLICT ], .... ] }
            for (var i = 0; i < o.data.length; i++) {
              var x = o.data[i];
              if(x.length != 4 || !x[0]) {
                continue;
              }
              var record = this.store.getById(x[0]);
              if(!record) {
                continue;
              }
              if(x[1] != '0') 
                    record.data.flags |= 1;
              else
                    record.data.flags &= ~1;
              if(x[2] != '0') 
                    record.data.running = 1;
              else
                    record.data.running = 0;
              record.data.collision = x[3];
              record.commit();
            }
        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szToggleFailure, msg);
        }
    }

    ,onToggleFailure : function( response,options ) {
        this.viewer.loadMask.hide();
        new Ext.xxv.MessageBox().msgFailure(this.szToggleFailure, response.statusText);
    }

    ,ToggleItem : function( record ) {
      this.stopEditing();
      this.viewer.loadMask.show(); 

      var gsm = this.getSelectionModel();
      var sel = gsm.getSelections();
      if(sel.length <= 0) {
       gsm.selectRecords([record]);
       sel.push(record);
      }
      var todo = "";
      for(var i = 0, len = sel.length; i < len; i++){
        if(i)
          todo += ',';
          todo += sel[i].data.id;
      }
      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('tt')
         ,timeout: 15000
         ,success: this.onToggleSuccess
         ,failure: this.onToggleFailure
         ,params:{ data: todo }
      });
    }
  /******************************************************************************/
    ,onDeleteSuccess : function( response,options ) { 
        this.viewer.loadMask.hide(); 

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szDeleteSuccess, o.data);

            var gsm = this.getSelectionModel();
            var sel = options.params.data.split(",");
            sel.reverse();
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
        this.viewer.loadMask.hide();
        new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, response.statusText);
    }

    ,DeleteItem : function( record ) {
      this.stopEditing();
      this.viewer.loadMask.show(); 

      var gsm = this.getSelectionModel();
      var sel = gsm.getSelections();
      if(sel.length <= 0) {
       gsm.selectRecords([record]);
       sel.push(record);
      }
      var todel = "";
      for(var i = 0, len = sel.length; i < len; i++){
        if(i)
          todel += ',';
        todel += sel[i].data.id;
      }
      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('td')
         ,timeout: 15000
         ,success: this.onDeleteSuccess
         ,failure: this.onDeleteFailure
         ,params:{ data: todel }
      });
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
    }
    ,EditItem : function( record ) {
      this.stopEditing();
      var item;

      if(record) {
        var gsmTimer = this.getSelectionModel();
        gsmTimer.selectRecords([record]);

        item = {
           cmd:   'te'
          ,id:    record.data.id
          ,title: record.data.title
        };
      } else {
        item = {
           cmd:   'tn'
          ,id:    0
          ,title: this.szNew
        };
      }

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item, this.updateTimer, this);
    }
    ,onEditItem : function(grid, index, e) {
      e.stopEvent();
      if(this.ctxRow){
          Ext.fly(this.ctxRow).removeClass('x-node-ctx');
          this.ctxRow = null;
      }
      var record = this.store.getAt(index);
      this.EditItem(record);
    }
    ,EditAutoTimerItem : function( record ) {
      this.stopEditing();
      var item;

      if(record) {
        var gsmTimer = this.getSelectionModel();
        gsmTimer.selectRecords([record]);

        item = {
           cmd:   'ae'
          ,id:    record.data.autotimerid
          ,title: record.data.title
        };
      } else {
        return;
      }

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item, this.updateTimer, this);
    }
});

Ext.xxv.timerPreview = function(viewer,store) {
    return new Ext.xxv.EPGPreview(viewer,store, {
        id: 'preview-timer',
        region: 'south',
        cls:'preview',
        autoScroll: true,
        stateful:false,
        tbar: [ 
       {
             id:'s'
            ,iconCls: 'find-icon'
            ,tooltip: Ext.xxv.timerGrid.prototype.szFindReRun
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.searchTab(this.gridTimer.getSelectionModel().getSelected()); }
        },{
             id:'te'
            ,iconCls: 'edit-icon'
            ,tooltip: Ext.xxv.timerGrid.prototype.szEdit
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridTimer.EditItem(this.gridTimer.getSelectionModel().getSelected()); }
        },{
             id:'ae'
            ,iconCls: 'autotimer-icon'
            ,tooltip: Ext.xxv.autotimerGrid.prototype.szEdit
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridTimer.EditAutoTimerItem(this.gridTimer.getSelectionModel().getSelected()); }
        },{
             id:'td'
            ,iconCls: 'timer-delete-icon'
            ,tooltip: Ext.xxv.timerGrid.prototype.szDelete
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridTimer.DeleteItem(this.gridTimer.getSelectionModel().getSelected()); }
        } ]
    });
};

function createTimerView(viewer,id) {

    viewer.gridTimer = new Ext.xxv.timerGrid(viewer);

    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"timer-icon",
      closable:true,
      autoScroll:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[
            viewer.gridTimer,
            {
              id:'timer-bottom-preview',
              layout:'fit',
              items:XXV.BottomPreview ? 0 : viewer.gridTimer.preview,
              height: 250,
              split: true,
              border:false,
              region:'south',
              hidden:XXV.BottomPreview
            }, {
              id:'timer-right-preview',
              layout:'fit',
              items:XXV.RightPreview ? 0 : viewer.gridTimer.preview,
              border:false,
              region:'east',
              width:350,
              split: true,
              hidden:XXV.RightPreview
            }
            ]
      ,listeners: { 
            activate: function(p){
                viewer.gridTimer.refreshPanel(p); 
           }
        }
    });

    viewer.add(tab);
    return tab;
}

