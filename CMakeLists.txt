cmake_minimum_required(VERSION 3.12)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "libs/SFML")
set(DLL_FOLDER_PATH "${CMAKE_SOURCE_DIR}/libs/SFML/bin")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")

file(GLOB DLL_FILES "${DLL_FOLDER_PATH}/*.dll")
file(COPY ${DLL_FILES} DESTINATION ${CMAKE_BINARY_DIR})

add_executable(TicTacToe src/main.cpp)

target_link_libraries(TicTacToe sfml-system sfml-window sfml-window sfml-graphics)


