#ifndef GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H
#define GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H

#include "../main.h"

// Формат выхода:
// 8 байт     - количество сатоши для перевода
// 1-9 байт   - длина скрипта
// много байт - скрипт
class TransactionOutput {
private:
    // Количество сатоши для перевода
    byte value[8];

    size_t scriptSize;

    byte* script;

public:
    explicit TransactionOutput(FILE* filePointer);

    std::vector<byte> getSourceBytes();

    ~TransactionOutput();
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTIONOUTPUT_H
