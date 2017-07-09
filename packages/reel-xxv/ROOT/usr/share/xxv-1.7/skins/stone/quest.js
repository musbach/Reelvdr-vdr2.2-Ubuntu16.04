
var questfn = null;
function questcontent(title, text, image){
  var utitle = unescape(title);
  var content =  '<table class="areatable" summary=""><tr><td class="areahead"><div class="editorhead">';
  content += utitle.substr(0,50);
  if (utitle.length > 50)  {content += '...';}
  content += '</div><div id="shutter">';
  content += '<a href="javascript:questclose(0)">';
  content += '<img tabindex="2" src="images/close.gif" alt="" />';
  content += '</a>';
  content += '</div>';
  content += '</td></tr><tr><td class="areatext"><font class="title">';
  content += '<ul>';
  for(var i=0;i<text.length;++i) {
    content += '<li>';
    content += unescape(text[i]);
    content += '</li>';
  }
  var imageExt = ie5&&!opera ? "gif" : "png";
  content += '</ul></font>';
  content += '<font class="title" style="float:right;padding-right:2em;">';
  content += '<a href="javascript:questclose(1)">';
  content += '<img src="images/'+ image +'.'+ imageExt +'" alt="'+ title +'" />';
  content += '</a></font></td></tr>';
  content += '<tr><td class="areabottom"></td></tr></table>';
  return content;
}

function questkeypress(e) {
  var KeyID = (window.event) ? event.keyCode : e.keyCode;
  if(questfn) {
    if(KeyID == 27) { //ESC
      questclose(0);
    } else if(KeyID == 13) { //ENTER
      questclose(1);
    }
  }
}

var lastKeypress = null;
function quest(title, text, center, image) {
  ttp_enable(0);
  lastKeypress = document.onkeypress;
  document.onkeypress = questkeypress;

  var Size = WindowSize();
  var x0;
  var y;

  var ele = document.getElementById('TOOLTIP');
  var scrPos = getScrollingPosition();

  if(center) {
    x = ((Size[0] / 2) - 200) + scrPos[0];
    y =  (Size[1] / 4) + scrPos[1];
  } else {
    x = ttp_x - 200;
    y = ttp_y - 50;
  }

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
      if(ie5&&!opera) ele.style.removeAttribute('bottom');
    	else ele.style.bottom  = '';
  		ele.style.top  = (y + 20) + "px";
  }
	ele.style.left = x + "px";

	ele.innerHTML = questcontent(title, text, image);
  ele.style.visibility = "visible";
}

function questclose(doit) {
  var ele = document.getElementById('TOOLTIP');
  ele.style.visibility = "hidden";
	ele.innerHTML = '';
  if(questfn && doit) {
    questfn.callback();
    questfn = null;
  }
  document.onkeypress = lastKeypress;
  lastKeypress = null;
  ttp_enable(1);
}

// Question bevor delete
function sure(question, text, cmd, data) {
    function fn() {
      this.callback=function() {
        var url = "?cmd=" + cmd + "&data=" + data;
        if(ie5&&!opera) //Avoid use cache
          url += "&random=" + (Math.random() * Date.parse(new Date()));
        location.href = url;
      }
    }
    questfn=new fn();
    quest(question,[text],0,'delete');
}

function di(url, wert) {
    location.href = url + wert;
}

// Question bevor delete
function sureandreload(question, text, cmd, data) {
    function fn() {
      this.callback=function() {
          fire(cmd,data);
      }
    }
    questfn=new fn();
    quest(question,[text],0,'delete');
}

// Question bevor delete
function surecmd(question,text,cmd,data,width,height) {
    function fn() {
      this.callback=function() {
          popup(cmd,data,width,height,1);
      }
    }
    questfn=new fn();
    quest(question,[text],0,'delete');
}

function DoitReally(question,warnmsg,cmd,form,width,height,image) {
// collect checked boxes
    ok = new Array;
    txt = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' 
            && form.elements[i].checked 
            && form.elements[i].name != '__selfield__') {
            id = form.elements[i].value;
            ok.push(id);
            if(txt.length < 20)
                txt.push(form.elements[i].name);
            form.elements[i].checked = 0;
            x += 1;
        }
    }
    if(x > 0) {
        if(txt.length >= 20)
              txt.push("...");

        function fn() {
          this.callback=function() {
            popup(cmd,ok.join('_'),width,height,1);
          }
        }
        questfn=new fn();
        quest(question,txt,1,image);
    } else {
        function none() { this.callback=function() { } }
        questfn=new none();
        txt.push(warnmsg);
        quest(question,txt,1,'off');
    }
}
