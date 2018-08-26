#ifndef GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H
#define GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H

#include "../main.h"

#include "./TransactionInput.h"
#include "./TransactionOutput.h"

class TransactionInput;
class TransactionOutput;

class Transaction {
private:
    size_t version;

    size_t inputCount;
    size_t outputCount;

    // Входы
    std::vector<TransactionInput*> inputs;

    // Выходы
    std::vector<TransactionOutput*> outputs;

    size_t lock_time;

    /**
     * Массив показывает потрачен выход или нет
     */
    std::map<int, bool> spend;

public:
    Transaction() = default;
    ~Transaction();

    void spendOutput(int index);

    std::string getHash();

    /**
     * Функция нужна для проверки наличия непотраченных выходов
     * @return bool
     */
    bool haveUnsepndOutput();

    /**
     * Функция нужна для чтения транзакции из файла
     * @param filePointer - объект файла
     */
    void read(FILE* filePointer);

    std::vector<TransactionInput*>  getInputs();
    std::vector<TransactionOutput*> getOutputs();
};


#endif //GENISYS_BLOCK_FROM_UTXO_TRANSACTION_H
