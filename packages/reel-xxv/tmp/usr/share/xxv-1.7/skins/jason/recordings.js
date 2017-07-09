/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */
/******************************************************************************/

minTime = function() {
  return Date.parseDate(Ext.form.TimeField.prototype.initDate, 
                        Ext.form.TimeField.prototype.initDateFormat).clearTime();
};

pad = function(n) {
 return String("00" + parseInt(n)).slice(-2);
};

SecondsToHMS = function(t) {
  var s = t % 60;
  var m = parseInt(t / 60) % 60;
  var h = parseInt(t / 3600);
  return h + ":" + pad(m) + ":" + pad(s);
};

/******************************************************************************/
HMSToSeconds = function(s) {
  var seconds;
  var tt = s.replace(/\..*/g, '');
  var x = tt.split(":");
  seconds = parseInt(x.pop(),10);
  if(x.length > 0) {
    seconds += ( 60 * parseInt(x.pop(),10));
  }
  if(x.length > 0) {
    seconds += (3600 * parseInt(x.pop(),10));
  }
  return seconds;
};

/******************************************************************************/
Ext.xxv.slider = function(config){
    Ext.xxv.slider.superclass.constructor.call(this, config);
    
    Ext.apply(this, config);
};

Ext.extend(Ext.xxv.slider, Ext.Component, {

    slider: null

    ,initComponent : function(){
        Ext.xxv.slider.superclass.initComponent.call(this);
        this.addEvents({'MoveSlider' : true});
    },

    setvalue : function(marks, duration){
      this.marks = marks;
      this.duration = duration;
      this.modified = 1;
    },

    render : function(ct, position){
      if(!this.modified)
        return;
      this.modified = 0;
      if(this.slider) {
        //this.slider.remove();
        ct.dom.innerHTML = '';
        delete this.slider;
        this.slider = null;

        //this.slider.sliders.clear();
        //this.slider.maxValue = this.duration;
      } //else 
      //{
        this.slider = new Ext.ux.SlideZone(ct.id, {  
           type: 'horizontal'
          ,size: ct.getWidth()
          ,sliderWidth: 16
          ,sliderHeight: 24
          ,minValue: 0
          ,maxValue: this.duration
          //,sliderSnap: 1
          ,allowSliderCrossing: true
          });
        this.ts = new Ext.ux.ThumbSlider({
           value: 0
          ,name: 'cutpoint_thumb'
          ,cls: 'x-slide-zone-bottom'
          ,allowMove: true
          });
        this.ts.on('drag',
          function() {
            var v = parseInt(this.ts.value * 1000,10);
            this.fireEvent('MoveSlider', this, new Date((minTime().getTime())+v), null, null);
        },this);
      //}

      if(this.marks && this.marks.length) {
        var cutpoint = this.marks.split(",");
        for(var i = 0, len = cutpoint.length; i < len; i += 2){
          var first = HMSToSeconds(cutpoint[i]);
          var second;
          if(i+1 < cutpoint.length) {
            second = HMSToSeconds(cutpoint[i+1]);
          } else {
            second = this.duration;
          }
          var rs = new Ext.ux.RangeSlider({
             value: [first,second]
            ,name: 'cutpoint_'+i
            ,cls: 'x-slide-zone-top'
            ,allowMove: false
          });
          this.slider.add(rs);  
        }
      }
      this.slider.add(this.ts);
    }
});

Ext.reg('MarksSlider', Ext.xxv.slider);

/******************************************************************************/
Ext.xxv.RecHeader = function(config){
    Ext.xxv.RecHeader.superclass.constructor.call(this, config);    Ext.apply(this, config);
};

Ext.extend(Ext.xxv.RecHeader, Ext.Component, {

    initComponent : function(){
        Ext.xxv.RecHeader.superclass.initComponent.call(this);

        this.tpl = new Ext.Template(
          '<div class="preview-header">',
            '<div class="preview-topic">',
              '<h3 class="preview-title">{title}</h3>',
              '<h4 class="preview-shorttitle">{subtitle:this.formatSubtitle}</h4>',
            '</div>',
            '{channel:this.formatChannel}',
            '<div class="preview-date">{day:date} {start} - {stop} {period}{cutlength:this.formatCutlength}',
            '</div>',
           '</div>'
          ,{
             compiled: true
            ,formatSubtitle : function(t) {
              if(t && t !== '')
                  return '&nbsp;-&nbsp;' + t;
              return '&nbsp;';
            }
            ,formatChannel : function(t) {
              if(t && t !== '')
                  return '<div class="preview-channel"><b>' + t + '</b>&nbsp;</div>';
              return '';
            }
            ,formatCutlength : function(t) {
              if(t && t !== '')
                  return '&nbsp;(' + t + ')';
              return '';
            }
          }
        );
    },

    setvalue : function(data, lookupdata){

      this.param = {
         title:     data.fulltitle
        ,subtitle:  ''
        ,channel:   data.channel
        ,day:       data.day
        ,duration:  data.duration
        ,start:     data.day.dateFormat('H:i')
        ,stop:      new Date(data.day.getTime() + (data.duration * 1000)).dateFormat('H:i')
        ,cutlength: data.cutlength == data.duration ? null : SecondsToHMS(data.cutlength)
        ,period:    SecondsToHMS(data.duration)
        ,lookup:    lookupdata
      };

      var title = data.title.split("~");
      if(data.subtitle && data.subtitle.length >1) {
        title.push(data.subtitle);
      }
      if(title.length >1) {
        this.param.subtitle = title.pop();
        this.param.title = title.join("~");
      }
    },
    render : function(ct, position){
      if(this.param) {
          this.tpl.overwrite(ct, this.param);
          if(this.param.lookup)
            highlightText(ct.dom,this.param.lookup,'x-highlight',1);
        }
    }
});

