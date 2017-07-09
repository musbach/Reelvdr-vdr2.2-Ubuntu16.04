/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.vdrStore = function() {

    // create the data store
    return new Ext.data.Store({
             baseParams:{cmd:'vl'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                      {name: 'id', type: 'int'},
                      {name: 'active', type: 'int', convert: function(x) { if(x == 'y'){ return 1;} else {return 0;} }},
                      {name: 'primary', type: 'int', convert: function(x) { if(x == 'y'){ return 1;} else {return 0;} }},
                      {name: 'host', type: 'string'},
                      {name: 'dvbtyp', type: 'string'},
                      {name: 'directory', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'host', direction:'ASC'}
    });
};

Ext.xxv.vdrGrid = function(viewer) {
    this.viewer = viewer;
    //Ext.apply(this, {}); // Apply config

    // create the data store
    this.store = new Ext.xxv.vdrStore();
    this.store.setDefaultSort('host', "ASC");

    // custom columns as plugins
    this.activeColumn = new Ext.grid.CheckColumn({
       header: this.szColActive
       ,dataIndex: 'active'
       ,width: 50
       ,bitmask: 1
       ,editable: false
       ,hidden: true
    });
    this.primaryColumn = new Ext.grid.CheckColumn({
       header: this.szColPrimary
       ,dataIndex: 'primary'
       ,width: 50
       ,bitmask: 1
       ,editable: false
       ,hidden: true
    });

    this.columns = [
        {
           header: this.szColHost
           ,dataIndex: 'host'
           ,width: 200
           ,renderer: this.formatTitle
        },
        this.activeColumn,
        this.primaryColumn,
        {           header: this.szColDirectory
           ,dataIndex: 'directory'
           ,width: 200
           ,renderer: this.formatTitle
        },{
           header: this.szDVBTyp
           ,dataIndex: 'dvbtyp'
           ,width: 200
           ,renderer: this.formatTitle
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;

    Ext.xxv.vdrGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'vdr-view-grid'
        ,loadMask: true
        ,plugins:[this.activeColumn,this.primaryColumn]
        ,clicksToEdit:1
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:false
        })
        ,tbar:new Ext.PagingToolbar({
              pageSize: this.store.autoLoad.params.limit
              ,store: this.store
              ,displayInfo: true 
              ,items: [
              {
                   id:'vn'
                  ,iconCls: 'new-icon'
//                ,text: this.szNew
                  ,scope: this
                  ,disabled:false
                  ,handler: function(){ this.EditItem(null); }
              }
              ]})
    });

    this.store.on({
         'load' : this.onLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });

    this.on('rowcontextmenu', this.onContextClick, this);
    this.on('rowdblclick', this.onEditItem, this);
};

Ext.extend(Ext.xxv.vdrGrid,  Ext.grid.EditorGridPanel, {

     szTitle         : "Video disk recorder"
    ,szNew           : "New"
    ,szEdit          : "Edit"
    ,szDelete        : "Delete"
    ,szColHost       : "Host computer"
    ,szColActive     : "Active"
    ,szColPrimary    : "Primary"
    ,szColDirectory  : "Directory"
    ,szDVBTyp        : "Type of DVB-cards"
    ,szLoadException : "Couldn't get data about video disk recorder!\r\n{0}"
    ,szDeleteSuccess : "Video disk recorder deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete video disk recorder!\r\n{0}"
 
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
                     itemId:'ve'
                    ,text:  this.szEdit
                    ,iconCls: 'edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditItem(this.ctxRecord); }
                   },{
                     itemId:'vd'
                    ,text:  this.szDelete
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
        if((record.data.active & 1) == 0) {
          style = " deactive";
        } else if(record.data.primary) {
          style = " running";
        }

        return String.format(
              '<div class="topic{1}">{0}</div>',
              value, style
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

    ,onDeleteFailure : function( response,options ) 
    { 
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
        if(i)
           todel += ',';
        todel += sel[i].data.id;
      }
      Ext.Ajax.request({
          scope: this
         ,url: XXV.help.cmdAJAX('vd')
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

      if(record) {
        var gsmTimer = this.getSelectionModel();
        gsmTimer.selectRecords([record]);

        item = {
           cmd:   've'
          ,id:    record.data.id
          ,title: record.data.host
        };
      } else {
        item = {
           cmd:   'vn'
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
});

function createVDRView(viewer,id) {

    viewer.gridvdr = new Ext.xxv.vdrGrid(viewer);
  
    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"vdr-icon",
      closable:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[
            viewer.gridvdr
            ]
    });


    viewer.add(tab);

    return tab;
}

