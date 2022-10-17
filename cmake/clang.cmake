add_compile_options(-Wfloat-equal -Wmove -Wthread-safety)

if (USE_LIBCPP)
    add_compile_options(-stdlib=libc++ -lc++abi)
    add_link_options(-stdlib=libc++ -lc++abi)
else ()
    add_compile_options(-stdlib=libstdc++)
    add_link_options(-stdlib=libstdc++)
endif ()
