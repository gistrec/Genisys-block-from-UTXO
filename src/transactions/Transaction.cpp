#include "Transaction.h"

void Transaction::read(FILE* filePointer) {
    byte buf[9];
    fread(buf, sizeof(byte), 4, filePointer);

    version = getIntFromBytes((byte *) &buf, 4);

    // TODO: Flag 2 byte array?!

    // Считываем количество входов
    // Так как размер может быть от 1 до 9 байт
    // То считываем максимум, т.е. 9 байт
    // А потом вернемся назад на лишнее кол-во байт
    fread(buf, sizeof(byte), 9, filePointer);
    std::tuple<size_t, int> result = getVarInt((byte *) &buf);

    inputCount = get<0>(result);
    int byteCount = get<1>(result);

    fseek(filePointer, byteCount - 9, SEEK_CUR);


    for (int i = 0; i < inputCount; i++) {
        TransactionInput* input = new TransactionInput(filePointer);
        inputs.push_back(input);
    }


    // Считываем количество выходов
    // Так как размер может быть от 1 до 9 байт
    // То считываем максимум, т.е. 9 байт
    // А потом вернемся назад на лишнее кол-во байт
    fread(buf, sizeof(byte), 9, filePointer);
    result = getVarInt((byte *) &buf);

    outputCount = get<0>(result);
    byteCount = get<1>(result);

    fseek(filePointer, byteCount - 9, SEEK_CUR);


    for (int i = 0; i < outputCount; i++) {
        TransactionOutput* output = new TransactionOutput(filePointer);
        outputs.push_back(output);
    }

    // Считываем lock time
    fseek(filePointer, 4, SEEK_CUR);
}