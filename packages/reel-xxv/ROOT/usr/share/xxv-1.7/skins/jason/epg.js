/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2011-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.EPGPreview = function(viewer,store, config) {
    this.viewer = viewer;
    this.store = store;
    Ext.xxv.EPGPreview.superclass.constructor.call(this, config);
};

Ext.extend(Ext.xxv.EPGPreview, Ext.Panel, {
    select : function(record){
      var data = record.data;
      data.footer = "";
      if(data.contents) {
        var c = data.contents.split(" ");
        for(var i = 0; i < c.length; i++){
          if(data.footer.length) { data.footer += ' '; }
          var s = contentText[parseInt(c[i],16)];
          if(!s)
            s = contentText[(parseInt(c[i],16) & 0xF0)>>8 ];
          if(s)
            data.footer += s;
        }
      }
      if(this.body)
        XXV.getTemplate().overwrite(this.body, data);

      if(this.lookup)
        highlightText(this.body.dom,this.lookup,'x-highlight',1);

      var hasAutotimer = (data.autotimerid && data.autotimerid <= 0) ? 0 : 1;
      var hasTimer = (data.timerid || this.id == 'preview-timer') ? 1 : 0;

      // Enable all toolbar buttons
      if(this.topToolbar.items) { 
          this.topToolbar.items.eachKey(function(key, f) {
                    if(f.id == 'tn')      { if(hasTimer) f.hide(); else f.show(); }
                    else if(f.id == 'te') { if(hasTimer) f.show(); else f.hide(); }
                    else if(f.id == 'tt') { if(hasTimer) f.show(); else f.hide(); }
                    else if(f.id == 'td') { if(hasTimer) f.show(); else f.hide(); }
                    else if(f.id == 'ae') { if(hasAutotimer) f.show(); else f.hide(); }
                    if(XXV.help.cmdAllowed(key)) f.enable();
            },this.topToolbar.items); 
        }
    }
    ,clear: function(){
      this.lookup = null;
      if(this.body)
         this.body.update('');
      // Disable all items
      if(this.topToolbar.items)
        { this.topToolbar.items.eachKey(function(key, f){f.disable();},this.topToolbar.items); }
    }
    ,showDetails : function(record, eventid, lookup){
        this.lookup = lookup;
        this.select(record);
        this.DetailsItem(record, eventid);
    } 
    /******************************************************************************/
    ,onDetailsSuccess : function( response,options ) 
    { 
      var iSel = this.store.indexOfId(options.query);
      if(iSel === -1)
        return;

      var o = eval("("+response.responseText+")");

      if(o && o.data && typeof(o.data) == 'object') {

          var a = o.data[0];

          if(this.store.data.items[iSel].data.eventid) {
            if(this.store.data.items[iSel].data.eventid != a[0])
              return;
          } else {
            if(this.store.data.items[iSel].id != a[0])
              return;
          }

          this.store.data.items[iSel].data.description = a[6];
          this.store.data.items[iSel].data.video       = a[7];
          this.store.data.items[iSel].data.audio       = a[8];
          this.store.data.items[iSel].data.image       = a[13];
          this.store.data.items[iSel].data.contents    = a[17] ? a[17] : '0';

          var record = this.store.getById(options.query);
          this.select(record);

      } else {
          this.store.data.items[iSel].data.contents = '0';
          var msg = '';
          if(o && o.data && typeof(o.data) == 'string') {
            msg = o.data;
          }
          new Ext.xxv.MessageBox().msgFailure(this.szDetailsFailure, msg);
      }
    }
    ,onDetailsFailure : function( response,options ) 
    { 
      var iSel = this.store.indexOfId(options.query);
      if(iSel === -1)
        return;
      this.store.data.items[iSel].data.contents = '0';

      var msg = '';
      if(response && response.statusText && typeof(response.statusText) == 'string') {
        msg = response.statusText;
      }
      new Ext.xxv.MessageBox().msgFailure(this.szDetailsFailure, msg);
    }
    ,DetailsItem : function(record, eventid) {
      if(record.data.contents) { //use cached data
        this.select(record);
        return;
      }
      if(!eventid) {
        return;
      }
      if(this.DetailsTransaction) 
        Ext.Ajax.abort(this.DetailsTransaction);
      this.DetailsTransaction = Ext.Ajax.request({
            scope: this
           ,url: XXV.help.cmdAJAX('d')
           ,timeout: 15000
           ,success: this.onDetailsSuccess
           ,failure: this.onDetailsFailure
           ,params:{ data: eventid }
           ,query: record.data.id
      });
    }
});

