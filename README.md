# fsc

FSC - проект компилятора к собственному языку программирования.

## Поддерживаемые платформы

- Linux (включая ALT linux)

## Требования

Для сборки проекта подходят следующие версии компиляторов:

- Clang-16
- GCC-12
- MSVC-19.32

### Зависимости

- [antlr4](https://www.antlr.org)
- [ccl](https://github.com/Vaskozlov/ccl-project)
- [fmt](https://github.com/fmtlib/fmt)

! Все зависимости могут быть установлены при помощи vcpkg

## Сборка проекта

```bash
git
clone --recurse-submodules https://github.com/Vaskozlov/fsc.git
cd fsc
mkdir build && cd build
```

```bash
cmake .. -G Ninja -DCCL_WSHADOW=OFF
ninja
```

При использовании vcpkg:

```bash
cmake .. -G Ninja -DCCL_WSHADOW=OFF -DCMAKE_TOOLCHAIN_FILE=`путь до vcpkg + scripts/buildsystems/vcpkg.cmake`
ninja
```

## Установка

```bash
ninja install all
```

Также имеется возможность сборки rpm пакет при помощи CPack

```bash
cpack -G RPM
```

## Пример использования компилятора

fsc-compiler exam

```bash
fsc-compiler example/fibonacci.fsc --run
```

![image](https://user-images.githubusercontent.com/46150969/228610779-734de800-f0b8-43db-96b3-4730b584a48e.png)
