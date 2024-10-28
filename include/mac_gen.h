#ifndef MAC_GEN_H
#define MAC_GEN_H

#include <Arduino.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/flash.h"

#ifdef __cplusplus
extern "C"
{
#endif

void get_unique_id(uint8_t* id);
void get_unique_mac_adress(uint8_t* id, byte* mac_adress);

#ifdef __cplusplus
}
#endif

#endif // MAC_GEN_H
