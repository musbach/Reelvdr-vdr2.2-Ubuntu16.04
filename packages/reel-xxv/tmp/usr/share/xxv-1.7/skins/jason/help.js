/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.help = function(/*config*/){
    //Ext.xxv.help.superclass.constructor.call(this, config);
    //Ext.apply(this, config);

    this.store = new Ext.data.Store({
             baseParams:{cmd:'help'}
            ,autoLoad: true
            ,reader: new Ext.xxv.jsonReader({
                        fields: [
                                  {name: 'id', type: 'string'},
                                  {name: 'cmd', type: 'string'},
                                  {name: 'module', type: 'string'},
                                  {name: 'description', type: 'string'}
                                ]
                    })
            ,proxy : new Ext.data.HttpProxy({
                url: this.baseURL()
               ,method: 'GET'
            })
    });

    this.store.on('load', this.onLoad , this);
};


Ext.extend(Ext.xxv.help, Ext.util.Observable, {

  onLoad : function(store, records, options) {

    if(!this.cmdDisabled('ce')) {
      var lastModule;
      for(var i = 0, len = store.getCount(); i < len; i++){
        var record = store.getAt(i);
        if(!lastModule || record.data.module != lastModule) {
          lastModule = record.data.module;
          XXV.configMenu.add(new Ext.menu.Item(
            { 
               text: record.data.module
              ,disabled:false
              ,handler: this.Configure
              ,scope:this
            }));
        }
      }
    }
  }
  ,Configure : function(item, e) {
    if(e) {
      if(XXV.tab.formwin){
        XXV.tab.formwin.close();
      }
      XXV.tab.formwin = new Ext.xxv.Question({
         cmd:   'ce'
        ,id:    item.text
        ,title: item.text
      });
    }
  }
  ,Settings : function(item, e) {
    if(e) {
      if(XXV.tab.formwin){
        XXV.tab.formwin.close();
      }
      XXV.tab.formwin = new Ext.xxv.Question({
         cmd:   'up'
        ,title: item.text
      });
    }
  }
  ,baseURL: function(param) {
    if(!param) {
      param = {};
    }
    param.ajax = 'json';
    return '?' + Ext.urlEncode(param);
  }
  ,cmdHTML: function(cmd, param) {
    if(!param) {
      param = {};
    }
    param.cmd = cmd;
    return '?' + Ext.urlEncode(param);
  }
  ,cmdAJAX: function(cmd, param) {
    if(!param) {
      param = {};
    }
    param.cmd = cmd;
    param.ajax = 'json';
    return this.cmdHTML(cmd,param);
  }
  ,cmdAllowed: function(cmd) {
    var record = this.store.getById(cmd);
    return (record) ? true : false;
  }
  ,cmdDisabled: function(cmd) {
    var record = this.store.getById(cmd);
    return (record) ? false : true;
  }
});


