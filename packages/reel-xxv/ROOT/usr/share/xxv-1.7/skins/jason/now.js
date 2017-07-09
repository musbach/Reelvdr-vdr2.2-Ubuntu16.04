/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.NowStore = function() {
    return new Ext.data.GroupingStore({
             baseParams:{cmd:'n','__cgrp':'all'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                          fields: [
                                     {name: 'id', type: 'string'}
                                    ,{name: 'title', type: 'string'}
                                    ,{name: 'subtitle', type: 'string'}
                                    ,{name: 'channel', type: 'string'}
                                    ,{name: 'chid', type: 'string'}
                                    ,{name: 'grpname', type: 'string'}
                                    ,{name: 'start', type: 'string' }
                                    ,{name: 'stop', type: 'string' }
                                    ,{name: 'description', type: 'string'}
                                    ,{name: 'prozent', type: 'string'}
                                    ,{name: 'timerid', type: 'string'}
                                    ,{name: 'timeractiv', type: 'string'}
                                    ,{name: 'running', type: 'string'}
                                    ,{name: 'vps', type: 'string'} //type:'date', dateFormat:'timestamp'}
                                    ,{name: 'level', type: 'int'}
                                    ,{name: 'order', type: 'int'} //dummy field created after onload
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
            ,groupOnSort:false
            ,sortInfo:{field:'order', direction:'ASC'}
            ,groupField:'grpname'
            ,remoteGroup:true
            ,hasMultiSort:false
            ,multiSortInfo:{}
    });
};

Ext.xxv.NowGrid = function(viewer) {

    this.viewer = viewer;
    // create the data store
    this.store = new Ext.xxv.NowStore();

    this.preview = new Ext.xxv.NowPreview(viewer, this.store);

    var range = new Array();
    range.push([this.szPresent,0]);
    range.push([this.szFollowing,this.szFollowing]);
    for(var i = 0, len = configuration.periods.length; i < len; i++){
      range.push([configuration.periods[i],configuration.periods[i]]);
    }

    this.timefield = new Ext.form.ComboBox({
                id:'timefield'
                ,width:75
                ,store: new Ext.data.Store({
                    reader: new Ext.data.ArrayReader({}, [{name: 'display'},{name: 'value'} ]),
                    data: range
                })
                ,displayField:'display'
                ,valueField:'value'
                ,triggerAction: 'all'
                ,lazyRender:true
                ,listClass: 'x-combo-list-small'
                ,mode: 'local'
                ,emptyText:this.szPresent
                ,selectOnFocus:false
                ,editable: true
                ,maskRe: /^([0-9\:]+)$/
                ,regex: new RegExp("^([0-9]+\:[0-9]+)|("+this.szFollowing+")$")
                ,maxLengthText: 5
                ,listeners: {
                  'select': {fn:this.reload, scope:this}
                 ,'specialkey': {fn:this.onSpecialkey, scope:this}
                }
            });

    this.columns = [
        {
           header: this.szColPosition,
           dataIndex: 'order',
           width: 20,
           hidden: true
        },{
           id:'expand'
           ,header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 150
           ,renderer: { fn: this.formatTitle, scope: this }
        },{
           header: this.szColChannel,
           dataIndex: 'channel',
           width: 50
        },{
           header: this.szColGrpName,
           dataIndex: 'grpname',
           width: 50,
           hidden: true
        },{
           header: this.szColStart,
           dataIndex: 'start',
           width: 50
        },{
           header: this.szColStop,
           dataIndex: 'stop',
           width: 50
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;

    Ext.xxv.NowGrid.superclass.constructor.call(this, {
        region: 'center'
        ,id: 'now-grid'
        ,loadMask: false
        ,autoExpandColumn:'expand'
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:true
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
    });

    var tbPosition = 15;
    var tb = this.topToolbar;
    tb.insert(tbPosition+0, '-');
    tb.insert(tbPosition+1, this.timefield);

    this.store.on({
         'load' :          this.onLoad
        ,'beforeload'    : this.onBeforeLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });

    this.on('rowcontextmenu', this.onContextClick, this);
    this.getSelectionModel().on('rowselect', this.showDetails, this, {buffer:50});
    this.on('rowdblclick', this.onSelectProgram, this);
};

Ext.extend(Ext.xxv.NowGrid, Ext.grid.GridPanel, {

     szTitle         : "Program guide"
    ,szPresent       : "Present"
    ,szFollowing     : "Following"
    ,szFindReRun     : "Find rerun"
    ,szProgram       : "Show program"
    ,szRecord        : "Record"
    ,szEditTimer     : "Edit timer"
    ,szToggleTimer   : "Enable or disable timer"
    ,szDeleteTimer   : "Delete timer"
    ,szColPosition   : "Channel position"
    ,szColTitle      : "Title"
    ,szColChannel    : "Channel"
    ,szColGrpName    : "Group of channel"
    ,szColStart      : "Start"
    ,szColStop       : "Stop"
    ,szLoadException : "Couldn't get data!\r\n{0}"
    ,szRecordSuccess : "Timer created successful.\r\n{0}"
    ,szRecordFailure : "Couldn't create timer!\r\n{0}"
    ,szToggleFailure : "Couldn't modify timer!\r\n{0}"
    ,szDeleteSuccess : "Timer deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete timer!\r\n{0}"
    ,szDetailsFailure : "Couldn't update details of event!\r\n{0}"

    ,onLoadException :  function( scope, o, arg, e) {
      var msg = '';
      if(e && e.message && typeof(e.message) == 'string') {
        msg = e.message;
      }
      else if(o && o.data && typeof(o.data) == 'string') {
        msg = o.data;
      }
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, msg);
    }
    ,onBeforeLoad : function(  store, opt ) {
      this.preview.clear();
    }
    ,onLoad : function( store, records, opt ) {
      if(this.view.keepSelection)
        this.getSelectionModel().selectRow(this.view.keepSelection[0],false);
      else
        this.getSelectionModel().selectFirstRow();

      if(store.baseParams.data
        && store.baseParams.cmd != 'nx'
        && store.reader.meta 
        && store.reader.meta.param 
        && store.reader.meta.param.zeit) {
        var datum = new Date(store.reader.meta.param.zeit * 1000);
        this.ownerCt.SetPanelTitle(datum.dateFormat('l - H:i'));
      } else if(store.baseParams.cmd == 'nx')
        this.ownerCt.SetPanelTitle(this.szFollowing + " - " + new Date().dateFormat('H:i'));
      else
        this.ownerCt.SetPanelTitle(this.szPresent + " - " + new Date().dateFormat('H:i'));
    }
    ,showDetails : function(sm, index, record){
        this.preview.showDetails(record, record.data.id, null);
    } 
    ,onSpecialkey : function(f, e) {
      if(e.getKey() == e.ENTER){
          this.reload();
      }
    }
    ,onSelectProgram : function(grid, index, e) {
      e.stopEvent();
      if(this.ctxRow){
          Ext.fly(this.ctxRow).removeClass('x-node-ctx');
          this.ctxRow = null;
      }
      var record = this.store.getAt(index);
      var data = {'id':record.data.chid,'name':record.data.channel};
      this.viewer.openProgram(data); 
    }
/******************************************************************************/
    ,onContextClick : function(grid, index, e){

        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [{
                     itemId:'s'
                    ,text: this.szFindReRun
                    ,iconCls: 'find-icon'
                    ,scope: this
                    ,disabled: true
                    ,handler: function(){ this.viewer.searchTab(this.ctxRecord); }
                    },{
                     itemId:'p'
                    ,text: this.szProgram
                    ,iconCls: 'program-icon'
                    ,scope: this
                    ,disabled: true
                    ,handler: function(){ 
                      var data = {'id':this.ctxRecord.data.chid,'name':this.ctxRecord.data.channel};
                      this.viewer.openProgram(data); }
                    },'-',{
                     itemId:'tn'
                    ,text: this.szRecord
                    ,iconCls: 'record-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.Record(this.ctxRecord); }
                    },{
                     itemId:'te'
                    ,text: this.szEditTimer
                    ,iconCls: 'timer-edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditTimer(this.ctxRecord, this.updateTimer, this); }
                    },{
                     itemId:'tt'
                    ,text: this.szToggleTimer
                    ,iconCls: 'timer-toggle-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.ToggleTimer(this.ctxRecord); }
                    },{
                     itemId:'td'
                    ,text: this.szDeleteTimer
                    ,iconCls: 'timer-delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteTimer(this.ctxRecord, this.store); }
                    },'-',{
                     itemId:'lst'
                    ,iconCls:'stream-icon'
                    ,text: XXV.side.webcastText
                    ,scope: this
                    ,disabled: true
                    ,handler: function(){ XXV.side.onWebCastChannel(this.ctxRecord.data.chid); }
                    },{
                     itemId:'sw'
                    ,iconCls: 'switch-icon'
                    ,text: XXV.side.switchText
                    ,scope: this
                    ,disabled: true
                    ,handler: function(){ XXV.side.onSwitchChannel(this.ctxRecord.data.chid); }
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
        var follow = this.store.baseParams.cmd != 'n' || this.store.baseParams.data; 
        var items = this.menu.items;
        if(items) { items.eachKey(function(key, f) {
                      if(follow) {
                        if(f.itemId == 'lst') 
                          return;
                        if(f.itemId == 'sw') 
                          return;
                      }
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
    ,reload : function() {
        if(this.store.baseParams.data)
          delete(this.store.baseParams.data);

        var time = this.timefield.lastQuery;
        if(!time || time === '') time = this.timefield.getValue();
        if(!time || time === this.szPresent) {
          this.store.baseParams.cmd = 'n';
        } else if(time == this.szFollowing) {
          this.store.baseParams.cmd = 'nx';
        } else {
          this.store.baseParams.cmd = 'n';
          this.store.baseParams.data = time;
        }   
        this.store.load({params:{start:0, limit:configuration.pageSize}});
    }

/******************************************************************************/
    ,onRecordSuccess : function( response,options ) 
    { 
        this.viewer.loadMask.hide();
        var json = response.responseText;
        var o = eval("("+json+")");
        if(!o || !o.data || typeof(o.data) != 'string') {
          throw {message: "Ajax.read: Json message not found"};
        }
        if(o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szRecordSuccess, o.data);
            if(options.callback)
              options.callback.call(options.cbscope);
        } else {
            new Ext.xxv.MessageBox().msgFailure(this.szRecordFailure, o.data);
        }
    }
    ,onRecordFailure : function( response,options ) 
    { 
        this.viewer.loadMask.hide();
        new Ext.xxv.MessageBox().msgFailure(this.szRecordFailure, response.statusText);
    }
    ,Record : function(record) {
        this.RecordID(record.data.id, this.updateTimer, this);
    }
    ,RecordID : function(id, callback, cbscope) {
        this.viewer.loadMask.show();
        Ext.Ajax.request({
              scope:  this
             ,url: XXV.help.cmdAJAX('tn',{ data: id, '__fast':'1' })
             ,success: this.onRecordSuccess
             ,failure: this.onRecordFailure
             ,callback: callback
             ,cbscope:  cbscope
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
      if(this.viewer.gridTimer) {
        this.viewer.gridTimer.dataDirty = true;
      }
    }
    ,EditTimer : function(record,callback,scope) {
      var item;

      if(record.data.timerid) {
        item = {
           cmd:   'te'
          ,id:    record.data.timerid
          ,title: record.data.title
        };
      } else {
        item = {
           cmd:   'tn'
          ,id:    record.data.id
          ,title: this.szEditTimer
        };
      }

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,callback,scope);
    }
    /******************************************************************************/
    ,SelectedTimer : function(record) {
        var gsm = this.getSelectionModel();
        var sel = gsm.getSelections();
        if(sel.length <= 0) {
         gsm.selectRecords([record]);
         sel.push(record);
        }
        var items = "";
        for(var i = 0, len = sel.length; i < len; i++){
          if(i !== 0)
            items += ',';
          if(sel[i].data.timerid === 0) {
            continue;
          }
          items += sel[i].data.timerid;
        }
        return items;
    }
    ,ToggleTimer : function(record) {
        this.ToggleTimerId(this.SelectedTimer(record), this.store);
    }
    ,onToggleSuccess : function( response,options ) 
    { 
        this.viewer.loadMask.hide();

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'object' 
             && o.param && o.param.state && o.param.state === 'success') {

            var items = options.params.data.split(",");
            for (var j = 0, jlen = options.store.getCount(); j < jlen; j++) {
              var record = options.store.getAt(j);
              for(var i = 0, len = items.length; i < len; i++){
                if(!record || record.data.timerid != items[i]) {
                  continue;
                }
                for(var k = 0, klen = o.data.length; k < klen; k++){
                    if(record.data.timerid == o.data[k][0]) {
                        record.data.timeractiv = o.data[k][1];
                        record.data.running = o.data[k][2];
                        //record.data.conflict = o.data[k][3];
                        record.commit();
                        break;
                    }
                 }
              }
            }
            this.updateTimer();
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
    ,ToggleTimerId : function( items,store ) {
      if(items.length <= 0)
        return;
      this.viewer.loadMask.show(); 

      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('tt')
         ,timeout: 15000
         ,success: this.onToggleSuccess
         ,failure: this.onToggleFailure
         ,store:   store
         ,params:{ data: items }
      });
    }
    /******************************************************************************/
    ,onDeleteSuccess : function( response,options ) 
    { 
        this.viewer.loadMask.hide(); 

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szDeleteSuccess, o.data);

            var items = options.params.data.split(",");
            for (var j = 0, jlen = options.store.getCount(); j < jlen; j++) {
              var record = options.store.getAt(j);
              for(var i = 0, len = items.length; i < len; i++){
                if(!record || record.data.timerid != items[i]) {
                  continue;
                }
                record.data.timerid = 0;
                record.commit();
              }
            }
            this.updateTimer();
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
    ,DeleteTimer : function(record) {
        this.DeleteTimerId(this.SelectedTimer(record), this.store);
    }
    ,DeleteTimerId : function( items,store ) {
      if(items.length <= 0)
        return;
      this.viewer.loadMask.show(); 

      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('td')
         ,timeout: 15000
         ,success: this.onDeleteSuccess
         ,failure: this.onDeleteFailure
         ,store:   store
         ,params:{ data: items }
      });
    }

    ,formatTitle: function(value, p, record) {

        var style = "";
        if(record.data.timerid) {
          if(record.data.timeractiv != 1) {
            style = " deactive";
          } else if(record.data.running == 1) {
            style = " running";
          } else {
            style = " active";
          }
        }

        return String.format(
                '<div class="topic{2}"><b>{0}</b> <span class="subtitle">{1}</span></div>'
                , value, record.data.subtitle, style
                );
    }
});

Ext.xxv.NowPreview = function(viewer,store) {
    return new Ext.xxv.EPGPreview(viewer,store, {
        id: 'now-preview',
        region: 'south',
        cls:'preview',
        autoScroll: true,
        stateful:true,
        tbar: [ {
            id:'s',
            tooltip: Ext.xxv.NowGrid.prototype.szFindReRun,
            iconCls: 'find-icon',
            disabled:true,
            scope: viewer,
            handler: function(){ this.searchTab(this.gridNow.getSelectionModel().getSelected()); }
        },{
            id:'tn',
            tooltip: Ext.xxv.NowGrid.prototype.szRecord,
            iconCls: 'record-icon',
            disabled:true,
            scope: viewer,
            handler: function(){ this.gridNow.Record(this.gridNow.getSelectionModel().getSelected()); }
        },{
            id:'te',
            tooltip: Ext.xxv.NowGrid.prototype.szEditTimer,
            iconCls: 'timer-edit-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridNow.EditTimer(this.gridNow.getSelectionModel().getSelected(), this.updateTimer, this); 
            }
        },{
            id:'tt',
            tooltip: Ext.xxv.NowGrid.prototype.szToggleTimer,
            iconCls: 'timer-toggle-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridNow.ToggleTimer(this.gridNow.getSelectionModel().getSelected(), this.updateTimer, this); 
            }
        },{
            id:'td',
            tooltip: Ext.xxv.NowGrid.prototype.szDeleteTimer,
            iconCls: 'timer-delete-icon',
            disabled:true,
            scope: viewer,
            handler: function(){
              this.gridNow.DeleteTimer(this.gridNow.getSelectionModel().getSelected()); 
            }
        } ]
    });
};

function createNowView(viewer,id) {

    viewer.gridNow = new Ext.xxv.NowGrid(viewer);

    var tab = new Ext.xxv.Panel({
            id:id,
            stateful:true,
            iconCls: 'channel-icon',
            layout:'border',
            items:[
                viewer.gridNow,
            {
                id:'now-bottom-preview',
                layout:'fit',
                items:XXV.BottomPreview ? 0 : viewer.gridNow.preview,
                height: 250,
                split: true,
                border:false,
                region:'south',
                hidden:XXV.BottomPreview
            }, {
                id:'now-right-preview',
                layout:'fit',
                items:XXV.RightPreview ? 0 : viewer.gridNow.preview,
                border:false,
                region:'east',
                width:350,
                split: true,
                hidden:XXV.RightPreview
            }]
    });

    return tab;
}
