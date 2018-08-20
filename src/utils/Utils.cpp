#include "Utils.h"

int getIntFromBytes(byte* buffer, int count) {
    int value = 0;
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

std::tuple<int, int> getVarInt(byte* buffer) {
    /*byte first = buffer[0];
    int position = 1;
    if (first < 253) {
        return {first, position};
    }else if (first == 252) {
        position += 3;
        char buf[]
        return {hexToNumber(substr($data, $position - 2, 2)), 3};
    }else if (first == 254) {
        position += 5;
        return self::hexToNumber(substr($data, $position - 4, 4));
    }else if (first == 255) {
        position += 9;
        return self::hexToNumber(substr($data, $position - 8, 8));
    }*/
}