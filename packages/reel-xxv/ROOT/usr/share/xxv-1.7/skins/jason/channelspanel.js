/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2010, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.channelsPanel = function() {

    this.store = new Ext.xxv.storeChannels();

    Ext.xxv.channelsPanel.superclass.constructor.call(this, {
        id:'channel-tree',
        region:'west',
        split:true,
        width: 225,
        minSize: 175,
        maxSize: 400,
        collapsible: true,
        margins:'5 0 5 5',
        cmargins:'5 5 5 5',
        rootVisible:false,
        lines:false,
        autoScroll:true,
        root: new Ext.tree.TreeNode('items'),
        collapseFirst:false,

        tbar: [
                 {
                     id:'lst'
                    ,iconCls:'stream-icon'
                    ,tooltip: {title:this.webcastTTText,text:this.webcastText}
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){
                        var s = this.getSelectionModel().getSelectedNode();
                        if(s){
                          this.onWebCastChannel(s.attributes.channel);
                        }
                     }
                 },
                 {
                       id:'sw'
                      ,iconCls:'switch-icon'
                      ,tooltip: {title:this.switchTTText,text:this.switchText}
                      ,scope: this
                      ,disabled: true
                      ,handler:function(){
                        var s = this.getSelectionModel().getSelectedNode();
                        if(s){
                          this.onSwitchChannel(s.attributes.channel);
                        }
                      }
                 }
                 ,'-',
                 {
                       id:'ced'
                      ,iconCls:'edit-icon'
                      ,tooltip: {title:this.editTTText,text:this.editText}
                      ,scope: this
                      ,disabled: true
                      ,handler:function(){
                        var s = this.getSelectionModel().getSelectedNode();
                        if(s){
                          this.EditItem(s.attributes.channel);
                        }
                      }
                 }
                 ,'->'
                 ,{
                       id:'cl'
                      ,iconCls:'x-tbar-loading'
                      ,tooltip: this.refreshText
                      ,scope: this
                      ,handler:function(){ this.store.reload(); }
                 }

              ]
    });

    this.getSelectionModel().on({
        'beforeselect' : function(sm, node){
             return node.isLeaf();
        },
        'selectionchange' : function(sm, node){
            if(node){
                var record = this.store.getById(node.attributes.channel);
                var top = Ext.getCmp('main-tabs');
                if(top.getActiveTab().id == 'vt') {
                  top.openTeleText(node.attributes.text, node.attributes.channel);
                } else {
                  top.openProgram(record.data);
                }

                var items = this.topToolbar.items;
                if(items) { items.eachKey(function(key, f) {
                            if(XXV.help.cmdAllowed(key)) { f.enable(); }
                },items); }
            }
        },
        scope:this
    });

    this.store.on('load', this.onLoad, this);
    this.store.on('loadexception', this.onLoadException, this);
    this.on('contextmenu', this.onContextMenu, this);
};          

Ext.extend(Ext.xxv.channelsPanel, Ext.tree.TreePanel, {

     title       : "Channels"
    ,refreshText : "Refresh"
    ,selectText  : "Select channel"
    ,webcastTTText : "Web cast"
    ,webcastText : "Live web cast this channel"
    ,switchTTText: "Switch"
    ,switchText  : "Switch to this channel"
    ,teleTextText: "Teletext pages"
    ,teleTextTTText: "Show teletext pages from this channel"
    ,editTTText  : "Edit"
    ,editText    : "Edit this channel"
    ,deleteText  : "Delete this channel"
    ,szLoadException : "Couldn't get channels data!\r\n{0}"
    ,szSwitchSuccess : "Successful switch to channel.\r\n{0}"
    ,szSwitchFailure : "Couldn't switch to channel!\r\n{0}"
    ,szDeleteSuccess : "Channel successful deleted.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete channel!\r\n{0}"
    ,stateful        : true

    ,onContextMenu : function(node, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                items: [{
                     itemId:'p'
                    ,iconCls:'select-channel-icon'
                    ,text:this.selectText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ 
                        var record = this.store.getById(this.ctxNode.attributes.channel);
                        var top = Ext.getCmp('main-tabs');
                        top.openProgram(record.data);
                      }
                    }
                    ,'-',
                    {
                     itemId:'lst'
                    ,iconCls:'stream-icon'
                    ,text:this.webcastText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ this.onWebCastChannel(this.ctxNode.attributes.channel); }
                    },{
                     itemId:'sw'
                    ,iconCls:'switch-icon'
                    ,text:this.switchText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ this.onSwitchChannel(this.ctxNode.attributes.channel); }
                    },{
                     itemId:'vt'
                    ,iconCls:'teletext-icon'
                    ,text:this.teleTextText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ 
                        var top = Ext.getCmp('main-tabs');
                        top.openTeleText(this.ctxNode.attributes.text, this.ctxNode.attributes.channel);
                      }
                    }
                    ,'-',
                    {
                     itemId:'ced'
                    ,iconCls:'edit-icon'
                    ,text:this.editText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ this.EditItem(this.ctxNode.attributes.channel); }
                    },
                    {
                     itemId:'cdl'
                    ,iconCls:'delete-icon'
                    ,text:this.deleteText
                    ,scope: this
                    ,disabled: true
                    ,handler:function(){ this.DeleteItem(this.ctxNode.attributes.channel,this.ctxNode); }
                    }
                    ]
            });
            this.menu.on('hide', this.onContextHide, this);
        }
        if(this.ctxNode){
            this.ctxNode.ui.removeClass('x-node-ctx');
            this.ctxNode = null;
        }
        if(node.isLeaf()){
            this.ctxNode = node;
            this.ctxNode.ui.addClass('x-node-ctx');

            var items = this.menu.items;
            if(items) { items.eachKey(function(key, f) {
                          if(XXV.help.cmdAllowed(f.itemId)) 
                          { f.enable(); }
                          },items); 
                      }

            this.menu.showAt(e.getXY());
        }
    }

    ,onContextHide : function(){
        if(this.ctxNode){
            this.ctxNode.ui.removeClass('x-node-ctx');
            this.ctxNode = null;
        }
        if(this.menu) {
          this.menu.destroy();
          delete this.menu;
          this.menu = null;
        }
    }

    ,additem : function(attrs, inactive, preventAnim, treeitem){
        var exists = this.getNodeById(attrs.url);
        if(exists){
            if(!inactive){
                exists.select();
                exists.ui.highlight();
            }
            return null;
        }
        Ext.apply(attrs, {
            iconCls: 'channel-icon',
            leaf:true,
            cls:'channel',
            id: attrs.url
        });
        var node = new Ext.tree.TreeNode(attrs);
        treeitem.appendChild(node);

        if(!inactive){
            if(!preventAnim){
                Ext.fly(node.ui.elNode).slideIn('l', {
                    callback: node.select, scope: node, duration: 0.4
                });
            }else{
                node.select();
            }
        }
        return node;
    }

    // prevent the default context menu when you miss the node
    ,afterRender : function(){
        Ext.xxv.channelsPanel.superclass.afterRender.call(this);
        this.el.on('contextmenu', function(e){
            e.preventDefault();
        });
    }
