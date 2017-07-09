/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2009-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

Ext.LoginPanel = function() {

    Ext.LoginPanel.superclass.constructor.call(this, {
         labelWidth:120
        ,url:'?cmd=login&ajax=json&__action=save'
        ,frame:true
        ,title:this.szTitle
        ,defaultType:'textfield'
        ,monitorValid:true
        ,items:[ {
               xtype:'box'
              ,anchor:''
              ,isFormField:false
              ,fieldLabel:''
              ,autoEl:{
                  tag:'div' 
                  ,style:'margin:0 0 0 0'
                  ,children:[{
                   tag:'img'
                  ,src:'pic/login.png'
                }]
              }
            },{ 
                fieldLabel:this.szUser
                ,name:'__name'
                ,allowBlank:false 
            },{ 
                fieldLabel:this.szPassword
                ,name:'__password'
                ,inputType:'password'
                ,allowBlank:false 
            }]
        ,buttons:[{ 
                text: this.szLogin
                ,formBind: true
                ,scope: this
                ,handler:this.onSubmit
                }]
    });
};

Ext.extend(Ext.LoginPanel, Ext.FormPanel, {
     szTitle:   'Please login'
    ,szUser:    'Username'
    ,szPassword:'Password'
    ,szLogin:   'Login'
    ,szFailed:  'Login failed!'
    ,szWarning: 'Warning!'
    ,szUnreachable: 'Authentication server is unreachable : '
    ,onSubmit:function() { 
        this.getForm().submit({ 
            method:'POST'
            ,waitTitle:Ext.form.BasicForm.prototype.waitTitle 
            ,waitMsg:Ext.LoadMask.prototype.msg
            ,scope: this
            ,success:function(){ 
                var redirect = '?cmd=n'; 
                window.location = redirect;
            }
            ,failure:function(form, action){ 
                if(action.response && action.response.status === 200 ){ 
                    var obj = Ext.util.JSON.decode(action.response.responseText);
                    Ext.Msg.show({
                       title:this.szFailed,
                       msg: obj.data,
                       buttons: Ext.Msg.CANCEL,
                       icon: Ext.MessageBox.ERROR
                    });
                }else{ 
                    if(action.failureType) {
                      switch (action.failureType) {
                          case Ext.form.Action.CLIENT_INVALID:
                              Ext.Msg.show({
                                 title:this.szWarning,
                                 msg: Ext.form.Field.prototype.invalidText,
                                 buttons: Ext.Msg.CANCEL,
                                 icon: Ext.MessageBox.ERROR
                              });
                              break;
                          case Ext.form.Action.CONNECT_FAILURE:
                              Ext.Msg.show({
                                 title:this.szWarning,
                                 msg: this.szUnreachable + action.response.statusText,
                                 buttons: Ext.Msg.CANCEL,
                                 icon: Ext.MessageBox.ERROR
                              });
                              break;
                          case Ext.form.Action.SERVER_INVALID:
                              Ext.Msg.show({
                                 title:this.szWarning,
                                 msg: action.result.msg,
                                 buttons: Ext.Msg.CANCEL,
                                 icon: Ext.MessageBox.ERROR
                              });
                              break;
                     }
                    } else {
                      Ext.Msg.show({
                         title:this.szWarning,
                         msg: this.szUnreachable + action.response.statusText,
                         buttons: Ext.Msg.CANCEL,
                         icon: Ext.MessageBox.ERROR
                      });
                    }
                } 
                this.getForm().reset(); 
            } 
        }); 
    } 
});

Ext.onReady(function(){
  Ext.QuickTips.init();

  var win = new Ext.Window({
      layout:'fit',
      width:330,
      height:220,
      closable: false,
      resizable: false,
      plain: true,
      border: false,
      items: [new Ext.LoginPanel()]
    });

  win.show();

  setTimeout(function(){
        var l = Ext.get('loading'); 
        if(l) {
          l.remove();
        }
        var m = Ext.get('loading-mask'); 
        if(m) {
          m.fadeOut({remove:true});
        }
  }, 250);
});
