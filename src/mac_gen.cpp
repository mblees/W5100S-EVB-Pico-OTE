#include "mac_gen.h"
#include "Arduino.h"

void get_unique_id(uint8_t* id){
    flash_get_unique_id(id);
}

void get_unique_mac_adress(uint8_t* id, byte* mac_adress){
    get_unique_id(id);
    mac_adress[0] = 0xDE;
    mac_adress[1] = 0x04;
    mac_adress[2] = 0x25;
    mac_adress[3] = id[5];
    mac_adress[4] = id[6];
    mac_adress[5] = id[7];
}