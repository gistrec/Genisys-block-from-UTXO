#include "TransactionInput.h"

TransactionInput::TransactionInput(FILE* filePointer) {
    fread(hashPreviousTrans, sizeof(byte), 32, filePointer);

    byte buf[4];
    fread(buf, sizeof(byte), 4, filePointer);
    indexPreviousTrans = getIntFromBytes((byte *) &buf, 4);

    scriptSize = readVarInt(filePointer);
    script = new byte[scriptSize];
    fread(script, sizeof(byte), scriptSize, filePointer);

    // Пропускаем sequence number
    fread(buf, sizeof(byte), 4, filePointer);
    sequence_number = getIntFromBytes((byte *) &buf, 4);
}

vector<byte> TransactionInput::getHashPreviousTrans() {
    vector<byte> result;
    result.reserve(32);
    for (auto symbol : hashPreviousTrans) {
        result.push_back(symbol);
    }
    return result;
}

size_t TransactionInput::getIndexPreviousTrans() {
    return indexPreviousTrans;
}

vector<byte> TransactionInput::getSourceBytes() {
    // Резервируем максимальную длину
    vector<byte> result;
    result.reserve(32 + 4 + 9 +scriptSize + 4);

    // Кладем хэш предыдущей транзакции
    for (int i = 0; i < 32; i++) {
        result.push_back(hashPreviousTrans[i]);
    }

    // Кладем индекс предыдущей транзакции
    vector<byte> buf = getBytesFromInt(indexPreviousTrans, 4);
    result.insert(result.end(), buf.begin(), buf.end());

    // Кладем длину скрипта
    buf = putVarInt(scriptSize);
    result.insert(result.end(), buf.begin(), buf.end());

    // Кладем скрипт
    for (int i = 0; i < scriptSize; i++) {
        result.push_back(script[i]);
    }

    // Кладем sequence_number
    buf = getBytesFromInt(sequence_number, 4);
    result.insert(result.end(), buf.begin(), buf.end());

    return result;
}