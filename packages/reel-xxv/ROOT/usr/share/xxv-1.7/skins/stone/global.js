
var parent_url="";

function popup(cmd,data,width,height,reloadonclose){
  var url = "?cmd=" + cmd + "&data=" + data;
  if(ie5&&!opera) //Avoid use cache
    url += "&random=" + (Math.random() * Date.parse(new Date()));
  popupwindow(url,width,height,reloadonclose);
}

function popupcmd(cmd,width,height,reloadonclose){
  var url = "?cmd=" + cmd;
  if(ie5&&!opera) //Avoid use cache
    url += "&random=" + (Math.random() * Date.parse(new Date()));
  popupwindow(url,width,height,reloadonclose);
}

function popupwindow(url,width,height,reloadonclose){

    ttp_make_invisable();
    questclose(0);

    if (!ie5&&!ns6)
        window.open(url,"","width=width,height=height,scrollbars=1");
    else{
        var scrPos = getScrollingPosition();

        document.getElementById("hilfsframe").style.width=width+"px";
        document.getElementById("hilfsframe").style.height=height+"px";
        document.getElementById("hilfsframe").style.left="160px";
        document.getElementById("hilfsframe").style.top=scrPos[1]+30+"px";
        document.getElementById("cframe").src=url;
        document.getElementById("hilfsframe").style.display = "";
    }
    if(reloadonclose)
        parent_url = parent.window.location.href;
    else
        parent_url = "";
}

var lastKeypress = null;
function popupkeypress(e) {
  var KeyID = (window.event) ? event.keyCode : e.keyCode;
  if(KeyID == 27) { //ESC
    parent.parent_url = null;
    closeit();
  } 
}

function initcloseit(){
    lastKeypress = parent.document.onkeypress;
    parent.document.onkeypress = popupkeypress;
    document.onkeypress = popupkeypress;
}

function closeit(){
    parent.document.getElementById("hilfsframe").style.display = "none";
    parent.document.getElementById("cframe").src="about:blank";
    if(parent.parent_url) {
      var url = parent.parent_url.replace(/&random=.+/g,'');
      if(ie5&&!opera) //Avoid use cache
        url += "&random=" + (Math.random() * Date.parse(new Date()));
      parent.window.location.href = url;
    }

    if(lastKeypress) {
      parent.document.onkeypress = lastKeypress;
      lastKeypress = null;
    }
}




// Request senden, aber Ergebnis nicht anzeigen, Reload der aktuellen Seite
function toggle(cmd,data) {

    var fnWhenDone = function(oAnswer, sData) {
        var values = eval('(' + oAnswer.responseText + ')');
        if(values && values.data && typeof(values.data) == 'object'){
          var className;
          var imageExt = ie5&&!opera ? "gif" : "png";
          for (var i = 0; i < values.data.length; i++) {
            var x = values.data[i];
            if(x.length == 4 && x[0]) {
              var tid  = x[0];
              var ton  = x[1];
              var trun = x[2];
              var tcon = x[3];

              var img = document.getElementById('toggle' + tid);
              if(img) {
                if(ton != '0') {
                  if(tcon != '0')
                    className = 'problem';
                  else if(trun != '0')
                      className = 'running';
                    else
                      className = '';
                  img.src = 'images/on.' + imageExt;
                } else {
                  className = 'deactive';
                  img.src = 'images/off.' + imageExt;
                }

                var area = document.getElementById('item' + tid);
                if(area) {
                  var elem = area.getElementsByTagName('font');
                  for (var j = 0; j < elem.length; j++) {
                    var classList = elem[j].className.split(' ');

                    for ( var k = 0; k < classList.length; k++ ) {
                      if(    classList[k] == 'deactive' //remove class
                          || classList[k] == 'problem' 
                          || classList[k] == 'running') 
                        classList.splice(k, 1);
                    }

                    if(className) //add class
                      classList[classList.length] = className;

                    elem[j].className = classList.join(' ');
                  }
                }
              }
            }
          }
        }
    };

    var tt = data.split('_');
    for (var l = 0; l < tt.length; l++) {
      var timg = document.getElementById('toggle' + tt[l]);
      if(timg) {
        timg.src = 'images/wait.gif';
      }
    }

    // Hmm, brutal und gemein, das Laden der URL als Bild funktioniert...
    var url = "?cmd=" + cmd + "&data=" + data + "&ajax=json";
    if(ie5&&!opera) //Avoid use cache
      url += "&random=" + (Math.random() * Date.parse(new Date()));
    var aconn = new XHRequest();
    if(!aconn)
      return;
    aconn.connect(url, fnWhenDone, data);
}

