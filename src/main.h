#ifndef GENISYS_BLOCK_FROM_UTXO_MAIN_H
#define GENISYS_BLOCK_FROM_UTXO_MAIN_H

#include <iostream>
#include <string>

#include <fstream>
#include <vector>
#include <tuple>
#include <math.h>
#include <map>

typedef unsigned char byte;
typedef std::basic_string<unsigned char> ustring;

#include "Block.h"
#include "utils/sha256.h"

using namespace std;

int main(int argc, char** argv);

#endif //GENISYS_BLOCK_FROM_UTXO_MAIN_H
