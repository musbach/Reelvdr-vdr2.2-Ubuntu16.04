var ttp_content;
ttp_content = "";

var ttp_timer;
var ttp_x = -1;
var ttp_y = -1;
var ttp_visable = 0;
var ttp_offset_x = 0;
var ttp_x_start = -1;
var ttp_y_start = -1;
var ttp_active  = 1;
var ttp_inside  = 0;

var ie5=document.all&&document.getElementById;
var ns6=document.getElementById&&!document.all;
var opera =window.opera;
var dom=(!opera && document.compatMode && document.compatMode!="BackCompat");

function iecompattest(){
    return dom ? document.documentElement : document.body
}

function getScrollingPosition() {
 var x = 0, y = 0;
  if( ns6 || typeof( window.pageYOffset ) == 'number' ) {
    y = window.pageYOffset;
    x = window.pageXOffset;
  } else {
    y = iecompattest().scrollTop;
    x = iecompattest().scrollLeft;
  }
  return [ x, y ];
}

function WindowSize () {
  var width = 0, height = 0;
  if( ns6 || typeof( window.innerWidth ) == 'number' ) {
    width = window.innerWidth;
    height = window.innerHeight;
  } else {
    width = iecompattest().clientWidth;
    height = iecompattest().clientHeight;
  }
  return [ width, height ];
}

function ttp_update_pos(){
    var Size = WindowSize();

    var x = ttp_x + ttp_offset_x;
    var y = ttp_y;

    var ele = document.getElementById('TOOLTIP');
    var scrPos = getScrollingPosition();
    
    if(x + 500 > Size[0] + scrPos[0]) {
      x = Size[0] - 500;
    }
    if(y + 150 > Size[1] + scrPos[1]) {
      y = Size[1] - (y - 10);
      ele.style.top  = '';
      if(ie5&&!opera) {
        ele.style.removeAttribute('top');
        y += scrPos[1];
      }
  		ele.style.bottom  =  y + "px";
    } else {
      ele.style.bottom  = '';
      if(ie5&&!opera) {
        ele.style.removeAttribute('bottom');
      }
  		ele.style.top  = (y + 20) + "px";
    }
		ele.style.left = x + "px";
}

var ttp_ie = document.all?true:false;
//Netscape 4.0 only 
//if (!ttp_ie) document.captureEvents(Event.MOUSEMOVE)
document.onmousemove = ttp_onmousemove;

function ttp_onmousemove(e) {
if (ttp_ie) { 
  ttp_x = event.clientX + document.body.scrollLeft;
  ttp_y = event.clientY + document.body.scrollTop;
} else { 
  ttp_x = e.pageX;
  ttp_y = e.pageY;
}
if (ttp_x < 0)  {ttp_x = 0;}
if (ttp_y < 0)  {ttp_y = 0;}

if(ttp_visable) {
  if(Math.abs(ttp_x_start - ttp_x) > 15
   || Math.abs(ttp_y_start - ttp_y) > 15) {
    ttp_make_invisable();
  }
  ttp_update_pos();
  }
}

function ttp_update_content(title, description, style){
  var utitle = unescape(title);
  ttp_content =  '<div id="ttwindow"><p class="topic">';
  ttp_content += utitle.substr(0,50);
  if (utitle.length > 50)  {ttp_content += '...';}
  ttp_content += '</p><p class="' + style +'">';
  if(description == 'WAIT') {
    ttp_content += '<img src="images/wait.gif" alt="" />';
  } else {
    ttp_content += unescape(description);
  }
  ttp_content += '</p></div>';
}

function ttp_make_visable(title, description, style){
		ttp_update_pos();
		ttp_update_content(title, description, style);
    var ele = document.getElementById('TOOLTIP');
		ele.innerHTML = ttp_content;
		ele.style.visibility = "visible";
}

function ttp_make_invisable(){
    var ele = document.getElementById('TOOLTIP');

    if(ttp_visable || ele.style.visibility == "visible") {
      clearTimeout(ttp_timer);
	  	ele.style.visibility = "hidden";
    }
    ttp_visable = 0;
    ttp_inside = 0;
}

function ttp_enable(enable){
  ttp_make_invisable();
  ttp_active = enable
}

function ttp_make_req_visable(title, eventid, x, y){

    if(!eventid || eventid<=0 || ttp_inside==0
      || Math.abs(x - ttp_x) > 15
      || Math.abs(y - ttp_y) > 15) {
        clearTimeout(ttp_timer);
        ttp_inside = 0;
        return false;
    }

    ttp_x_start = ttp_x;
    ttp_y_start = ttp_y;
    ttp_make_visable(title,'WAIT','description');

    var fnWhenDone = function (oXML, sData) {

        var description = eval('(' + oXML.responseText + ')');
        var content;
        if(description && description.data && typeof(description.data) == 'string'){
            content = description.data.replace(/\r\n/g,'<br />');
        } else {
            content = '...';
        }

        ttp_make_visable(title,content,'description');
    };

    var url = "?cmd=edescription&data=" + eventid + "&ajax=json";
    var aconn = new XHRequest();
    if(!aconn)
      return false;
    return aconn.connect(url, fnWhenDone, eventid);
}


