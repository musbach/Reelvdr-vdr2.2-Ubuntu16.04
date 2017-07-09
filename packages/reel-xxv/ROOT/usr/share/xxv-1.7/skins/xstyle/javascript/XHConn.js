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

var ajaxconn = new XHRequest();

if (!ajaxconn)
    alert("XMLHTTP not available. Try a newer/better browser.");