Ext.reg('RecHeader', Ext.xxv.RecHeader);


/******************************************************************************/

Ext.DataView.LabelEditor = function(cfg, field){
    Ext.DataView.LabelEditor.superclass.constructor.call(this,
        field || new Ext.form.TextField({
            allowBlank: false,
            growMin:90,
            growMax:240,
            grow:true,
            selectOnFocus:true
        }), cfg
    );
};

Ext.extend(Ext.DataView.LabelEditor, Ext.Editor, {
    alignment: "tl-tl",
    hideEl : false,
    cls: "x-small-editor",
    shim: false,
    completeOnEnter: true,
    cancelOnEsc: true,
    labelSelector: 'span.x-editable',

    init : function(view){
        this.view = view;
        view.on('render', this.initEditor, this);
        this.on('complete', this.onSave, this);
    },

    initEditor : function(){
        this.view.getEl().on('mousedown', this.onMouseDown, this, {delegate: this.labelSelector});
    },

    onMouseDown : function(e, target){
        if(!e.ctrlKey && !e.shiftKey){
            var item = this.view.findItemFromChild(target);
            e.stopEvent();
            var record = this.view.store.getAt(this.view.indexOf(item));
            if(record.data[this.allow]) {
              this.startEdit(target, record.data[this.dataIndex]);
              this.activeRecord = record;
            }
        }else{
            e.preventDefault();
        }
    },

    onSave : function(ed, value){
        this.activeRecord.set(this.dataIndex, value);
    }
});

/******************************************************************************/

Ext.DataView.DragSelector = function(cfg){
    cfg = cfg || {};
    var view, regions, proxy, tracker;
    var rs, bodyRegion, dragRegion = new Ext.lib.Region(0,0,0,0);
    var dragSafe = cfg.dragSafe === true;

    this.init = function(dataView){
        view = dataView;
        view.on('render', onRender);
    };

    function fillRegions(){
        rs = [];
        view.all.each(function(el){
            rs[rs.length] = el.getRegion();
        });
        bodyRegion = view.el.getRegion();
    }

    function cancelClick(){
        return false;
    }

    function onBeforeStart(e){
        return !dragSafe || e.target == view.el.dom;
    }

    function onStart(e){
        view.on('containerclick', cancelClick, view, {single:true});
        if(!proxy){
            proxy = view.el.createChild({cls:'x-view-selector'});
        }else{
            proxy.setDisplayed('block');
        }
        fillRegions();
        view.clearSelections();
    }

    function onDrag(e){
        var startXY = tracker.startXY;
        var xy = tracker.getXY();

        var x = Math.min(startXY[0], xy[0]);
        var y = Math.min(startXY[1], xy[1]);
        var w = Math.abs(startXY[0] - xy[0]);
        var h = Math.abs(startXY[1] - xy[1]);

        dragRegion.left = x;
        dragRegion.top = y;
        dragRegion.right = x+w;
        dragRegion.bottom = y+h;

        dragRegion.constrainTo(bodyRegion);
        proxy.setRegion(dragRegion);

        for(var i = 0, len = rs.length; i < len; i++){
            var r = rs[i], sel = dragRegion.intersect(r);
            if(sel && !r.selected){
                r.selected = true;
                view.select(i, true);
            }else if(!sel && r.selected){
                r.selected = false;
                view.deselect(i);
            }
        }
    }

    function onEnd(e){
        if(proxy){
            proxy.setDisplayed(false);
        }
    }

    function onRender(view){
        tracker = new Ext.dd.DragTracker({
            onBeforeStart: onBeforeStart,
            onStart: onStart,
            onDrag: onDrag,
            onEnd: onEnd
        });
        tracker.initEl(view.el);
    }
};

/******************************************************************************/

Ext.xxv.recordingsStore = function() {

    // create the data store
    return new Ext.data.Store({
             baseParams:{cmd:'rl'}
            ,autoLoad:{params:{start:0, limit:configuration.pageSize}}
            ,reader: new Ext.xxv.jsonReader({
                    fields: [
                       {name: 'id', type: 'string'}
                      ,{name: 'eventid', type: 'int'}
                      ,{name: 'title', type: 'string'}
                      ,{name: 'subtitle', type: 'string'}
                      ,{name: 'duration', type: 'int'}
                      ,{name: 'day', type:'date', dateFormat:'timestamp'}
                      ,{name: 'unviewed', type: 'int'}
                      ,{name: 'type', type: 'string'}
                      ,{name: 'group', type: 'int'}
                      ,{name: 'fulltitle', type: 'string'}
                      ,{name: 'isrecording', type: 'int'}
                      ,{name: 'description', type: 'string'}
                      ,{name: 'preview', type: 'string'}
                      ,{name: 'cutlength', type: 'int'}
                      //*** filled later by rdisplay ***
                      ,{name: 'channel', type: 'string'}
                      ,{name: 'marks', type: 'string'}
                      ,{name: 'lifetime', type: 'int'}
                      ,{name: 'priority', type: 'int'}
                      ,{name: 'keywords', type: 'string'}
                    ]
                })
            ,proxy : new Ext.data.HttpProxy({
                 url: XXV.help.baseURL()
                ,method: 'POST'
            })
    });
};

