cmake_minimum_required(VERSION 3.20)
project(Tarea_2)

set(CMAKE_CXX_STANDARD 20)

# Esto crea el target "Tarea_2" que CLion está buscando,
# pero solo con un test para que no de error de 'main'
add_executable(Tarea_2 test_estadistica.cpp)

# Estos son los otros por si quieres probarlos luego
add_executable(test_max test_max_y_objetos.cpp)
add_executable(test_variadic test_variadic.cpp)