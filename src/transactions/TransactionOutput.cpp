#include "TransactionOutput.h"

TransactionOutput::TransactionOutput(FILE *filePointer) {
    fread(value, sizeof(byte), 8, filePointer);

    // Получаем длину скрипта
    scriptSize = readVarInt(filePointer);

    script = new byte[scriptSize];
    fread(script, sizeof(byte), scriptSize, filePointer);
}

vector<byte> TransactionOutput::getSourceBytes() {
    // Резервируем максимальную длину
    vector<byte> result;
    result.reserve(8 + 9 + scriptSize);

    // Кладем сатоши
    for (int i = 0; i < 8; i++) {
        result.push_back(value[i]);
    }

    // Кладем длину скрипта
    vector<byte> buf = putVarInt(scriptSize);
    result.insert(result.end(), buf.begin(), buf.end());

    // Кладем скрипт
    for (int i = 0; i < scriptSize; i++) {
        result.push_back(script[i]);
    }

    return result;
}

TransactionOutput::~TransactionOutput() {
    delete[] script;
}
