/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.jsonReader = function(meta, recordType){
    meta = meta || {};
    Ext.xxv.jsonReader.superclass.constructor.call(this, meta, recordType || meta.fields);
};
Ext.extend(Ext.xxv.jsonReader, Ext.data.DataReader, {

    read : function(r){
        if(r.status != 200) {
            throw {message: "XXVReader.read: " + r.statusText };
        }
        var o = eval('('+r.responseText+')');
        if(!o || !o.data || typeof(o.data) != 'object') {
            if(o && o.data && typeof(o.data) == 'string') {
              throw {message: o.data};
            }
            throw {message: "XXVReader.read: Json object not found"};
        }
        return this.readRecords(o.data,o.param);
    },

    readRecords : function(o,p){

      var Record = this.recordType,
          f = Record.prototype.fields, fi = f.items, fl = f.length;
      var records = [];

      for (var i = 0; i < o.length; i++) {
        var n = o[i];
        var values = {};
        var id = n[0];
        for(var j = 0; j < fl; j++){
          f = fi[j];
          var v = n[j];
          values[f.name] = f.convert((v !== undefined) ? v : f.defaultValue);
        }
        var record = new Record(values, id);
        record.json = n;
        records[i] = record;
      }
      var total = records.length;
      if(p && p.rows) {
        total = p.rows;
      }
      if(this.meta && p) {
        if(this.meta.param) {
          delete this.meta.param;
        }
        this.meta.param = p;
      }
      return {
        success : true,
        records : records,
        totalRecords : total
      };
    }
});
