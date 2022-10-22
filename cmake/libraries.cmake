find_package(Threads REQUIRED)
find_package(fmt CONFIG REQUIRED)

find_package(antlr4-generator REQUIRED)
find_package(antlr4-runtime CONFIG REQUIRED)
include_directories(AFTER SYSTEM ${ANTLR4_INCLUDE_DIR})

find_package(LLVM REQUIRED CONFIG PATHS FSC_LLVM_PATH)
llvm_map_components_to_libnames(llvm_libs support core irreader)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
