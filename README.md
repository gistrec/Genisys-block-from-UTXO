# Genisys-block-from-UTXO

---
### Установка Google Test
```
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make

# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```
---
### Загрузка
Используйте команду [git clone](https://git-scm.com/docs/git-clone) чтобы скачать этот проект.
```
git clone --depth=1 git@github.com:gistrec/Genisys-block-from-UTXO.git GenisysCreator
cd GenisysCreator
```
#### Запуск тестов
```
cmake --build . --target run_tests -- -j 2
./run_tests --gtest_filter=* --gtest_color=yes
```

#### Создание генезис блока
```
cmake --build . --target genisys_creator -- -j 2
./genisys_creator
```
