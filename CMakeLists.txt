cmake_minimum_required(VERSION 3.20)
project(fsc VERSION 0.0.1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_compile_definitions(CCL_DEBUG=1)
add_subdirectory(ccl EXCLUDE_FROM_ALL SYSTEM)
set(CCL_WSHADOW OFF)

include(project-options)
include(compile-options)
include(libraries)
include(fsc/CMakeLists.txt)
include(fsc/program/CMakeLists.txt)
include(catch/CMakeLists.txt)

include(CPack)

set(CPACK_PACKAGE_HOMEPAGE_URL https://vaskozlov.github.io)

install(TARGETS fsc fsc-compiler
        EXPORT fscTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(DIRECTORY include/fsc
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.hpp")

install(EXPORT fscTargets
        FILE fscTargets.cmake
        NAMESPACE fsc::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fsc
        )

include(CMakePackageConfigHelpers)

set_property(TARGET fsc PROPERTY VERSION ${version})

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/fscConfigVersion.cmake"
        VERSION "${version}"
        COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/fscConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fsc
        )

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/fscConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/fscConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fsc
        )

export(EXPORT fscTargets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/fscTargets.cmake"
        NAMESPACE fsc::
        )
