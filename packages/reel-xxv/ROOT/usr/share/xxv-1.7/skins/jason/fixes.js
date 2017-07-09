/*
 * jason - Javascript based skin for xxv
 * Copyright(c) 2008-2012, anbr
 * 
 * http://projects.vdr-developer.org/projects/xxv
 *
 */

/* http://extjs.com/forum/showthread.php?p=309913#post309913 */
Ext.override(Ext.form.TimeField, {
    // private
    initDate: '01/01/2008',

    // private
    initDateFormat: 'd/m/Y',

    initComponent : function(){
        Ext.form.TimeField.superclass.initComponent.call(this);

        this.minValue = this.parseDate(this.minValue) || Date.parseDate(this.initDate, this.initDateFormat).clearTime();
        this.maxValue = this.parseDate(this.maxValue) || this.minValue.add('mi', (24 * 60) - 1);

        if(!this.store){
            var times = [],
                min = this.minValue,
                max = this.maxValue;
            while(min <= max){
                times.push([min.dateFormat(this.format)]);
                min = min.add('mi', this.increment);
            }
            this.store = new Ext.data.SimpleStore({
                fields: ['text'],
                data : times
            });
            this.displayField = 'text';
        }
    },
    
    parseDate : function(value){
        if(!value || Ext.isDate(value)){
            return value;
        }
        var v = Date.parseDate(this.initDate + ' ' + value, this.initDateFormat + ' ' + this.format);
        if(!v && this.altFormats){
            if(!this.altFormatsArray){
                this.altFormatsArray = this.altFormats.split("|");
            }
            for(var i = 0, len = this.altFormatsArray.length; i < len && !v; i++){
                v = Date.parseDate(this.initDate + ' ' + value, this.initDateFormat + ' ' + this.altFormatsArray[i]);
            }
        }
        return v;
    }    
});

/* http://www.extjs.com/forum/showthread.php?t=73615 */
Ext.override(Ext.menu.Menu, {
    show: function(el, pos, parentMenu) {
        if (this.floating) {
            this.parentMenu = parentMenu;
            if (!this.el) {
                this.render();
                this.doLayout(false, true);
            }
            //if(this.fireEvent('beforeshow', this) !== false){
            this.showAt(this.el.getAlignToXY(el, pos || this.defaultAlign, this.defaultOffsets), parentMenu, false);
            //}
        } else {
            Ext.menu.Menu.superclass.show.call(this);
        }
    },
    showAt: function(xy, parentMenu, _e) {
        if (this.fireEvent('beforeshow', this) !== false) {
            this.parentMenu = parentMenu;
            if (!this.el) {
                this.render();
            }
            if (_e !== false) {
                xy = this.el.adjustForConstraints(xy);
            }
            this.el.setXY(xy);
            if (this.enableScrolling) {
                this.constrainScroll(xy[1]);
            }
            this.el.show();
            Ext.menu.Menu.superclass.onShow.call(this);
            if (Ext.isIE) {
                this.layout.doAutoSize();
                if (!Ext.isIE8) {
                    this.el.repaint();
                }
            }
            this.hidden = false;
            this.focus();
            this.fireEvent("show", this);
        }
    }
});
