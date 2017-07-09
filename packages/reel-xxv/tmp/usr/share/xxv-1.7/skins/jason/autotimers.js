/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.autotimerStore = function() {

    // create the data store
    return new Ext.data.Store({
             baseParams:{cmd:'al'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                      {name: 'id', type: 'int'},
                      {name: 'active', type: 'int', convert: function(x) { if(x == 'y'){ return 1;} else {return 0;} }},
                      {name: 'title', type: 'string'},
                      {name: 'channels', type: 'string'},
                      {name: 'directory', type: 'string'},
                      {name: 'start', type: 'string'},
                      {name: 'stop', type: 'string'},
                      {name: 'minlength', type: 'int'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'title', direction:'ASC'}
    });
};

Ext.xxv.autotimerGrid = function(viewer, channels) {
    this.viewer = viewer;

    // create the data store
    this.store = new Ext.xxv.autotimerStore();
    this.store.setDefaultSort('title', "ASC");

    // custom columns as plugins
    this.activeColumn = new Ext.grid.CheckColumn({
       header: this.szColActive
       ,dataIndex: 'active'
       ,width: 50
       ,bitmask: 1
       ,editable: false
       ,hidden: true
    });

    this.columns = [
        {
           id:'expand'
           ,header: this.szColSearch
           ,dataIndex: 'title'
           ,width: 200
           ,renderer: this.formatTitle
        },
        this.activeColumn, 
        {  
           header: this.szColChannels
           ,dataIndex: 'channels'
           ,width: 150
        },{
           header: this.szColDirectory
           ,dataIndex: 'directory'
           ,width: 250
        },{
           header: this.szColStart
           ,dataIndex: 'start'
           ,width: 50
        },{
           header: this.szColStop
           ,dataIndex: 'stop'
           ,width: 50
        },{
           header: this.szColMinLength
           ,dataIndex: 'minlength'
           ,width: 50
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;

    Ext.xxv.autotimerGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'autotimer-view-grid'
        ,loadMask: true
        ,clicksToEdit:1
        ,autoExpandColumn:'expand'
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:false
        })
        ,tbar:new Ext.PagingToolbar({
              pageSize: this.store.autoLoad.params.limit
              ,store: this.store
              ,displayInfo: true 
              ,items: [{
                   id:'au'
                  ,iconCls: 'upgrade-icon'
                  ,tooltip: this.szUpgrade
                  ,scope: this
                  ,disabled:false
                  ,handler: function(){ this.UpgradeItem(); }
              },{
                   id:'an'
                  ,iconCls: 'new-icon'
                  ,tooltip: this.szNew
                  ,scope: this
                  ,disabled:false
                  ,handler: function(){ this.EditItem(null); }
              }
              ]})
        ,plugins:[this.activeColumn,
                  new Ext.ux.grid.Search({
                   position:'top'
                  ,shortcutKey:null
                  ,paramNames: {
                          fields:'cmd'
                          ,all:'al'
                          ,cmd:'ase'
                          ,query:'data'
                      }
        })]
    });

    this.store.on({
         'load' : this.onLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });

    this.on('rowcontextmenu', this.onContextClick, this);
    this.on('rowdblclick', this.onEditItem, this);
};

