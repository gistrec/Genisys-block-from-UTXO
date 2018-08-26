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


vector<byte> getBytesFromInt(size_t value, int count) {
    vector<byte> buffer(count);
    for (int i = 0; i < count; i++) {
        buffer[i] = (byte) (value >> (i * 8));
    }
    return buffer;
}


//  Value           Storage length    Format
//  < 0xFD          1                 uint8_t
//  <= 0xFFFF       3                 0xFD followed by the length as uint16_t
//  <= 0xFFFF FFFF  5                 0xFE followed by the length as uint32_t
//  -               9                 0xFF followed by the length as uint64_t
std::tuple<size_t, int> getVarInt(byte* buffer) {
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

vector<byte> putVarInt(size_t value) {
    vector<byte> result;
    if (value < 0xFDU) {
        // Число состоит из 1 байта
        return getBytesFromInt(value, 1);
    }else if (value <= 0xFFFFU) { // Число изх
        // Число состоит из 2 байт
        result.push_back(0xFD);
        vector<byte> buffer = getBytesFromInt(value, 2);
        result.insert(result.end(), buffer.begin(), buffer.end());
    }else if (value <= 0xFFFFFFFFU) {
        // Число состоит из 4 байт
        result.push_back(0xFE);
        vector<byte> buffer = getBytesFromInt(value, 4);
        result.insert(result.end(), buffer.begin(), buffer.end());
    }else {
        // Число состоит из 8 байт
        result.push_back(0xFF);
        vector<byte> buffer = getBytesFromInt(value, 8);
        result.insert(result.end(), buffer.begin(), buffer.end());
    }
    return result;
}

size_t readVarInt(FILE* filePointer) {
    // Так как размер может быть от 1 до 9 байт
    // То считываем максимум, т.е. 9 байт
    // А потом вернемся назад на лишнее кол-во байт
    byte buf[9];

    fread(buf, sizeof(byte), 9, filePointer);
    std::tuple<size_t, int> result = getVarInt((byte *) &buf);

    int byteCount = get<1>(result);

    // Сдвигаем на лишнее количество байт назад
    fseek(filePointer, byteCount - 9, SEEK_CUR);

    return get<0>(result);
}