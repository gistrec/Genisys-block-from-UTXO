## Установка Google test
Скачиваем пакет `Google's framework for writing C++ tests`  
```
sudo apt-get install libgtest-dev
```

Компилируем скаченный пакет
```
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
```

Копируем **libgtest.a** и **libgtest_main.a** в директорию **/usr/lib**
```
sudo cp *.a /usr/lib
```