Ext.xxv.recordingsDataView = function(viewer, preview, store, config) {
    this.viewer = viewer;
    this.preview = preview;
    Ext.apply(this, config);
    // create the data store
    this.store = store;
    var tpl = new Ext.XTemplate(
    '<tpl for=".">',
      '<div class="thumb-wrap" id="{id}">',
        '<div class="thumb">',
        '<tpl if="isrecording == 0">',
            '<img src="pic/folder.png"<tpl if="group != 0"> ext:qtitle="{shortTitle}" ext:qtip="{ToolTip}"</tpl>/>',
        '</tpl>',
        '<tpl if="isrecording != 0">',
          '<tpl if="this.isRadio(type)">',
              '<img src="pic/radio.png" ext:qtitle="{shortTitle}" ext:qtip="{ToolTip}" />',
          '</tpl>',
          '<tpl if="this.isRadio(type) == false">',
              '<tpl if="frame == -1">',
                  '<img src="pic/movie.png" ext:qtitle="{shortTitle}" ext:qtip="{ToolTip}" />',
              '</tpl>',
              '<tpl if="frame != -1">',
                  '<img src="?cmd=ri&data={id}_{frame}" ext:qtitle="{shortTitle}" ext:qtip="{ToolTip}" />',
              '</tpl>',
          '</tpl>',
        '</tpl>',
        '<tpl if="unviewed != 0">',
            '<div class="unviewed"></div>',
        '</tpl>',
      '</div>',
      '<span class="x-editable">{shortName}</span></div>',
    '</tpl>',
    '<div class="x-clear"></div>', {
         isRadio: function(name){
             return name == 'RADIO';
         }
      }
    );

    this.filter = new Ext.ux.grid.Search({
         position:'owner'
        ,shortcutKey:null
        ,paramNames: {
              fields:'cmd'
              ,all:'rl'
              ,cmd:'rs'
              ,query:'data'
        }
    });

    Ext.xxv.recordingsDataView.superclass.constructor.call(this, {
                    region: 'center'
                    ,store: store
                    ,tpl: tpl
                    ,cls: 'x-panel-body' // workaround - add missing border
                    ,style: 'overflow:auto'
                    ,multiSelect: true
                    ,overClass:'x-view-over'
                    ,itemSelector:'div.thumb-wrap'
                    ,prepareData: function(data){
                      if(data.id != 'up' && this.store.baseParams.data && this.store.baseParams.cmd == 'rl') {

                        var Woerter = data.fulltitle.split("~");
                        var last = this.store.baseParams.data.split("~");
                        var i = (Woerter.length > last.length) ? last.length : (Woerter.length - 1);
                        var title = '';
                        for(len = Woerter.length; i < len; i++){
                          if(title.length) { title += '~'; }
                          title += Woerter[i];
                        }
                        data.shortName = Ext.util.Format.ellipsis(title, 16);
                      } else {
                        data.shortName = Ext.util.Format.ellipsis(data.fulltitle, 16);
                      }
                      data.shortTitle = Ext.util.Format.ellipsis(data.fulltitle, 40).replace(/\"/g,'\'');

                      if(data.isrecording) {
                        var frames = data.preview.split(",");
                        if(data.preview.length && frames.length) {
                          var item = (frames.length) / 2;
                          data.frame = frames[item.toFixed(0)];
                        } else {
                          data.frame = -1;
                        }

                        data.ToolTip = String.format(this.szRecordingTip, 
                            Ext.util.Format.date(data.day), 
                            String(new Date(data.day.getTime()).dateFormat('H:i')), 
                            String(new Date(data.day.getTime() + (data.duration * 1000)).dateFormat('H:i')), 
                            SecondsToHMS(data.duration),
                            Ext.util.Format.ellipsis(data.description, 50).replace(/\"/g,'\'')
                        );
  
                      } else {
                        if(data.unviewed) {
                          if(data.unviewed == 1) {
                            data.ToolTip = String.format(this.szFolderTip1, 
                                String(data.group), 
                                String(data.unviewed), 
                                SecondsToHMS(data.duration)
                            );
                          } else {
                            data.ToolTip = String.format(this.szFolderTip2, 
                                String(data.group), 
                                String(data.unviewed), 
                                SecondsToHMS(data.duration)
                            );
                          }
                        } else {
                          data.ToolTip = String.format(this.szFolderTip0, 
                              String(data.group), 
                              SecondsToHMS(data.duration)
                          );
                        }
                      }
                      return data;
                    }
                    ,listeners: {
                        'selectionchange': {fn:this.doClick, scope:this, buffer:100}
                         ,'contextmenu'    : {fn:this.onContextClick, scope:this}
                        ,'dblclick'       : {fn:this.doDblclick, scope:this}
//                      ,'loadexception'  : {fn:this.onLoadException, scope:this}
                         ,'beforeselect'   : {fn:function(view){ return view.store.getRange().length > 0; } }
                    }
                   ,plugins: [
                      new Ext.DataView.DragSelector()                   //,new Ext.DataView.LabelEditor({dataIndex: 'fulltitle', allow: 'isrecording'})
                     ,this.filter
                   ]
                  }
  );

  this.store.on({
     'beforeload' : this.onBeforeLoad
    ,'load' : this.onLoad
    ,'loadexception' : this.onLoadException
    ,scope:this
  });
};

Ext.extend(Ext.xxv.recordingsDataView,  Ext.DataView, {

     szTitle         : "Recordings"
    ,szToolTip       : "Display recordings"
    ,szFindReRun     : "Find rerun"
    ,szEdit          : "Edit"
    ,szCut           : "Cut"
    ,szConvert       : "Convert"
    ,szDelete        : "Delete"
    ,szRecover       : "Recover deleted recordings"
    ,szStream        : "Stream recording"
    ,szPlay          : "Playback"
    ,szLoadException : "Couldn't get data about recording!\r\n{0}"
    ,szCutSuccess    : "Recordings started cutting process successful.\r\n{0}"
    ,szCutFailure    : "Couldn't start cutting process recordings!\r\n{0}"
    ,szDeleteSuccess : "Recordings deleted successful.\r\n{0}"
    ,szDeleteFailure : "Couldn't delete recordings!\r\n{0}"
    ,szPlayBackSuccess : "Recording started playback successful.\r\n{0}"
    ,szPlayBackFailure : "Couldn't started playback recording!\r\n{0}"
    ,szUpgrade        : "Update list of recordings"
    ,szUpgradeWait    : "Please wait..."
    ,szUpgradeSuccess : "List of recordings update successful.\r\n{0}"
    ,szUpgradeFailure : "Couldn't update list of recordings!\r\n{0}"
    ,szDetailsFailure : "Couldn't update details of recording!\r\n{0}"
    ,szRecordingTip   : "{0} {1} - {2} ({3})<br />{4}"
    ,szFolderTip0     : "There are {0} recordings<br />Total time {1}"
    ,szFolderTip1     : "There are {0} recordings<br />Have a new recording<br />Total time {2}"
    ,szFolderTip2     : "There are {0} recordings<br />Have {1} new recordings<br />Total time {2}"

    ,onLoadException :  function( scope, o, arg, e) {
      new Ext.xxv.MessageBox().msgFailure(this.szLoadException, e.message);
    }
    ,onBeforeLoad :  function( scope, params ) {
      if(this.DetailsTransaction) 
        Ext.Ajax.abort(this.DetailsTransaction);
      this.preview.clear();
    }
    ,onLoad :  function( store, records, opt ) {

      // Add folder to go to back folder
      if(store.baseParams && store.baseParams.data) {
        var Recording = Ext.data.Record.create( store.fields.items );
        store.insert(0,[new Recording(
              {id: 'up',
               eventid: 0,
               title: '..',
               subtitle: '',
               duration: 0,
               day: new Date(), 
               unviewed: 0,
               type: '',
               group: 0,
               fulltitle: '..',
               isrecording: 0,
               description: '',
               preview: ''},'up')]);
      }

      // Show details from first recording
      for(var i = 0, len = store.getCount(); i < len; i++){
        var record = store.getAt(i);
          if(record.data.isrecording !== 0) {
            this.showDetails(record);
            //this.select(record.data.id,false,false);
            break;
          }
       }
       if(store.reader.meta.param) {
        var tb = this.ownerCt.getTopToolbar();
        //tb.displayMsg = store.reader.meta.param.usage;
        //tb.displayMsg += ' - ';
        //tb.displayMsg += Ext.PagingToolbar.prototype.displayMsg;
       }
       if(store.title) {
        this.ownerCt.SetPanelTitle(store.title);
        store.title = undefined;
       } else {
        this.ownerCt.SetPanelTitle(this.szTitle);
       }
    }
    ,doSelectKeyword : function(tag) {
       if(tag) {
         delete(this.store.baseParams.data);
         this.store.title = tag;
         this.store.baseParams.cmd = 'rk';
         this.store.baseParams.data = tag;
         this.store.load({params:{start:0, limit:this.store.autoLoad.params.limit}});
       }
    }
    ,doDblclick : function() {
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          var firstNode = selNode[0];
          var record = this.store.getById(firstNode.id);
          if(record) {
            if(record.data.isrecording === 0) {
                var data = this.store.baseParams.data;
                delete(this.store.baseParams.data);
                this.store.baseParams.cmd = 'rl';
                if(record.id == 'up') {
                  if(this.filter.field.isValid()) {
                    this.filter.field.setValue('');
                  }
                  var Woerter = data.split("~");
                  Woerter.pop();
                  var title = Woerter.join('~');
                  if(title != '') {
                    this.store.title = title;
                    this.store.baseParams.data = title;
                  }
                } else {
                  this.store.title = record.data.fulltitle;
                  this.store.baseParams.data = record.data.fulltitle;
                }
                this.store.load({params:{start:0, limit:this.store.autoLoad.params.limit}});
              } else {
                this.EditItem(record);
              }
            }
        }
    },

    doClick : function(){
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          var record = this.store.getById(selNode[0].id);
          this.showDetails(record);
        }
    },
    showDetails : function(record){
        this.preview.content(record,this.filter.getValue());
        this.DetailsItem(record);
    }, 
/******************************************************************************/
    onDetailsSuccess : function( response,options ) 
    { 
        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'object' 
             && o.param) {

            var RecordingsID = options.params.data.split(",");
            for(var j = 0, len = RecordingsID.length; j < len; j++){
              var iSel = this.store.indexOfId(RecordingsID[j]);
              if(iSel === -1 
                || this.store.data.items[iSel].id != o.data.RecordId)
                continue;

              this.store.data.items[iSel].data.description = o.data.Description;
              this.store.data.items[iSel].data.channel  = o.data.Channel;
              this.store.data.items[iSel].data.marks    = o.data.Marks;
              this.store.data.items[iSel].data.lifetime = parseInt(o.data.lifetime,10);
              this.store.data.items[iSel].data.priority = parseInt(o.data.priority,10);
              this.store.data.items[iSel].data.keywords = o.data.keywords;

              var record = this.store.getById(RecordingsID[j]);
              this.preview.update(record,this.filter.getValue());
            }

        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szDetailsFailure, msg);
        }
    },

    onDetailsFailure : function( response,options ) 
    { 
        new Ext.xxv.MessageBox().msgFailure(this.szDetailsFailure, response.statusText);
    },

    DetailsItem : function(record) {
      if(record.data.id == 'up') {
        return;
      }
      if(record.data.priority) { //use cached data
        this.preview.update(record,this.filter.getValue());
        return;
      }
      var toDetails = '';
      if(record && record.data) {
        toDetails = record.data.id;
      } else {
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          for(var i = 0, len = selNode.length; i < len; i++){
            if(selNode[i].id == 'up')
              continue;
            if(toDetails.length) {
              toDetails += ',';
            }
            var r = this.store.getById(selNode[i].id);
            if(!r.data.isrecording) {
              //toDetails += 'all:';
              continue;
            }
            toDetails += r.data.id;
          }
        }
      }
      if(toDetails.length) {
      if(this.DetailsTransaction) 
        Ext.Ajax.abort(this.DetailsTransaction);
      this.DetailsTransaction = Ext.Ajax.request({
            scope: this
           ,url: XXV.help.cmdAJAX('rd')
           ,timeout: 15000
           ,success: this.onDetailsSuccess
           ,failure: this.onDetailsFailure
           ,params:{ data: toDetails }
        });
      }
    },  
