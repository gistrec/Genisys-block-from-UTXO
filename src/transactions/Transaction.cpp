#include "Transaction.h"

void Transaction::read(FILE* filePointer) {
    byte buf[9];
    fread(buf, sizeof(byte), 4, filePointer);

    version = getIntFromBytes((byte *) &buf, 4);

    // TODO: Flag 2 byte array?!



    // Считываем количество входов
    inputCount = readVarInt(filePointer);

    for (int i = 0; i < inputCount; i++) {
        TransactionInput* input = new TransactionInput(filePointer);
        inputs.push_back(input);
    }


    // Считываем количество выходов
    outputCount = readVarInt(filePointer);

    for (int i = 0; i < outputCount; i++) {
        TransactionOutput* output = new TransactionOutput(filePointer);
        outputs.push_back(output);
    }

    // Считываем lock time
    fseek(filePointer, 4, SEEK_CUR);
}