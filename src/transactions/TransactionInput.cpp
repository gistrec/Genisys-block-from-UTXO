#include "TransactionInput.h"

TransactionInput::TransactionInput(FILE* filePointer) {
    fread(hashPreviousTrans, sizeof(byte), 32, filePointer);

    byte buf[4];
    fread(buf, sizeof(byte), 4, filePointer);
    indexPreviousTrans = getIntFromBytes((byte *) &buf, 4);

    scriptSize = readVarInt(filePointer);
    fseek(filePointer, scriptSize, SEEK_CUR);

    // Пропускаем sequence number
    fseek(filePointer, 4, SEEK_CUR);
}