#include "webpage.h"

const String httpHeader[] PROGMEM = {
    "HTTP/1.1 200 OK",
    "Content-type:text/html",
    "Connection:close",
};

const String webpageHead[] PROGMEM = {
    "<head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">",
    "<meta name=viewport content=\"width=device-width,initial-scale=1\">",
    "<style>@import url(https://fonts.googleapis.com/css2?family=Inter&display=swap);",
    "body{font-family:Inter;width:100%;min-height:100vh;display:flex;flex-direction:column;align-items:center;justify-content:center}",
    "table{border-collapse:collapse;border:1px solid #3f3f46;padding:16px;text-align:center}",
    ".row__header{background-color:#27272a;color:#fff;text-transform:uppercase}",
    "th{padding:16px;border:1px solid #52525b}",
    "td{padding:16px;border:1px solid #3f3f46}</style></head>",
};

const String webpageBody[] PROGMEM = {
    "<body><h2>LoRa Private sensor network</h2><table>",
    "<tr class=\"row__header\">",
    "<th class=\"header__item\">measurement</th>",
    "<th class=\"header__item\">node 1</th>",
    "<th class=\"header__item\">node 2</th>",
    "<th class=\"header__item\">node 3</th>",
    "</tr>",
    "", // 7th item
    "</table></body></html>",
};