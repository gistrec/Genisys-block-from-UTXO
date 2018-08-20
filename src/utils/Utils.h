#ifndef GENISYS_BLOCK_FROM_UTXO_UTILS_H
#define GENISYS_BLOCK_FROM_UTXO_UTILS_H

#include "../main.h"

/**
 * Функция нужна для получения int из little-endian числа
 * @param buffer буффер с little-endian числом
 * @param count  количество байт
 * @return int
 */
int getIntFromBytes(byte* buffer, int count);

/**
 * Функция нужна для получения int из VarInt little-endian числа
 * @param buffer буффер с little-endian числом
 * @return 1. int - число
 *         2. int - кол-во байт, которое занимает это число
 */
tuple<int, int> getVarInt(byte* buffer);

#endif //GENISYS_BLOCK_FROM_UTXO_UTILS_H
