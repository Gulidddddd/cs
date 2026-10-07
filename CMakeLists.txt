cmake_minimum_required(VERSION 3.16)
project(MiAplicacionGUI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir librerías del sistema
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Incluir archivos del proyecto
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.h"
)

# Añadir ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Directorios de inclusión
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Vincular dependencias
target_link_libraries(${PROJECT_NAME} PRIVATE 
    OpenGL::GL
    glfw
)