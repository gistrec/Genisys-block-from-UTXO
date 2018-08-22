#ifndef GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H
#define GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H

#include "../main.h"

#include "./TransactionInput.h"
#include "./TransactionOutput.h"

class TransactionInput;
class TransactionOutput;

class Transaction {
public:
    size_t version;

    size_t inputCount;
    size_t outputCount;

    // Входы
    std::vector<TransactionInput*> inputs;

    // Выходы
    std::vector<TransactionOutput*> outputs;

    Transaction() = default;

    void read(FILE* filePointer);
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H