Ext.extend(Ext.xxv.autotimerGrid,  Ext.grid.EditorGridPanel, {

     szTitle         : "Search timer"
    ,szFindReRun     : "Find rerun"
    ,szNew           : "Create new search timer"
    ,szEdit          : "Edit search timer"
    ,szDelete        : "Delete search timer"
    ,szColSearch     : "Search text"
    ,szColActive     : "Active"
    ,szColChannels   : "Channels"
    ,szColDirectory  : "Directory"
    ,szColStart      : "Start"
    ,szColStop       : "Stop"
    ,szColMinLength  : "Min. Length"
    ,szLoadException : "Couldn't get data about autotimer!\r\n{0}"
    ,szDeleteSuccess : "Autotimer deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete autotimer!\r\n{0}"
    ,szUpgrade        : "Lookup for wanted events"
    ,szUpgradeWait    : "Please wait..."
    ,szUpgradeSuccess : "Lookup for wanted events successful.\r\n{0}"
    ,szUpgradeFailure : "Couldn't lookup for wanted events!\r\n{0}"

    ,stateful:  true

    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onLoad : function( store, records, opt ) {
      this.getSelectionModel().selectFirstRow();
      this.ownerCt.SetPanelTitle(this.szTitle);
    }
    ,onContextClick : function(grid, index, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [{
                     itemId:'ae'
                    ,text:  this.szEdit
                    ,iconCls: 'edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditItem(this.ctxRecord); }
                   },{
                     itemId:'ad'
                    ,text:  this.szDelete
                    ,iconCls: 'delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteItem(this.ctxRecord); }
                  },'-',{
                     itemId:'s'
                    ,text:  this.szFindReRun
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

        var items = this.menu.items;
        if(items) { items.eachKey(function(key, f) {
                      if(XXV.help.cmdAllowed(f.itemId)) {  
                         f.enable(); 
                         }
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
        var style = "";
        if((record.data.active & 1) === 0) {
          style = " deactive";
        }
        return String.format(
              '<div class="topic{1}"><b>{0}</b></div>',
              value, style
              );
    }
/******************************************************************************/
    ,onDeleteSuccess : function( response,options ) { 
        this.loadMask.hide(); 

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
        if(i !== 0) {
          todel += ',';
        }
        todel += sel[i].data.id;
      }
      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('ad')
         ,timeout: 15000
         ,success: this.onDeleteSuccess
         ,failure: this.onDeleteFailure
         ,params:{ data: todel }
      });
    }

/******************************************************************************/
    ,EditItem : function( record ) {
      this.stopEditing();
      var item;

      if(record !== null) {
        var gsmTimer = this.getSelectionModel();
        gsmTimer.selectRecords([record]);

        item = {
           cmd:   'ae'
          ,id:    record.data.id
          ,title: record.data.title
        };
      } else {
        item = {
           cmd:   'an'
          ,id:    0
          ,title: this.szNew
        };
      }

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this.store);
    },
    onEditItem : function(grid, index, e) {
      e.stopEvent();
      if(this.ctxRow){
          Ext.fly(this.ctxRow).removeClass('x-node-ctx');
          this.ctxRow = null;
      }
      var record = this.store.getAt(index);
      this.EditItem(record);
    }
/******************************************************************************/
    ,onUpgradeSuccess : function( response,options ) 
    { 
        Ext.MessageBox.hide();
        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szUpgradeSuccess, o.data);
            this.updateTimer();
        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szUpgradeFailure, msg);
        }
    }
    ,onUpgradeFailure : function( response,options ) 
    { 
        Ext.MessageBox.hide();
        new Ext.xxv.MessageBox().msgFailure(this.szUpgradeFailure, response.statusText);
    }
    ,UpgradeItem : function() {
      Ext.Ajax.request({
        scope: this
       ,url: XXV.help.cmdAJAX('au')
       ,timeout: 120000
       ,success: this.onUpgradeSuccess
       ,failure: this.onUpgradeFailure
      });

      Ext.MessageBox.show({
           title: this.szUpgradeWait
           ,msg: this.szUpgrade
           ,width:240
           ,wait:true
           ,waitConfig:{
              interval:200
            ,duration:119000
            ,increment:15
            ,fn:function() {
                    Ext.MessageBox.hide();
              }
           }
       });
    }
    ,updateTimer : function() {
      if(this.viewer.gridTimer) {
        this.viewer.gridTimer.dataDirty = true;
      }
    }
});

function createAutoTimerView(viewer,id) {

    viewer.gridAutoTimer = new Ext.xxv.autotimerGrid(viewer, viewer.storeChannels);
  
    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"autotimer-icon",
      closable:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[
            viewer.gridAutoTimer
            ]
    });

    viewer.add(tab);
    return tab;
}

