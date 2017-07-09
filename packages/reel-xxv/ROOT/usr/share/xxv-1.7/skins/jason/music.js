/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.musicStore = function() {

    // create the data store
    return new Ext.data.GroupingStore({
             baseParams:{cmd:'ml',data:'all:1'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                       {name: 'id', type: 'int'}
                      ,{name: 'artist', type: 'string'}
                      ,{name: 'album', type: 'string'}
                      ,{name: 'title', type: 'string'}
                      ,{name: 'track', type: 'int'}
                      ,{name: 'year', type: 'int'}
                      ,{name: 'duration', type: 'string'}
                      ,{name: 'genre', type: 'string'}
                      ,{name: 'comment', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'GET'
            })
            ,sortInfo:{field:'track', direction:'ASC'}
            ,groupField:'album'
    });
};

Ext.xxv.musicGrid = function(viewer) {
    this.viewer = viewer;
    //Ext.apply(this, {}); // Apply config

    // create the data store
    this.store = new Ext.xxv.musicStore();
    this.store.setDefaultSort('track', "ASC");

    this.columns = [
        {
            header: this.szColArtist
           ,dataIndex: 'artist'
           ,width: 200
        },{
            header: this.szColTitle
           ,dataIndex: 'title'
           ,width: 200
           ,id:'expand'
        },{
            header: this.szColAlbum
           ,dataIndex: 'album'
           ,width: 200
           ,hidden: true
        },{
            header: this.szColTrack
           ,dataIndex: 'track'
           ,width: 50
           ,hidden: true
        },{
            header: this.szColYear
           ,dataIndex: 'year'
           ,width: 50
           ,hidden: true
        },{
            header: this.szColDuration
           ,dataIndex: 'duration'
           ,width: 50
        },{
            header: this.szColGenre
           ,dataIndex: 'genre'
           ,width: 100
           ,hidden: true
        },{
            header: this.szColComment
           ,dataIndex: 'comment'
           ,width: 250
           ,hidden: true
        }
    ];

    var cm = new Ext.grid.ColumnModel(this.columns);
    cm.defaultSortable = true;
    this.filter = new Ext.ux.grid.Search({
               position:'top'
              ,shortcutKey:null
              ,paramNames: {
                      fields:'cmd'
                      ,all:'ml'
                      ,defdata:'all:1'
                      ,cmd:'ms'
                      ,query:'data'
                  }
          });
    Ext.xxv.musicGrid.superclass.constructor.call(this, {
         region: 'center'
        ,id: 'music-view-grid'
        ,loadMask: true
        ,clicksToEdit:1
        ,autoExpandColumn:'expand'
        ,cm: cm
        ,sm: new Ext.grid.RowSelectionModel({
            singleSelect:false
        })
        ,view: new Ext.grid.GroupingView({
            enableGroupingMenu:false
            ,showGroupName: false
            //,groupTextTpl: '{text} <img class="coverimage" src="?cmd=mi&data={[values.rs[0].data["id"]]}" />'
        })
        /*,listeners: {
          mouseover: function(e, t) {
             var rowIndex = this.getView().findRowIndex(t); 
             if(rowIndex === false)return;
             var colIndex = this.getView().findCellIndex(t); 
             if(colIndex === false)return;
           
              var row = this.getStore().getAt(rowIndex)
              var id = row.data.id;
              if(this.CoverTransaction) 
                Ext.Ajax.abort(this.CoverTransaction);
              this.DetailsTransaction = Ext.Ajax.request({
                    scope: this
                   ,method: 'HEAD'
                   ,url: XXV.help.cmdHTML('mi',{data:row.data.id})
                   ,timeout: 15000
                   ,success: this.onCoverSuccess
                   ,failure: this.onCoverFailure
                   ,params:{ data: row.data.id }
                });
                if(this.CoverTT) {
                  this.CoverTT.destroy();
                  delete this.CoverTT;
                }
                this.CoverTT = new Ext.ToolTip({
                 target: e.target,
                 title: 'Cover',
                 autoHide: false,
                 closable: true,
                 showDelay:1000,
                 hideDelay:0,
                 autoHeight:true,
                 hidden:true,
                 width:210,
                 html: '<img class="coverimage" src="?cmd=mi&data='+row.data.id +'" />',
                });
          }
        }*/
        ,tbar:new Ext.PagingToolbar({
              pageSize: this.store.autoLoad.params.limit
              ,store: this.store
              ,displayInfo: true 
              /*,items: [
              {
                   id:'mn'
                  ,iconCls: 'music-new-icon'
                  ,tooltip: this.szNew
                  ,scope: this
                  ,disabled:false
                  ,handler: function(){ this.EditItem(null); }
              }
              ]*/})
        ,plugins:[this.filter]
    });

    this.store.on({
         'load' : this.onLoad
        ,'loadexception' : this.onLoadException
        ,scope:this
    });

    this.on('rowcontextmenu', this.onContextClick, this);
    this.on('rowdblclick', this.onDblClick, this);
};

