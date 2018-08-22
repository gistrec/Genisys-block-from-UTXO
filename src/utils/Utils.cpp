#include "Utils.h"

size_t getIntFromBytes(byte* buffer, int count) {
    size_t value = 0;
    for (int i = 0; i < count; i++) {
        value += buffer[i] * pow(256, i);
    }
    return value;
    /*
    return int((byte)*(buffer + 0) << 0 |
               (byte)*(buffer + 1) << 8 |
               (byte)*(buffer + 2) << 16|
               (byte)*(buffer + 3) << 24);
    */
}


//  Value           Storage length    Format
//  < 0xFD          1                 uint8_t
//  <= 0xFFFF       3                 0xFD followed by the length as uint16_t
//  <= 0xFFFF FFFF  5                 0xFE followed by the length as uint32_t
//  -               9                 0xFF followed by the length as uint64_t
tuple<size_t, int> getVarInt(byte* buffer) {
    byte first = buffer[0];
    if (first < 253) {
        return make_tuple(first, 1);
    }else if (first == 253) {
        return make_tuple(getIntFromBytes(buffer + 1, 2), 3);
    }else if (first == 254) {
        return make_tuple(getIntFromBytes(buffer + 1, 4), 5);
    }else if (first == 255) {
        return make_tuple(getIntFromBytes(buffer + 1, 8), 9);
    }
}