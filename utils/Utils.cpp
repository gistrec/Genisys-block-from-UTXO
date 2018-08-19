#include "Utils.h"

int getIntFromBytes(byte* buffer) {
    return int((byte)*(buffer + 0) << 0 |
               (byte)*(buffer + 1) << 8 |
               (byte)*(buffer + 2) << 16|
               (byte)*(buffer + 3) << 24);
}

int getVarInt(byte* buffer) {
    return 1;
}