// Request senden, aber Ergebnis nicht anzeigen
function post(cmd,data) {

    var fnWhenDone = function (oXML, sData) {

    };

    var url = "?cmd=" + cmd + "&data=" + data;
    var aconn = new XHRequest();
    if(!aconn)
      return;
    aconn.connect(url, fnWhenDone, data);
}

// Request senden, aber Ergebnis nicht anzeigen, Reload der aktuellen Seite
function fire(cmd,data) {

    var fnWhenDone = function (oXML, sData) {
        location.href = location.href;
    };


    // Hmm, brutal und gemein, das Laden der URL als Bild funktioniert...
    var url = "?cmd=" + cmd + "&data=" + data;
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

// Question bevor delete
function sure(text, url) {
    if(confirm(text)) {
        location.href = url;
    }
}

function di(url, wert) {
    location.href = url + wert;
}

// Question bevor delete
function sureandreload(text, cmd,data) {
    if(confirm(text)) {
        fire(cmd,data)
    }
}

function DeleteSelected(question,warn,cmd,form) {
// test on checked Boxes
    ok = new Array;
    txt = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
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
        sure(question + '\n' + txt.join("\n"),'?cmd=' + cmd + '&data=' + ok.join('_'));
    } else {
        alert(warn);
    }
}

function ToggleTimer(warn,form) {
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
        fire('ttoggle',ok.join('_'));
    } else {
        alert(warn);
    }
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
