cmake_minimum_required(VERSION 3.20)
project(Tetris LANGUAGES C CXX)

# Raylib uses C99, can update to any version after that
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 23)

# raylib cmake has this on, leads to errors
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(raylib)

add_executable(${PROJECT_NAME}
   src/Block.cpp
   src/Grid.cpp
   src/main.cpp
   src/Resources.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include )

target_link_libraries(${PROJECT_NAME} PRIVATE raylib )