/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.usersStore = function() {

    // create the data store
    return new Ext.data.Store({
             baseParams:{cmd:'ul'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                      {name: 'id', type: 'int'},
                      {name: 'title', type: 'string'},
                      {name: 'level', type: 'string'},
                      {name: 'preferences', type: 'string'},
                      {name: 'userpreferences', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'title', direction:'ASC'}
    });
};

Ext.xxv.usersGrid = function(viewer) {
    this.viewer = viewer;
    //Ext.apply(this, {}); // Apply config

    // create the data store
    this.store = new Ext.xxv.usersStore();
    this.store.setDefaultSort('title', "ASC");

    this.columns = [
        {
           header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 200
        },
        {           header: this.szColLevel
           ,dataIndex: 'level'
           ,width: 200
        },
        {           header: this.szUserPreferences
           ,dataIndex: 'userpreferences'
           ,width: 400
           ,hidden: true
        },
        {           header: this.szAdminPreferences
           ,dataIndex: 'preferences'
           ,width: 400
           ,hidden: true
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;

    Ext.xxv.usersGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'users-view-grid'
        ,loadMask: true
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
                   id:'un'
                  ,iconCls: 'new-icon'
                  ,tooltip: this.szNew
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

Ext.extend(Ext.xxv.usersGrid,  Ext.grid.EditorGridPanel, {

     szTitle         : "User accounts"
    ,szNew           : "Create new account"
    ,szEdit          : "Edit"
    ,szDelete        : "Delete"
    ,szColTitle      : "Account"
    ,szColLevel      : "Level"
    ,szUserPreferences:"User Preferences"
    ,szAdminPreferences:"Preferences"
    ,szLoadException : "Couldn't get data about user accounts!\r\n{0}"
    ,szDeleteSuccess : "User account deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete user account!\r\n{0}"
 
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
                     itemId:'ue'
                    ,text:  this.szEdit
                    ,iconCls: 'edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditItem(this.ctxRecord); }
                   },{
                     itemId:'ud'
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
         ,url: XXV.help.cmdAJAX('ud')
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
           cmd:   'ue'
          ,id:    record.data.id
          ,title: record.data.title
        };
      } else {
        item = {
           cmd:   'un'
          ,id:    0
          ,title: this.szNew
        };
      }

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this);
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

function createUsersView(viewer,id) {

    viewer.gridusers = new Ext.xxv.usersGrid(viewer);
  
    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"users-icon",
      closable:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[
            viewer.gridusers
            ]
    });


    viewer.add(tab);

    return tab;
}

