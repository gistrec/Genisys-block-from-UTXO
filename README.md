# Genisys creator
[![CircleCI](https://img.shields.io/circleci/project/github/gistrec/Genisys-block-from-UTXO.svg?style=for-the-badge)](https://circleci.com/gh/gistrec/Genisys-block-from-UTXO)

С помощью этого проекта можно создать генезис блок биткоина, который не будет включать в себя потраченные транзакции  

___

### Документация
Всю документацию можно посмотреть в папке [docs]
___

### Зависимости
* [GTest] - фреймворк для юнит-тестирования
* [cmake] - кроссплатформенная система автоматизации сборки  

___


### Сборка
* [Установка GTest]
* [Установка CMake v3.9]  

Скачайте проект командой [git clone](https://git-scm.com/docs/git-clone):
```
git clone --depth=1 git@github.com:gistrec/Genisys-block-from-UTXO.git Genisys-creator
cd Genisys-creator
```  

Соберите проект с помощью CMake:
```
cmake .
cmake --build . --target genisys_creator -- -j 2
```

### Запуск
Доступные флаги для запуска:

| Флаг   | Описание |
| ------ | -------- |
| -path `<путь>` | Путь до блоков |

**Флаг -path является обязательным!**

Пример запуска:
```
./genisys_creator -path /home/blockchain/
```

___

### Todos
 - Добавить поддержку этого блока в bitcoin core/miner

   [docs]: <https://github.com/gistrec/Genisys-block-from-UTXO/tree/master/docs>
   [GTest]: <https://github.com/google/googletest>
   [cmake]: <https://cmake.org/>
   [Установка GTest]: <https://github.com/gistrec/Genisys-block-from-UTXO/blob/master/docs/gtest.md>
   [Установка CMake v3.9]: <https://github.com/gistrec/Genisys-block-from-UTXO/blob/master/docs/cmake.md>
