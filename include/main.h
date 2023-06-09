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

enum DataType
{
    TEMPERATURE,
    PRESSURE,
    HUMIDITY,
    FAILPERCENT,
};

/**
 * @brief Handles receiving data from MASTER LoRa module over I2C interface.
 * @param byteCount Amount of bytes being transmitted
 */
void i2cReceive(int byteCount);

/**
 * @brief Decodes string that was transmitted from MASTER module using I2C,
 * without using dynamic memory alloc.
 * @param recv Reference to received string
 * @param data Data structure to be filled with values
 */
void decodeStr(String *recv, StoredData_t *data);

#endif /* MAIN_H */