/******************************************************************************/
    onContextClick : function(grid, index, node, e){
        if(!this.menu){ // create context menu on first right click
            this.menu = new Ext.menu.Menu({
                id:'grid-ctx',
                items: [
                   {
                     itemId: 're'
                    ,text: this.szEdit
                    ,iconCls: 'edit-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.EditItem(this.ctxRecord); }
                   },{
                     itemId: 'rcu'
                    ,text: this.szCut
                    ,iconCls: 'cut-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.CutItem(null); }
                   },{
                     itemId: 'rc'
                    ,text: this.szConvert
                    ,iconCls: 'convert-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.ConvertItem(this.ctxRecord); }
                   },{
                     itemId: 'rr'
                    ,text: this.szDelete
                    ,iconCls: 'delete-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function() { this.DeleteItem(null); }
                   },'-',{
                     itemId: 's'
                    ,text: this.szFindReRun
                    ,iconCls: 'find-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.viewer.searchTab(this.ctxRecord);}
                   },'-',{
                     itemId: 'pre'
                    ,text: this.szStream
                    ,iconCls: 'stream-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.onStream(this.ctxRecord,'00:00:00');}
                   },{
                     itemId: 'rpv'
                    ,text: this.szPlay
                    ,iconCls: 'play-icon'
                    ,scope:this
                    ,disabled: true
                    ,handler: function(){ this.onPlay(this.ctxRecord,'00:00:00');}
                   }
                ]
            });
            this.menu.on('hide', this.onContextHide, this);
        }
        e.stopEvent();
        if(this.ctxRow){
            //Ext.fly(this.ctxRow).removeClass('x-view-selected');
            this.ctxRow = null;
        }
        this.ctxRow = node;
        var record = this.store.getById(node.id);
        this.select(node.id,true,false);

        var items = this.menu.items;
        if(items) { 
          items.eachKey(
            function(key, f) {
              var enable = XXV.help.cmdAllowed(f.itemId);
              if(enable) {
                switch(f.itemId) {
                  case 're':  enable = (record.data.isrecording) ? true : false; break;
                  case 'rcu': enable = (record.data.isrecording) ? true : false; break;
                  case 'rc':  enable = (record.data.isrecording) ? true : false; break;
                  case 'rpv': enable = (record.data.isrecording) ? true : false; break;
                  case 'pre': enable = (record.data.isrecording) ? true : false; break;
                }
                if(enable && node.id != 'up') {
                  f.enable();
                }
              }
            },items); 
        }
        this.ctxRecord = record;

        //Ext.fly(this.ctxRow).addClass('x-view-selected');
        this.menu.showAt(e.getXY());
    },

    onContextHide : function(){
        if(this.ctxRow){
            Ext.fly(this.ctxRow).removeClass('x-view-selected');
            this.ctxRow = null;
        }
        if(this.menu) {
          this.menu.destroy();
          delete this.menu;
          this.menu = null;
        }
    },

