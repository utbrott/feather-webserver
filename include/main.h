#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "globals.h"
#include "wificonfig.h"
#include "webserver.h"
#include "display.h"

#define CLIENT_TIMEOUT 2000

extern StoredData_t data;
extern u32 timeoutTimer;

#endif /* MAIN_H */