function selToggle(warnmsg,form) {
// test on checked Boxes
    ok = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
            id = form.elements[i].value;
            ok.push(id);
            form.elements[i].checked = 0;
            x += 1;
        }
    }
    if(x > 0) {
        toggle('ttoggle',ok.join('_'));
    } else {
        alert(warnmsg);
    }
}


// Request senden, aber Ergebnis nicht anzeigen
function post(cmd,data) {

    var fnWhenDone = function (oAnswer, sData) {

    };

    var url = "?cmd=" + cmd + "&data=" + data;
    if(ie5&&!opera) //Avoid use cache
      url += "&random=" + (Math.random() * Date.parse(new Date()));

    var aconn = new XHRequest();
    if(!aconn)
      return;
    aconn.connect(url, fnWhenDone, data);
}

// Request senden, aber Ergebnis nicht anzeigen, Reload der aktuellen Seite
function fire(cmd,data) {

    var fnWhenDone = function (oAnswer, sData) {
      var url = location.href.replace(/&random=.+/g,'');
      if(ie5&&!opera) //Avoid use cache
        url += "&random=" + (Math.random() * Date.parse(new Date()));
      location.href = url;
    };

    var url = "?cmd=" + cmd + "&data=" + data;
    if(ie5&&!opera) //Avoid use cache
      url += "&random=" + (Math.random() * Date.parse(new Date()));

    var aconn = new XHRequest();
    if(!aconn)
      return;
    aconn.connect(url, fnWhenDone, data);
}

// Redirect
function redirect(url, wait) {
    if(! wait) {
        wait = 1;
    }
    window.setTimeout('location.href = "' + url + '"', wait * 1000);
}

function selAll(form, type) {
// check all Boxes
    for(var i=0;i<form.length;++i) {
        if(form.elements[i].type == 'checkbox') {
            form.elements[i].checked = type;
        }
    }
}

function reverse(form) {
// check all Boxes
    for(var i=0;i<form.length;++i) {
        if(form.elements[i].type == 'checkbox') {
            if(form.elements[i].checked) {
                form.elements[i].checked = 0;
            } else {
                form.elements[i].checked = 1;
            }
        }
    }
}

function selfield(id,checkbox)
{
  var fieldset = document.getElementById(id);
  var list = fieldset.getElementsByTagName("input");
  for(var i = 0; i < list.length; i++)
  {
    if(list[i].type == 'checkbox') {
      list[i].checked = checkbox.checked;
    }
  }
}

function PlayMusic(ids) {
    var url = '?cmd=mplaylist&data=' + ids;
    location.href = url;
}

function Play(warnmsg,form) {
// test on checked Boxes
    x = 0;
    ok = new Array;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
            id = form.elements[i].value;
            ok.push(id);
            x += 1;
        }
    }
    if(x > 0) {
        PlayMusic(ok.join('_'));
    } else {
        alert(warnmsg);
    }
}

var suggestsearch = '';
var suggestinput;
function suggest(cmd,inputbox,suggestbox){

    var fnWhenDone = function (oAnswer, sData) {
		var sb = document.getElementById(suggestbox);
        if(sb) {
            sb.innerHTML = '';

            var values = eval('(' + oAnswer.responseText + ')');
            if(values && values.data && typeof(values.data) == 'object'){
                var suggest = '';
                for (var i = 0; i < values.data.length; i++) {
                    var x = values.data[i];
                    if(x.length >= 1 && x[0]) {
    		        	suggest += '<div id=\'suggestitem' + i + '\' onmouseover="javascript:suggestmouseover(this);" ';
            			suggest += 'onmouseout="javascript:suggestmouseout(this);" ';
    		            suggest += 'onclick="javascript:suggestselect(\'' + inputbox + '\',\'' + suggestbox + '\', this.innerHTML);" ';
    		        	suggest += 'class="suggestlink">' + x[0] + '</div>';
                    }
                }
                if(suggest != '') {
           			sb.innerHTML = suggest;
                    sb.style.visibility = "visible";
                } else {
           			sb.innerHTML = '';
                    sb.style.visibility = "hidden";
                }
            }
        }
    };
   
    var search = document.getElementById(inputbox).value;
    if(search && (suggestsearch != search || suggestinput != inputbox))
    {
        suggestsearch = search.replace('&amp;','&');
        suggestinput = inputbox;
        var url = "?cmd=" + cmd + "&data=" + escape(search) + "&ajax=json";
        var aconn = new XHRequest();
        if(aconn)
            return aconn.connect(url, fnWhenDone, search);
    }
    return false;
}