/******************************************************************************/
    onCutSuccess : function( response,options ) 
    { 
        this.viewer.loadMask.hide();

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {

            new Ext.xxv.MessageBox().msgSuccess(this.szCutSuccess, o.data);

        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szCutFailure, msg);
        }
    },

    onCutFailure : function( response,options ) 
    { 
        this.viewer.loadMask.hide();

        new Ext.xxv.MessageBox().msgFailure(this.szCutFailure, response.statusText);
    },

    CutItem : function(record) {

      var toCut = '';
      if(record && record.data) {
        toCut = record.data.id;
      } else {
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          for(var i = 0, len = selNode.length; i < len; i++){
            if(selNode[i].id == 'up')
              continue;
            if(toCut.length) {
              toCut += ',';
            }
            var r = this.store.getById(selNode[i].id);
            if(!r.data.isrecording) {
              //toCut += 'all:';
              continue;
            }
            toCut += r.data.id;
          }
        }
      }
      if(toCut.length) {
        this.viewer.loadMask.show();
        Ext.Ajax.request({
            scope: this
           ,url: XXV.help.cmdAJAX('rcu')
           ,timeout: 15000
           ,success: this.onCutSuccess
           ,failure: this.onCutFailure
           ,params:{ data: toCut }
        });
      }
    },  
