# fsc

FSC - проект компилятора к собственному языку программирования.

## Поддерживаемые платформы
- Linux (включая ALT linux)

## Требования

Для сборки проекта подходят следующие версии компиляторов:
- gcc-12
- clang-16
- msvc-19.33

### Зависимости 
- [antlr4](https://www.antlr.org)
- [ccl](https://github.com/Vaskozlov/ccl-project)
- [fmt](https://github.com/fmtlib/fmt)

! Все зависимости могут быть установлены при помощи vcpkg

## Сборка проекта

```cmake
https://github.com/Vaskozlov/fsc.git
cd fsc
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

Также имеется возможность сборки rpm пакет при помощи CPack

```cmake
cpack -G RPM
```

## Пример использования компилятора
fsc-compiler exam

```bash
fsc-compiler example/fibonacci.fsc --run
```

![image](https://user-images.githubusercontent.com/46150969/228609871-6cb3bba1-1222-4ebf-ab36-bf540d54fec5.png)
