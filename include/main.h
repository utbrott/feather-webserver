#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "globals.h"
#include "wificonfig.h"
#include "webserver.h"

#ifndef I2C_ADDR
#define I2C_ADDR 0x31
#endif
#define CLIENT_TIMEOUT 2000
#define DATA_COUNT 9

extern StoredData_t data;
extern u32 timeoutTimer;

void i2cReceive(int byteCount);

#endif /* MAIN_H */