/******************************************************************************/
    onDeleteSuccess : function( response,options ) 
    { 
        this.viewer.loadMask.hide();

        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {

            new Ext.xxv.MessageBox().msgSuccess(this.szDeleteSuccess, o.data);

            var RecordingsID = options.params.data.split(",");
            var selRecord;
            var iSel = 0;

            for(var j = 0, len = RecordingsID.length; j < len; j++){
              var record = this.store.getById(RecordingsID[j].replace(/all:/g, ''));
              if(!record)
                continue;
              iSel = this.store.indexOf(record) - 1;
              this.store.remove(record);
            }
            if(iSel >= 0 && iSel < this.store.getCount()) {
              selRecord = this.store.getAt(iSel);
            }
            if(!selRecord || !selRecord.data.isrecording) {
              for(iSel++;iSel < this.store.getCount();iSel++) {
                selRecord = this.store.getAt(iSel);
                if(selRecord.data.isrecording)
                  break;
              }
            }
            if(selRecord && selRecord.data.isrecording) {
                this.select(selRecord.data.id,false,false);
            }

        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, msg);
        }
    },

    onDeleteFailure : function( response,options ) 
    { 
        this.viewer.loadMask.hide();

        new Ext.xxv.MessageBox().msgFailure(this.szDeleteFailure, response.statusText);
    },

    DeleteItem : function(record) {

      var todelete = '';
      if(record && record.data) {
        todelete = record.data.id;
      } else {
        var selNode = this.getSelectedNodes();
        if(selNode && selNode.length > 0){
          for(var i = 0, len = selNode.length; i < len; i++){
            if(selNode[i].id == 'up')
              continue;
            if(todelete.length) {
              todelete += ',';
            }
            var r = this.store.getById(selNode[i].id);
            if(!r.data.isrecording) {
              todelete += 'all:';
            }
            todelete += r.data.id;
          }
        } 
      }
      if(todelete.length) {
        this.viewer.loadMask.show();
        Ext.Ajax.request({
            scope: this
           ,url: XXV.help.cmdAJAX('rr')
           ,timeout: 15000
           ,success: this.onDeleteSuccess
           ,failure: this.onDeleteFailure
           ,params:{ data: todelete }
        });
      }
    },
/******************************************************************************/
  onPlaySuccess : function( response,options ) 
  { 
      var json = response.responseText;
      var o = eval("("+json+")");
      if(!o || !o.data || typeof(o.data) != 'string') {
        throw {message: "Ajax.read: Json message not found"};
      }
      if(o.success) {
          new Ext.xxv.MessageBox().msgSuccess(this.szPlayBackSuccess, o.data);
      }else {
          new Ext.xxv.MessageBox().msgFailure(this.szPlayBackFailure, o.data);
      }
  },

  onPlayFailure : function( response,options ) 
  { 
      new Ext.xxv.MessageBox().msgFailure(this.szPlayBackFailure, response.statusText);
  },

  onPlay : function( record, begin ) {
      if(this.PlayTransaction) Ext.Ajax.abort(this.PlayTransaction);
      if(record.data.isrecording) {
        this.PlayTransaction = Ext.Ajax.request({
            url: XXV.help.cmdAJAX('rpv',{ data: record.data.id, '__start':begin, '__vdr': XXV.menu.host })
           ,success: this.onPlaySuccess
           ,failure: this.onPlayFailure
           ,scope: this
        });
      }
  },
/******************************************************************************/
  onStream : function( record, begin ) {
    var item = {
       url  : XXV.help.cmdHTML('pre',{data:record.data.id,'__player':'1','__start':begin})
      ,title: record.data.fulltitle
    };
    this.viewer.streamwin = Ext.xxv.createStream(item,this.viewer.streamwin);
  }
  /******************************************************************************/
    ,EditItem : function( record ) {

      var item = {
         cmd:   're'
        ,id:    record.data.id
        ,title: this.szEdit + " : " + record.data.fulltitle
      };

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this.store);
    }
    ,ConvertItem : function(record) {

      var item = {
         cmd:   'rc'
        ,id:    record.data.id
        ,title: this.szConvert + " : " + record.data.fulltitle
      };

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this.store);
    }
    ,Recover : function() {

      var item = {
         cmd:   'rru'
      };

      if(this.viewer.formwin){
        this.viewer.formwin.close();
      }
      this.viewer.formwin = new Ext.xxv.Question(item,this.store.reload,this.store);
    }
