/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.xxv.Question = function(item,callback,scope) {

    if(XXV.help.cmdDisabled(item.cmd)) {
        new Ext.xxv.MessageBox().msgFailure(this.szCommandDeny, item.cmd);
        return;
    }

    this.callback = callback;
    this.scope = scope;
    this.item = item;

    this.store = new Ext.data.Store({
            reader: new Ext.xxv.jsonReader({
                    fields: [
                      {name: 'id',type: 'string'},
                      {name: 'fieldLabel', type: 'string'},
                      {name: 'type', type: 'string'},
                      {name: 'valuedef', type: 'string'},
                      {name: 'valuereq', type: 'boolean'},
                      {name: 'readonly', type: 'boolean'},
                      {name: 'choices'}
                    ]
                }),
            proxy : new Ext.data.HttpProxy({
                url: XXV.help.cmdAJAX(item.cmd,{ data:item.id })
                ,method: 'GET'
//              ,params: { data:item.id }
            })
    });

    Ext.xxv.Question.superclass.constructor.call(this, {
         stateful: false
        ,title: item.title
        ,width: 600
        //,height:500
        ,autoHeight:true
        ,minWidth: 300
        ,minHeight: 100
        ,layout: 'anchor'
        ,plain:true
        //,bodyStyle:'padding:5px;'
        ,buttonAlign:'right'
        ,buttons: [{
             text: this.szClose
            ,handler: this.destroy
            ,scope: this
        },{
             text: this.szApply
            ,handler: this.onApply
            ,scope: this
        }]
    });

    this.store.load({ scope: this
       ,callback: this.onLoad
       ,failure: this.onLoadException
    });
};