/******************************************************************************/
    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onLoad : function( store, records, opt ) {

      var i,node,grpname; 

      for(i = this.root.childNodes.length; i > 0; i--){        
        this.root.removeChild(this.root.item(i-1));
      }

      for(i = 0, len = records.length; i < len; i++){
        if(!node || records[i].data.grpname != grpname) {
           node = this.root.appendChild(
                new Ext.tree.TreeNode({
                    text:records[i].data.grpname,
                    cls:'channels-node',
                    expanded: (i === 0 ? true: false)
                })
            );
          grpname = records[i].data.grpname;
        }
        this.additem({
            text: records[i].data.name,
            channel: records[i].data.id
        }, true,true,node);
     }
  }
/******************************************************************************/
  ,onSwitchSuccess : function( response,options ) 
  { 
      var json = response.responseText;
      var o = eval("("+json+")");
      if(!o || !o.data || typeof(o.data) != 'string') {
        throw {message: "Ajax.read: Json message not found"};
      }
      if(o.success) {
          new Ext.xxv.MessageBox().msgSuccess(this.szSwitchSuccess, o.data);
      }else {
          new Ext.xxv.MessageBox().msgFailure(this.szSwitchFailure, o.data);
      }
  }
  ,onSwitchFailure : function( response,options ) 
  { 
      new Ext.xxv.MessageBox().msgFailure(this.szSwitchFailure, response.statusText);
  }
  ,onSwitchChannel : function( id ) {
    var record = this.store.getById(id);
    
    if(this.SwitchChanneltid) Ext.Ajax.abort(this.SwitchChanneltid);
    this.SwitchChanneltid = Ext.Ajax.request({
        url: XXV.help.cmdAJAX('sw',{ 'data': record.data.cid, '__vdr': XXV.menu.host })
       ,success: this.onSwitchSuccess
       ,failure: this.onSwitchFailure
       ,scope: this
    });
  }
/******************************************************************************/
  ,EditItem : function( id ) {
    var record = this.store.getById(id);

    var item = {
       cmd:   'ced'
      ,id:    record.data.id
      ,title: record.data.name
    };

    var viewer = Ext.getCmp('main-tabs');
    if(viewer.formwin){
      viewer.formwin.close();
    }
    viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this.store);
  }
/******************************************************************************/
  ,onDeleteSuccess : function( response,options ) 
  { 
      var json = response.responseText;
      var o = eval("("+json+")");
      if(!o || !o.data || typeof(o.data) != 'string') {
        throw {message: "Ajax.read: Json message not found"};
      }
      if(o.success) {
          this.root.removeChild(options.node);
          var record = this.store.getById(options.id);
          if(record) {
            this.store.remove(record);
          }
          new Ext.xxv.MessageBox().msgSuccess(this.szDeleteSuccess, o.data);
      } else {
          new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, o.data);
      }
  }
  ,onDeleteFailure : function( response,options ) 
  { 
      new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, response.statusText);
  }
  ,DeleteItem : function( id,node ) {
    var record = this.store.getById(id);
    
    if(this.DeleteChanneltid) Ext.Ajax.abort(this.DeleteChanneltid);
    this.DeleteChanneltid = Ext.Ajax.request({
        url: XXV.help.cmdAJAX('cdl',{ data: record.data.id })
       ,node: node
       ,id: record.data.id
       ,success: this.onDeleteSuccess
       ,failure: this.onDeleteFailure
       ,scope: this
    });
  }
/******************************************************************************/
  ,onWebCastChannel : function( id ) {
    var record = this.store.getById(id);
    var item = {
       url: XXV.help.cmdHTML('lst',{ 'data': record.data.position, '__vdr': XXV.menu.host, '__player':'1' })
      ,title: record.data.name
    };

    var viewer = Ext.getCmp('main-tabs');
    viewer.streamwin = Ext.xxv.createStream(item,viewer.streamwin);
  }
});