/******************************************************************************/
    ,onUpgradeSuccess : function( response,options ) 
    { 
        Ext.MessageBox.hide();
        var o = eval("("+response.responseText+")");

        if(o && o.data && typeof(o.data) == 'string' 
             && o.success) {

            new Ext.xxv.MessageBox().msgSuccess(this.szUpgradeSuccess, o.data);
            this.reload();

        } else {
            var msg = '';
            if(o && o.data && typeof(o.data) == 'string') {
              msg = o.data;
            }
            new Ext.xxv.MessageBox().msgFailure(this.szUpgradeFailure, msg);
        }
    }
    ,onUpgradeFailure : function( response,options ) 
    { 
        Ext.MessageBox.hide();
        new Ext.xxv.MessageBox().msgFailure(this.szUpgradeFailure, response.statusText);
    }
    ,UpgradeItem : function() {
      Ext.Ajax.request({
        scope: this
       ,url: XXV.help.cmdAJAX('ru')
       ,timeout: 120000
       ,success: this.onUpgradeSuccess
       ,failure: this.onUpgradeFailure
      });

      Ext.MessageBox.show({
           title: this.szUpgradeWait
           ,msg: this.szUpgrade
           ,width:240
           ,wait:true
           ,waitConfig:{
              interval:200
            ,duration:119000
            ,increment:15
            ,fn:function() {
              Ext.MessageBox.hide();
            }
           }
       });
    }
    ,reload : function() {
        this.store.load({params:{start:0, limit:configuration.pageSize}});
    }

});

