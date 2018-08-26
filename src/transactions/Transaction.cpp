#include "Transaction.h"

void Transaction::read(FILE* filePointer) {
    byte buf[9];
    fread(buf, sizeof(byte), 4, filePointer);

    version = getIntFromBytes((byte *) &buf, 4);

    // TODO: Flag 2 byte array?!

    // Считываем количество входов
    inputCount = readVarInt(filePointer);

    for (int i = 0; i < inputCount; i++) {
        auto input = new TransactionInput(filePointer);
        inputs.push_back(input);
    }


    // Считываем количество выходов
    outputCount = readVarInt(filePointer);

    for (int i = 0; i < outputCount; i++) {
        auto output = new TransactionOutput(filePointer);
        outputs.push_back(output);
        spend[i] = false;
    }

    // Считываем lock time
    fread(buf, sizeof(byte), 4, filePointer);
    lock_time = getIntFromBytes((byte *) &buf, 4);
}

void Transaction::spendOutput(int index) {
    spend[index] = true;
}

bool Transaction::haveUnsepndOutput() {
    for (auto output : spend) {
        // Если выход не потрачен, то возвращаем true
        if (!output.second) return true;
    }
    // Когда все выходы потрачены
    return false;
}

std::vector<TransactionInput*>  Transaction::getInputs() {
    return inputs;
}

std::vector<TransactionOutput*> Transaction::getOutputs() {
    return outputs;
}

Transaction::~Transaction() {
    for (auto input : inputs) {
        delete input;
    }
    for (auto output : outputs) {
        delete output;
    }
}