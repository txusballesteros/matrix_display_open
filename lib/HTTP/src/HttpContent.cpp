#include "Arduino.h"
#include "HttpContent.h"

String HttpContent::styles { 
    "<style>#file-input,input{width:100%;height:44px;border-radius:4px;margin:10px auto;font-size:15px}"
    "input{background:#f1f1f1;border:0;padding:0 15px}body{background:#3498db;font-family:sans-serif;font-size:14px;color:#777}"
    "#file-input{padding:0;border:1px solid #ddd;line-height:44px;text-align:left;display:block;cursor:pointer}"
    "#bar,#prgbar{background-color:#f1f1f1;border-radius:10px}#bar{background-color:#3498db;width:0%;height:10px}"
    "form{background:#fff;max-width:258px;margin:75px auto;padding:30px;border-radius:5px;text-align:center}"
    ".btn{background:#3498db;color:#fff;cursor:pointer}</style>"
 };

 String HttpContent::mainPage { 
    HttpContent::styles +
    "<form name='data' action='/write'>"
        "<h1>ESP Matrix Display</h1>"
        "<h3>Text</h3>"
        "<input name=text placeholder='Text'  value='Hello!'>"
        "<h3>Speed (ms)</h3>"
        "<input name=speed type='number' min='1' max='1000' placeholder='Speed' value='20'>"
        "<input type=submit class=btn value=Send>"
    "</form>"
 };