Ext.extend(Ext.xxv.musicGrid,  Ext.grid.GridPanel, { // Ext.grid.EditorGridPanel

     szTitle         : "Music"
    ,szToolTip       : "Display list of music title"
    ,szFindTitle     : "Search tracks with same title"
    ,szFindArtist    : "Search tracks by same artist"
    ,szFindAlbum     : "Search tracks from same album"
    ,szFindGenre     : "Search tracks by same genre"
    ,szFindYear      : "Search tracks from same year"
    ,szPlaying       : "Playing"
    ,szColAlbum	     : "Album"
    ,szColArtist     : "Artist"
    ,szColTitle      : "Title"
    ,szColDuration   : "Duration"
    ,szColTrack      : "Track"
    ,szColYear       : "Year"
    ,szColGenre      : "Genre"
    ,szColComment    : "Comment"
    ,szLoadException : "Couldn't get tracks from music list!\r\n{0}"
 
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
                     itemId:'mg'
                    ,text:  this.szPlaying
                    ,iconCls: 'playing-music-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.PlayingItem(this.ctxRecord); }
                  },'-',{
                     text:  this.szFindTitle                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: false
                    ,handler: function(){ this.reload('title', this.ctxRecord.data.title);}
                   },{
                     text:  this.szFindArtist                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: false
                    ,handler: function(){ this.reload('artist', this.ctxRecord.data.artist);}
                   },{
                     text:  this.szFindAlbum                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: false
                    ,handler: function(){ this.reload('album', this.ctxRecord.data.album);}
                   }/*,{
                     text:  this.szFindGenre                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: false
                    ,handler: function(){ this.reload('genre', this.ctxRecord.data.genre);}
                   }*/,{
                     text:  this.szFindYear                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: false
                    ,handler: function(){ this.reload('year', this.ctxRecord.data.year);}
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
                      if(f.disabled && XXV.help.cmdAllowed(f.itemId)) 
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
    ,reload : function(topic, value) {
        var f = this.filter.field.getValue();
        if(f && f !== '') {
          this.filter.field.setValue('');
        }
        this.store.baseParams = {
             cmd: 'ml'
            ,data: topic + ':' + value
        };
        this.store.title = value;
        this.store.load({params:{start:0, limit:configuration.pageSize}});
    }
  /******************************************************************************/
    ,onDblClick : function(grid, index, e) {
      //if(e) e.stopEvent();
      if(this.ctxRow){
          Ext.fly(this.ctxRow).removeClass('x-node-ctx');
          this.ctxRow = null;
      }
      var record = this.store.getAt(index);
      this.PlayingItem(record);
    }
    ,PlayingItem : function( record ) {
      this.stopEditing();
      //this.loadMask.show(); 

      var gsm = this.getSelectionModel();
      var sel = gsm.getSelections();
      if(sel.length <= 0) {
       gsm.selectRecords([record]);
       sel.push(record);
      }
      var toplay = new Array();
      var totitle = new Array();
      var toartist = new Array();

      for(var i = 0, len = sel.length; i < len; i++){
	      toplay.push(XXV.help.cmdHTML('mg',{data:sel[i].data.id}));
	      totitle.push(sel[i].data.title);
	      toartist.push(sel[i].data.artist);
      }

			var item = {
			   url  : toplay
			  ,title: totitle 
			  ,artist: toartist
			};

			if(!this.viewer.audiowin){
			  this.viewer.audiowin = new Ext.xxv.AudioWindow(item);
			} else {
			  this.viewer.audiowin.show(item);
			}
      //this.loadMask.hide(); 
    }
    /******************************************************************************/
    ,onCoverSuccess : function( response,options ) 
    { 
      this.CoverTT.show();
    }
    ,onCoverFailure : function( response,options ) 
    { 
    }
});

function createMusicView(viewer,id) {

    viewer.musicGrid = new Ext.xxv.musicGrid(viewer);
  
    tab = new Ext.xxv.Panel({
      id: id,
      iconCls:"music-icon",
      closable:true,
      border:false,
      layout:'border',
      stateful:true,
      items:[ viewer.musicGrid ]
    });


    viewer.add(tab);
    return tab;
}