function createRecordingsView(viewer,id) {

    var timefield = new Ext.form.TimeField({ 
                 id:'timeline'
                ,mode:'local'
                ,width: 100
                ,format: 'H:i:s'
                ,value: '00:00:00'
                ,minValue: minTime()
                ,increment:5
                ,listeners: {
                  'expand': function(combo){
                      this.store.filterBy(function(record){ 
                        var b = combo.minValue;
                        var e = combo.maxValue;
                        var t = Date.parseDate(combo.initDate + ' ' + record.get('text'), combo.initDateFormat + ' ' + combo.format);
                        return t.between(b,e);
                      });
                    }
                }
    });
    
    var preview = new Ext.Panel({
        id: 'preview-recordings',
        region: 'south',
        cls:'preview',
        autoScroll: true,
        stateful:false,
        timefield : timefield,
        layout: {
            type:'vbox'
            ,padding:'0'
            ,align:'stretch'
            ,autoScroll: true
        }
        ,defaults:{margins:'0 0 0 0'}
        ,items: [
             { //header
                   xtype:'container'
                  ,height:     50
                  ,items: [{                  
                    autoWidth: true,
                    xtype:'RecHeader'}
                  ]
             },{ //images
                id:         'preview-recordings-images'
               ,xtype:      'box'
               ,height:     130
               ,listeners:{ 'SelectImage': function(slide, time, e, ele){ viewer.gridRecordings.preview.timefield.setValue(time); } }
             },{ //timeslide
                 id:'preview-recordings-slide'
                ,margins:'0 16 0 16'
                ,height:  32
                ,baseCls : 'x-slide'
                ,items: [{                  
                  xtype:'MarksSlider'
                 ,duration:  100
                 ,listeners:{ 'MoveSlider': function(slide, time, e, ele){ viewer.gridRecordings.preview.timefield.setValue(time); } }
                }]
             },{ //content
               id:          'preview-recordings-frame'
              ,cls:         'preview-body'
              ,xtype:       'box'
              ,flex:        3
             },{ // keywords
                 xtype:'container'
                ,height:  80
                ,items: [{                  
                   autoWidth: true
                  ,xtype:'TagClouds'
                  ,listeners:{ 'selectKeyword': function(tag) { viewer.gridRecordings.doSelectKeyword(tag); } }
                }]
             }],
        tbar: [
        {
             id:'s'
            ,iconCls: 'find-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szFindReRun
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.searchTab(this.gridRecordings.preview.record); }
        }
        ,'-'  
        ,{
             id:'re'
            ,iconCls: 'edit-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szEdit
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.EditItem(this.gridRecordings.preview.record);  }
        }
        ,{
             id:'rcu'
            ,iconCls: 'cut-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szCut
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.CutItem(this.gridRecordings.preview.record);  }
        }
        ,{
             id:'rc'
            ,iconCls: 'convert-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szConvert
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.ConvertItem(this.gridRecordings.preview.record);  }
        }
        ,{
             id:'rr'
            ,iconCls: 'delete-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szDelete
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.DeleteItem(this.gridRecordings.preview.record);  }
        }
        ,"->"
        ,{
             id:'pre'
            ,iconCls: 'stream-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szStream
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.onStream(this.gridRecordings.preview.record, this.gridRecordings.preview.timefield.getValue() );  }
        }
        ,{
             id:'rpv'
            ,iconCls: 'play-icon'
            ,tooltip: Ext.xxv.recordingsDataView.prototype.szPlay
            ,scope: viewer
            ,disabled:true
            ,handler: function(){ this.gridRecordings.onPlay(this.gridRecordings.preview.record, this.gridRecordings.preview.timefield.getValue() );  }
        }
        , timefield
        ]
        ,content : function(record,lookup){

            if(record && this.record != record
                && record.data.isrecording 
                //&& this.body 
                //&& this.ownerCt.isVisible()
                ) {
                  this.record = record;
                  //header    
                  this.get(0).get(0).setvalue(record.data,lookup);

                  this.timefield.maxValue = new Date((this.timefield.minValue.getTime())+(record.data.duration * 1000));
                  this.timefield.setValue(this.timefield.minValue);
  
                  // Enable all toolbar buttons
                  var items = this.topToolbar.items;
                  if(items) { 
                    items.eachKey(function(key, f)
                      {
                        if(key == 'timeline' 
                           && (XXV.help.cmdAllowed('pre') || XXV.help.cmdAllowed('rpv'))) { 
                          f.enable();                        
                        } else if(XXV.help.cmdAllowed(key)) 
                          f.enable();
                      }
                    ,items); 
                  }

                  var content = Ext.getDom("preview-recordings-frame");
                  content.innerHTML = record.data.description.replace(/\r\n/g, '<br />');
                  if(lookup)
                    highlightText(content,lookup,'x-highlight',1);
                  this.doLayout();
                }
        } 
        ,update : function(record,lookup) {
            if(record
                && record.data.isrecording 
                && this.body 
                && this.ownerCt.isVisible()) {
                  this.record = record;

                  this.get(0).get(0).setvalue(record.data,lookup);
                  var content = Ext.getDom("preview-recordings-frame");
                  content.innerHTML = record.data.description.replace(/\r\n/g, '<br />');
                  if(lookup)
                    highlightText(content,lookup,'x-highlight',1);

                  if(!this.tplimg) {
                    this.tplimg = new Ext.Template('{day:date} - {start} ({period})');
                    this.tplimg.compile();  
                  }

                  this.remove(1);
                  var pic = new Array();
  
                  if(record.data.preview && record.data.preview.length > 0) {
                    var frames = record.data.preview.split(",");
                    Ext.each(frames, function(frame){ 
                      var u = "?cmd=ri&data="+record.data.id+"_"+frame;
                      var d = new Date(record.data.day.getTime() + (frame * 40));
                      var t = SecondsToHMS((frame * 40)/1000);
                      var q = this.tplimg.applyTemplate({ 
                                 day:     d
                                ,start:   d.dateFormat('H:i')
                                ,period:  t
                              });
                      pic.push({
                             frame:   frame
                            ,width:  160
                            ,html: "<img width='160px' src='"+ u + "' 'ext:qtip='" + q + "'>"
                        });
                    },this);
                  } else if(record.data.type == 'RADIO'){
                      pic.push({
                             frame:   0
                            ,width:  160
                            ,html: "<img width='160px' src='pic/radio.png'>"
                        });
                  } else {
                      pic.push({
                             frame:   0
                            ,width:  160
                            ,html: "<img width='160px' src='pic/movie.png'>"
                        });
                  } 
                  this.insert(1,new Ext.Container( {
                                id:         'preview-recordings-images'
                               ,height:     130
                               ,layoutConfig: {
                                    scrollButtonPosition:'split',
                                    marginScrollButtons: 1,
                                    pagedScroll: false
                                }
                                ,layout: 'carousel'
                                ,items: pic
                            }));


                  this.get(2).get(0).setvalue(record.data.marks,record.data.duration);
                  // Keywords
                  this.get(4).get(0).setvalue(record.data.keywords);
                  var height = record.data.keywords && record.data.keywords.length ? 80 : 0;
                  if(this.get(4).getHeight() != height) {
                    this.get(4).suspendEvents(false);
                    this.get(4).setHeight(height);
                    this.get(4).resumeEvents();
                  }
                  this.doLayout();
/*
                  var root = Ext.getCmp('preview-recordings-images');
                  var images = root.select('img');
                  Ext.each(images, function(image){            
                    this.get(1).on("click", function(e, ele){
                      if (!image.onSelected || !(image.onSelected.call(this, image, e, ele )===false)){
                        this.fireEvent('selected', this, new Date(minTime().getTime()+(image.frame * 40)), e, ele);

                        var slider = this.get(2).get(0).getSlider('cutpoint_thumb');
                        slider.value = pic.frame/25;
                        this.get(2).get(0).slider.initSliderPosition(slider);
                      }
                    },this);
                  });
*/
            }
        }
        ,clear: function(){
            if(this) {
              //if(this.body)
              //  this.body.update('');
              this.record = null;
              // Disable all toolbar buttons
              var items = this.topToolbar.items;
              if(items) {
                  items.eachKey(function(key, f){f.disable();},items); 

              }
            }
        }
    });

    viewer.gridRecordings = new Ext.xxv.recordingsDataView(
                            viewer,
                            preview,
                            new Ext.xxv.recordingsStore(),
                            { id: 'recording-view-grid' });

    var tab = new Ext.xxv.Panel({
       id: id
      ,iconCls:"recordings-icon"
      ,closable:true
      ,border:false
      ,layout:'border'
      ,stateful:true
      ,items:[ 
            viewer.gridRecordings
            ,{
               id:'recording-bottom-preview'
              ,layout:'fit'
              ,items:XXV.BottomPreview ? 0 : viewer.gridRecordings.preview
              ,height: 250
              ,split: true
              ,border:false
              ,region:'south'
              ,hidden:XXV.BottomPreview
            }, {
               id:'recording-right-preview'
              ,layout:'fit'
              ,items:XXV.RightPreview ? 0 : viewer.gridRecordings.preview
              ,border:false
              ,region:'east'
              ,width:350
              ,split: true
              ,hidden:XXV.RightPreview
            }]
      ,tbar:new Ext.PagingToolbar({
             pageSize: viewer.gridRecordings.store.autoLoad.params.limit
            ,store: viewer.gridRecordings.store
            ,displayInfo: true
            ,items: [
              {
                   id:'ru'
                  ,iconCls: 'upgrade-icon'
                  ,tooltip: viewer.gridRecordings.szUpgrade
                  ,scope: viewer.gridRecordings
                  ,disabled:false
                  ,handler: function(){ this.UpgradeItem(); }
              },{
                   id:'rru'
                  ,iconCls: 'recover-icon'
                  ,tooltip: viewer.gridRecordings.szRecover
                  ,scope: viewer.gridRecordings
                  ,disabled:false
                  ,handler: function(){ this.Recover(); }
                }
              ]}
            )
    });

    viewer.add(tab);
    return tab;
}

