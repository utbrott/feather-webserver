#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef float f32;
typedef double f64;

#define INVERT(x) (x = (x + 1) % 2)

#endif /* GLOBALS_H */