#include "TransactionOutput.h"

TransactionOutput::TransactionOutput(FILE *filePointer) {
    // Пропускаем количество сатоши для перевода
    fseek(filePointer, 8, SEEK_CUR);

}
