# fsc

FSC - проект компилятора к собственному языку программирования.

## Поддерживаемые платформы
- Linux (включая ALT linux)

## Требования

Для сборки проекта подходят следующие версии компиляторов:
- gcc-12
- clang-16
- msvc-19.33

Используемые библиотеки
- [antlr4](https://www.antlr.org)
- [ccl](https://github.com/Vaskozlov/ccl-project)


## Сборка проекта
Для минимальной сборки проекта необходим cmake (от версии 3.20) и следующие библиотеки:
- antlr4
- cxxopts

```cmake
mkdir build
cd build
```

```cmake
cmake .. -G Ninja
ninja
```

## Установка
```cmake
ninja install all
```

Также имеется возможность собрать rpm пакет при помощи CPack

```cmake
cpack -G RPM
```