Ext.extend(Ext.xxv.Question, Ext.Window, {

     szClose : "Close"
    ,szApply : "Apply"
    ,szCommandDeny : "Command '{0}' not allowed!"
    ,szLoadException : "Couldn't get data!\r\n{0}"
    ,szFailure : "Couldn't save data!\r\n{0}"
    ,szSuccess : "Data saved successful.\r\n{0}"
    ,szComboEmpty : "Select ..."
 
    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onLoad : function(r,options,success){

      this.form = new Ext.form.FormPanel({
           id: 'form-panel'
          ,stateful: false
          ,baseCls: 'x-plain'
          ,labelWidth: 200
          ,defaultType: 'textfield'
          ,forceLayout: true
      });

      for(var i = 0, len = r.length; i < len; i++){
        var config = {
             name:       r[i].data.id
            ,fieldLabel: Ext.util.Format.ellipsis(r[i].data.fieldLabel,30)
            ,value:      r[i].data.valuedef
            ,anchor:     '100%'  // anchor width by percentage
            ,stateful:   false
            ,tabIndex:   i + 1
        };
        if(r[i].data.valuereq){
          config.allowBlank = false;
        }
        switch(r[i].data.type){
          case 'hidden':
            config.autoShow = false;
            config.xtype = 'hidden';
            break;
          case 'confirm':
            config.name  = null;
            config.xtype = 'fieldset';
            config.hideLabel = true;
            config.fieldLabel = null;
            config.hideBorders = true;
            config.autoHeight = true;
            config.labelWidth = 1;
            config.baseCls = '';
            config.style = 'border: 0px none;';
            config.items = [{
                 xtype: 'checkbox'
                ,labelSeparator: ''
                ,boxLabel: Ext.util.Format.ellipsis(r[i].data.fieldLabel,80)
                ,checked: r[i].data.valuedef == 'y' ? true : false
                ,name:    r[i].data.id
                }
            ];
            break;
          case 'checkbox':
            config.xtype = 'checkboxgroup';
            config.items = [];
            for(var f = 0, flen = r[i].data.choices.length; f < flen; f++){
              config.items.push({
                name:  r[i].data.choices[f],
                boxLabel: Ext.util.Format.ellipsis(r[i].data.choices[f],15),
                checked: (config.value.match(r[i].data.choices[f]) ? true : false)
                });
            }
            break;
          case 'password':
            config.xtype = 'textfield';
            config.allowBlank = true;
            config.inputType = 'password';
            break;
          case 'multilist':
            config.xtype = 'multiselect';
            config.allowBlank = true;

            if(r[i].data.choices.length > 0) {

              var fields;
              if(r[i].data.choices[0].length >= 3) {
                fields = [ {name: 'display'} ,{name: 'value'}, {name: 'groups'} ];

                var cls = 'ux-mselect';
                var tpl = '<tpl for=".">';
                    tpl+= '<tpl if="this.isNewGroup(groups)"><div class="x-combo-list-hd">{groups}</div></tpl>';
                    tpl+= '<div class="' + cls +'-item';
                if(Ext.isIE || Ext.isIE7)
                    tpl+='" unselectable=on';
                else
                    tpl+=' x-unselectable"';

                tpl+='>{display}</div></tpl>';

                config.tpl = new Ext.XTemplate(tpl, { 
                        isNewGroup: function(groups){
                          if(groups && (!this.lastgroups || groups != this.lastgroups)) 
                            { this.lastgroups = groups; return 1; }
                        return 0;
                     }
                });
              } else {
                fields = [ {name: 'display'} ,{name: 'value'} ];
                config.tpl = null;
              }
              config.store = new Ext.data.Store({
                          reader: new Ext.data.ArrayReader({}, fields),
                          data: r[i].data.choices
                      });
            }
            config.valueField        = 'value';
            config.displayField      = 'display';
            config.width             = '100%';
            if(len == 1) {
              config.hideLabel         = true;
              config.height            = 430; 
              if(!this.title) {
                this.title             = config.fieldLabel;
              }
            } else {
              config.height            = 120;
            }
            config.minLength         = 0;
            config.maxLength         = r[i].data.choices.length;
            break;
          case 'list':
            config.xtype = 'combo';
            if(r[i].data.choices.length > 0) {
              var fields;
              if(r[i].data.choices[0].length >= 3) {
                fields = [ {name: 'display'} ,{name: 'value'}, {name: 'groups'} ];
                config.tpl = new Ext.XTemplate(
                    '<tpl for=".">',
                        '<tpl if="this.isNewGroup(groups)"><div class="x-combo-list-hd">{groups}</div></tpl>',
                        '<div class="x-combo-list-item">{display}</div>',
                    '</tpl>', { 
                        isNewGroup: function(groups){
                          if(groups && (!this.lastgroups || groups != this.lastgroups)) { this.lastgroups = groups; return 1; }
                        return 0;
                     }
                });

              } else {
                fields = [ {name: 'display'} ,{name: 'value'} ];
                config.tpl = '<tpl for="."><div class="x-combo-list-item">{display}</div></tpl>';

              }
              config.store = new Ext.data.Store({
                          reader: new Ext.data.ArrayReader({}, fields),
                          data: r[i].data.choices
                      });

              config.displayField = 'display';
              config.valueField = 'value';
            }

            config.triggerAction = 'all';
            config.lazyRender = true;
            config.listClass = 'x-combo-list-small';
            config.mode = 'local';
            config.emptyText = this.szComboEmpty;
            config.selectOnFocus = true;
            config.editable = false;

            break;      
          case 'date':
            var today = new Date();
            today.clearTime();
            config.xtype = 'datefield';
            config.minValue = today;
            break;
          case 'time':
            config.xtype = 'timefield';
            config.increment = 15;
            config.format = 'H:i';
            break;
          case 'integer':
            config.xtype = 'numberfield';
            config.allowDecimals = false;
            break;   
          case 'textfield':
            config.xtype = 'textarea';
            break; 
        }
        if(r[i].data.readonly){
            config.hideLabel = true;
            config.height = 200;  // anchor width by percentage and height by raw adjustment
            config.readOnly = true;
        }
        this.form.add(config);
      }
      if(i) {
        this.add(this.form);
        this.show();
      } else {
        new Ext.xxv.MessageBox().msgFailure(this.szLoadException, "");
      }

    },

    onApply: function() {
        this.el.mask(Ext.LoadMask.prototype.msg, 'x-mask-loading');

        var params = {data:this.item.id,ajax:'json','__action':'save'}; 
        for(var i = 0, len = this.store.getCount(); i < len; i++){
          var record = this.store.getAt(i);
          if(record.data.readonly == 0) {
             var field = this.form.getForm().findField(record.data.id);
             if(field)
             switch(record.data.type){
                case 'confirm':
                  params['__'+record.data.id] = field.checked ? 'y' : 'n';
                  break;
                case 'checkbox':
                  var values = field.getValue();
                  var boxes = [];
                  for(var f = 0, flen = values.length; f < flen; f++){
                     boxes.push(values[f].name);
                  }
                  params['__'+record.data.id] = boxes.join(',');
                  break;
                case 'time':
                  params['__'+record.data.id] = field.getValue();
                  break;
                case 'date':
                  var f = field.getValue();
                  if(f && typeof(f) ==='date' )
                    params['__'+record.data.id] = f.dateFormat('Y-m-d');
                  else
                    params['__'+record.data.id] = field.getRawValue();
                  break;
                default:
                  params['__'+record.data.id] = field.getValue();
                  break;
             }
          }
        }
        Ext.Ajax.request({
             url:'?' + Ext.urlEncode({cmd:this.item.cmd})
            ,method: 'POST'
            ,params: params
            ,success: this.onSuccess
            ,failure: this.onFailure
            ,scope: this
        });
    },

    onFailure : function(response,options){
        this.el.unmask();
        new Ext.xxv.MessageBox().msgFailure(this.szFailure,response.statusText);
    },

    onSuccess : function(response, options){
        this.el.unmask();
        var o = eval("("+response.responseText+")");
        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {
            new Ext.xxv.MessageBox().msgSuccess(this.szSuccess, o.data);
            this.hide();
            if(this.callback)
              this.callback.call(this.scope);
        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szFailure, msg);
        }
    }
});
