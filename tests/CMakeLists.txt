# Quickstart CMake taken from:
# https://google.github.io/googletest/quickstart-cmake.html
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
# Se define un ejecutable de pruebas "pruebas_arboles",
# que requiere los siguientes archivos .cc para ser compilado.
add_executable(
    pruebas_arboles
    pruebas_arboles.cc
    ${TareaProgramada1_SOURCE_DIR}/src/arbolArreglo
)
# unit_test requiere los archivos de encabezados
# en el folder include
target_include_directories(pruebas_arboles PUBLIC "${TareaProgramada1_SOURCE_DIR}/include")
# Finalmente, enlazamos con la librería de Google Test
    target_link_libraries(
    pruebas_arboles
    GTest::gtest_main
)
include(GoogleTest)
# Añadan esto para permitir que ctest pueda descubrir
# las pruebas automáticamente
gtest_discover_tests(pruebas_arboles)