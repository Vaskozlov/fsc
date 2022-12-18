find_package(Threads REQUIRED)
find_package(fmt CONFIG REQUIRED)

find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime CONFIG REQUIRED)
include_directories(AFTER SYSTEM ${ANTLR4_INCLUDE_DIR})

include_directories(ccl/include)
