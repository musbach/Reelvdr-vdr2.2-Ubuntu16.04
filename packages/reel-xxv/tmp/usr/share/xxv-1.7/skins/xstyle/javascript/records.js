// Search for epgevents and check for future programming
function checkrecord (name) {
    var fnWhenDone = function (oXML, sData) {
        if(oXML.responseText != 'ok') {
            var text = oXML.responseText.split(':');
            document.getElementById(sData).src = 'images/record_red.png';
            document.getElementById(sData).title = '<?% gettext('Conflict with timer: ') %?>' + text[0];
            document.getElementById(sData).className = 'problem';
        } else {
            document.getElementById(sData).src = 'images/record_green.png';
            document.getElementById(sData).className = 'noproblem';
        }
     };

    var tags = document.getElementsByName('recordlink');
    for (var i = 0; i < tags.length; i++) {
        var epgid = tags[i].id;
        var url = "?cmd=conflict&data=" + epgid + "&ajax=text";
        var aconn = new XHRequest();
        if(!aconn)
          return false;
        aconn.connect(url, fnWhenDone, epgid);
    }
}

window.onLoad = window.setTimeout("checkrecord('recordlink')", 1000);