function ttpreq(self, title, eventid, offset_x){
  if(ttp_active) {
    self.onmouseout=function(){ ttp_make_invisable(); };
  	if(eventid && ttp_x != -1 && ttp_y != -1){
      ttp_offset_x  = offset_x;
      ttp_inside = 1;
      ttp_timer = setTimeout("ttp_make_req_visable('"+escape(title)+"', '"+eventid+"', '"+ttp_x+"', '"+ttp_y+"')", 750);
  	}
  }
}


function ttp_make_tlist_visable(title, tlist, x, y){

    if(!tlist || ttp_inside==0
      || Math.abs(x - ttp_x) > 15
      || Math.abs(y - ttp_y) > 15) {
        clearTimeout(ttp_timer);
        ttp_inside = 0;
        return false;
    }

    ttp_x_start = ttp_x;
    ttp_y_start = ttp_y;
    ttp_make_visable(title,'WAIT','title');

    var fnWhenDone = function (oAnswer, sData) {
        var content = "";
        var values = eval('(' + oAnswer.responseText + ')');
        if(values && values.data && typeof(values.data) == 'object'){
          for (var i = 0; i < values.data.length; i++) {
            var x = values.data[i];
            var len = 23;

            if ((x[1] & 1) == 0) { //Status
              content += '<span class="deactive">';
            }
            //var d = new Date(x[9] * 1000);
            var d = new Date(x[4] * 1000);
            if(0) {
              content += d.getDate() + "/" + (d.getMonth()+1) + "/" + (d.getYear() + 1900); //Day
            } else {
              content += d.getDate() + "." + (d.getMonth()+1) + "." + (d.getYear() + 1900); //Day
            }
            content += " - ";
            content += x[5]; //Start
            content += "-";
            content += x[6]; //Stop
            content += " - ";
            if (x[2].length > 15) {//Channel
              content += x[2].substring(0, 13);
              content += '...';
            } else {
              content += x[2]; 
            }
            if ((x[2].length + x[7].length) > 30) {
              content += "<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
              len = 50;
            } else {
              content += " - ";
            }
            if (x[7].length > len) {
              content += x[7].substring(0, len-2);
              content += '...';
            } else {
              content += x[7]; //File
            }
            if ((x[1] & 1) == 0) { //Status
              content += "</span>";
            }
            content += "<br />";
          }
        } else {
            content = '...';
        }

        ttp_make_visable(title,content,'title');
    };

    var url = "?cmd=tlist&data=" + tlist + "&ajax=json";
    var aconn = new XHRequest();
    if(!aconn)
      return false;
    return aconn.connect(url, fnWhenDone, tlist);
}


function ttptlist(self, title, tlist, offset_x){
  if(ttp_active) {
    self.onmouseout=function(){ ttp_make_invisable(); };
  	if(tlist && ttp_x != -1 && ttp_y != -1){
      ttp_offset_x  = offset_x;
      ttp_inside = 1;
      ttp_timer = setTimeout("ttp_make_tlist_visable('"+escape(title)+"', '"+tlist+"', '"+ttp_x+"', '"+ttp_y+"')", 750);
  	}
  }
}
function ttp_make_direct_visable(title, description, x, y){

    if(ttp_inside==0
      || Math.abs(x - ttp_x) > 15
      || Math.abs(y - ttp_y) > 15) {
        clearTimeout(ttp_timer);
        ttp_inside = 0;
        return false;
    }

    ttp_x_start = ttp_x;
    ttp_y_start = ttp_y;
    ttp_make_visable(title,description,'description');
}

function ttp(self, title, description, offset_x){
  if(ttp_active) {
    self.onmouseout=function(){ ttp_make_invisable(); };
  	if(description && ttp_x != -1 && ttp_y != -1){
      ttp_offset_x  = offset_x;
      ttp_inside = 1;
      ttp_timer = setTimeout("ttp_make_direct_visable('"+escape(title)+"', '"+escape(description)+"')", 750);
  	}
  }
}
/** XHRequest based on                                                       **
 ** XHConn - Simple XMLHTTP Interface - bfults@gmail.com - 2005-04-08        **
 ** Code licensed under Creative Commons Attribution-ShareAlike License      **
 ** http://creativecommons.org/licenses/by-sa/2.0/                           **/

function XHRequest()
{
  var xmlhttp, bComplete = false;
  try { xmlhttp = new ActiveXObject("Msxml2.XMLHTTP"); }
  catch (e) { try { xmlhttp = new ActiveXObject("Microsoft.XMLHTTP"); }
  catch (e) { try { xmlhttp = new XMLHttpRequest(); }
  catch (e) { xmlhttp = false; }}}
  if (!xmlhttp) 
    return null;

  this.connect = function(sRequest, fnDone, sData)
              {
                if (!xmlhttp) return false;
                bComplete = false;

                try {
                     xmlhttp.open("GET", sRequest, true);
                     xmlhttp.onreadystatechange = function() 
                          {
                            if (xmlhttp.readyState == 4 && !bComplete)
                            {
                                bComplete = true;
                                fnDone(xmlhttp, sData);
                            }
                          };
                     xmlhttp.send(null);
                } catch(z) { alert(z); return false; }
                return true;
              };
  return this;
}
