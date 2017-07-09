// To status frame und dann refresh der seite
function tostatus(url) {
    myoldurl = location.href;
    location.href = url;
}

// Redirect
function redirect(url, wait, par) {
    if(! wait) {
        wait = 0.1;
    }
    if(par) {
        window.setTimeout(par + '.location.href = "' + url + '"', wait * 1000);
    } else {
        window.setTimeout('location.href = "' + url + '"', wait * 1000);
    }
}

// Program choose
function di(wert, url) {
    location.href = url + wert;
}

// Question bevor delete
function sure(form, text, url, id) {
    id = (id) ? id : '';
    var erg = confirm(text);
    var refe = encodeURIComponent(form.referer.value);
    if(erg == true) {
        var callurl = url + id + '&referer=' + refe;
        location.href = callurl;
    }
}

function Delete(question,warn,cmd,form) {
// test on checked Boxes
    ok = new Array;
    txt = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
            id = form.elements[i].value;
            ok.push(id);
            txt.push(form.elements[i].name);
            form.elements[i].checked = 0;
            x += 1;
        }
    }
    if(x > 0) {
        if(confirm(question + '\n' + txt.join("\n"))) {
            tostatus('?cmd=' + cmd + '&data=' + ok.join('_'));
        }
    } else {
        alert(warn);
    }
}

function Toggle(warn,form) {
// test on checked Boxes
    ok = new Array;
    txt = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
            id = form.elements[i].value;
            ok.push(id);
            txt.push(form.elements[i].name);
            form.elements[i].checked = 0;
            x += 1;
        }
    }
    if(x > 0) {
        tostatus('?cmd=ttoggle&data=' + ok.join('_'));
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

function selSwitch(form, search) {
// switch Boxes with search in name on or off
    for(var i=0;i<form.length;++i) {
        if(form.elements[i].type == 'checkbox' && form.elements[i].name == search) {
            if(form.elements[i].checked) {
                form.elements[i].checked = 0;
            } else {
                form.elements[i].checked = 1;
            }
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

function Play(warnmsg,form) {
// test on checked Boxes
    ok = new Array;
    x = 0;
    for(var i=0;i<form.length;++i) {
        var id;
        if(form.elements[i].type == 'checkbox' && form.elements[i].checked) {
            id = form.elements[i].value;
            ok.push(id);
            x += 1;
        }
    }
    if(x > 0) {
          var url = '?cmd=mplaylist&data=' + ok.join('_');
          location.href = url;
    } else {
        alert(warnmsg);
    }
}

/* -------------------- Widget Routines --------------- */

/*
- An AjaxCall to check for right values in HTML Widget
checkValue(inputObject, msgId, perlCall, wrongMessage, goodMessage);
checkValue(this, 'id<?% param.count %?>', 'getip', 'host: %s is not exists!', 'ip address is %s')
*/
function checkValue (valobj, msgname, cmd, wrongMsg, goodMsg) {

    var fnWhenDone = function (oXML, sData) {
        var val = sData[0];
        var msg = sData[1];
        var wrongMsg = sData[2];
        var goodMsg = sData[3];

        var o = eval("("+oXML.responseText+")");
        if(o && o.data && typeof(o.data) == 'string' 
             && o.success && o.success == true) {
            msg.className = 'good';
            msg.innerHTML = goodMsg.replace('%s', o.data);
        } else {
            msg.className = 'error';
            msg.innerHTML = wrongMsg.replace('%s', o.data);
        }
    };

    var inputvalue = valobj.value;
    var msgobj = document.getElementById(msgname);
    msgobj.innerHTML = 'Check value ...';

    if(inputvalue) {
        var url = "?cmd=checkvalue&data=" + cmd + ":" + inputvalue + "&ajax=json";
        var aconn = new XHRequest();
        if(!aconn)
          return false;
        return aconn.connect(url, fnWhenDone, [valobj, msgobj, wrongMsg, goodMsg]);
    }
}
