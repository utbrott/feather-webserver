# Feather Webserver

Embedded Systems supplementary project to [LoRa Private Sensor Network](https://github.com/utbrott/lora-psn).
Uses Adafruit Feather M0 and Adafruit OLED FeatherWing display shield.

Developed for Master's Thesis @ WUT Warsaw University of Technology.

## Features

- Simple webserver served to view logged data,
- Fetching data through software serial connection from LoRa master board.

## Built with

- Adafruit Feather M0 (ATSAM21 + ATWINC1500) development board,
- Adafruit OLED FeatherWing 128x32 display expansion board,

## File structure

```
.
├── include
│   ├── debug.h
│   ├── globals.h
│   ├── main.h
│   ├── webpage.h
│   ├── webserver.h
│   ├── wificonfig.h
│   └── wificredentials.h
├── src
│   ├── debug.cpp
│   ├── main.cpp
│   ├── webpage.cpp
│   ├── webserver.cpp
│   └── wificonfig.cpp
├── platformio.ini
└── README.md
```

- `debug.h` - helper functions for debugging through Serial,
- `globals.h` - global typedefs,
- `webpage.h` - structure of the server webpage,
- `webserver.h` - starting the webserver,
- `wificonfig.h` - local network connection with WiFi,
- `wificredentials.h` - credentials for logging in to WiFi (example file in repo).

## Future development note

Project was built using PlatformIO Core CLI and PlatformIO IDE for VSCode.
