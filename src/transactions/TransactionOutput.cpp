#include "TransactionOutput.h"

TransactionOutput::TransactionOutput(FILE *filePointer) {
    // Пропускаем количество сатоши для перевода
    fseek(filePointer, 8, SEEK_CUR);

    // Получаем длину скрипта
    scriptSize = readVarInt(filePointer);

    // Пропускаем скрипт
    fseek(filePointer, scriptSize, SEEK_CUR);
}