function suggestmouseover(div_value) {
	div_value.className = 'suggestover';
}

function suggestmouseout(div_value) {
	div_value.className = 'suggestlink';
}

function suggestselect(inputbox, suggestbox, value) {
	document.getElementById(inputbox).value = unescape(value).replace('&amp;','&');
    var sb = document.getElementById(suggestbox);
    if(sb) {
	    sb.innerHTML = '';
        sb.style.visibility = "hidden";
    }
    suggestsearch = '';
    suggestinput = 0;
}

function suggestitem(i) {
    var item = document.getElementById('suggestitem' + i);
    if(item) {
        item.className = 'suggestover';
        var inp = document.getElementById(suggestinput);
        if(inp) {
            suggestsearch = item.innerHTML.replace('&amp;','&');
            inp.value = unescape(item.innerHTML).replace('&amp;','&');
        }
    }
}

document.onkeydown = suggestkeydown;
function suggestkeydown(e) {
    if (!e)
        e = window.event;
    if (!e)
        return;
    if(e.keyCode == 40 && suggestinput) {
        var i = 0;
        for (; i < 25; i++) {
            var itemlast = document.getElementById('suggestitem' + i);
            if(itemlast && itemlast.className == 'suggestover') {
                itemlast.className = 'suggestlink';
                i += 1;
                suggestitem(i);
                return;
            }
        }
        if(i == 25)
        {
           suggestitem(0);
        }
        return;
    }
    if(e.keyCode == 38 && suggestinput) {
        var i = 25;
        for (; i > 0; i--) {
            var itemlast = document.getElementById('suggestitem' + i);
            if(itemlast && itemlast.className == 'suggestover') {
                itemlast.className = 'suggestlink';
                i -= 1;
                suggestitem(i);
                return;
            }
        }
        return;
    }
}

var slidelist = false;
var slideminX = 0;
var slidemaxX = 0;
var slidespeed = 0;
var slideleft = false;
var slideright = false;

function start(e) {
	if(document.all)e = event;
	if(this.id=='slideright') {
		var m = Math.floor((e.clientX - this.offsetLeft) / 5);
		slidespeed = -1*m;
		slidespeed = Math.max(-10,slidespeed);
	} else {			
		var m = 10 - Math.floor((e.clientX - this.offsetLeft) / 5);
		slidespeed = 1*m;
		slidespeed = Math.min(10,slidespeed);
		if(slidespeed<0)slidespeed=10;
	}
}

function release() {
	slidespeed=0;
}
	
function slide() {
	if(slidespeed!=0) {
		var l = slidelist.offsetLeft;
		l = l/1 + slidespeed;

		if(l>=slidemaxX) {
			l = slidemaxX;
			slidespeed = 0;
            if(slideleft)
                slideleft.style.visibility = "hidden";
		} else {
            if(slideleft && slideleft.style.visibility == "hidden")
                slideleft.style.visibility = "visible";
        }

		if(l<=slideminX) {
			l = slideminX;
			slidespeed=0;
            if(slideright)
                slideright.style.visibility = "hidden";
		} else {
            if(slideright && slideright.style.visibility == "hidden")
                slideright.style.visibility = "visible";
        }
		slidelist.style.left = l + 'px';
	}
	setTimeout('slide()',20);
}

function initslide() {

  slideleft = document.getElementById('slideleft');
  slideleft.onmousemove = start;
  slideleft.onmouseout = release;
  slideleft.style.visibility = "hidden";

  slideright = document.getElementById('slideright');
  slideright.onmousemove = start;
  slideright.onmouseout = release;

  slidelist = document.getElementById('slidelist');
  var w = document.getElementById('slideframe').offsetWidth;
  slidemaxX = slidelist.offsetLeft; 
  slideminX = w - document.getElementById('slideend').offsetLeft;

  slide();
}
