add_compile_options(
        -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -pedantic -Wold-style-cast
        -Wcast-align -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wdouble-promotion
        -Wformat=2 -Wuninitialized -Wfloat-conversion
)

if (STRICT_COMPILATION)
    add_compile_options(-Werror)
endif ()

if (USE_ADDRESS_SANITIZER)
    add_compile_options(-fsanitize=address,undefined,leak)
    add_link_options(-fsanitize=address,undefined,leak)
elseif (USE_THREAD_SANITIZER)
    add_compile_options(-fsanitize=thread)
    add_link_options(-fsanitize=thread)
endif ()
