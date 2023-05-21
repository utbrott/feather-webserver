#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define INVERT(x) (x = (x + 1) % 2)
#define ARRAYSIZE(n) (sizeof(n) / sizeof(n[0]))

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef float f32;
typedef double f64;

typedef struct
{
    f32 temperature[3];
    f32 pressure[3];
    f32 humidity[3];
} StoredData_t;

#endif /* GLOBALS_H */