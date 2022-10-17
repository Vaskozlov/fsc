add_compile_options(/W4 /Zc:__cplusplus /utf-8)

if (STRICT_COMPILATION)
    add_compile_options(/WX)
endif ()

if (USE_ADDRESS_SANITIZER)
    add_compile_options(/fsanitize=address)
endif ()
