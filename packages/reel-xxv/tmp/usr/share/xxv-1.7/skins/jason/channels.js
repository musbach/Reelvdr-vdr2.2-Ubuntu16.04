/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.storeChannels = function() {
    return new Ext.data.Store({
            autoLoad: true,
            reader: new Ext.xxv.jsonReader({
                        fields: [
                                  {name: 'id', type: 'string'},
                                  {name: 'cid', type: 'string'},
                                  {name: 'name', type: 'string'},
                                  {name: 'group', type: 'string'},
                                  {name: 'position', type: 'int'},
                                  {name: 'grpname', type: 'string'}
                                ]
                    }),
            proxy : new Ext.data.HttpProxy({
                url: XXV.help.cmdAJAX('cl',{compact:1})
               ,method: 'GET'
            })
//          sortInfo:{field:'position', direction:'ASC'}
    });

};

/******************************************************************************/
Ext.xxv.ChannelsCombo = function(config){
    Ext.apply(this, config);
    if(!this.id){
        this.id = Ext.id();
    }
    this.renderer = this.renderer.createDelegate(this);
};

Ext.xxv.ChannelsCombo.prototype ={
    init : function(grid){
    },
    renderer: function(value, p, record) {

      for(var i = 0, len = this.store.data.length; i < len; i++){
        var rec = this.store.getAt(i);
        if(rec.data.position == value) {
          return rec.data.name;
        }
      }
      return record.data.channel;
    }
};
