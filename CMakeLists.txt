cmake_minimum_required(VERSION 3.12)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "libs/SFML")
set(DLL_FOLDER_PATH "${CMAKE_SOURCE_DIR}/libs/SFML/bin")

include_directories("${SFML_DIR}/include")
link_directories("${SFML_DIR}/lib")

file(GLOB DLL_FILES "${DLL_FOLDER_PATH}/*.dll")
file(COPY ${DLL_FILES} DESTINATION ${CMAKE_BINARY_DIR})

set(PNG_FOLDER_PATH "${CMAKE_SOURCE_DIR}/res")

file(GLOB PNG_FILES "${PNG_FOLDER_PATH}/*.png")
file(COPY ${PNG_FILES} DESTINATION "${CMAKE_BINARY_DIR}/res")

set(SOURCES
    "${CMAKE_SOURCE_DIR}/src/Application.cpp"
    "${CMAKE_SOURCE_DIR}/src/Board.cpp"
    "${CMAKE_SOURCE_DIR}/src/Block.cpp"
)

set(HEADERS
    "${CMAKE_SOURCE_DIR}/include/Application.h"
    "${CMAKE_SOURCE_DIR}/include/Board.h"
    "${CMAKE_SOURCE_DIR}/include/Block.h"
)

set(TEXTURE_FILES
    "${CMAKE_SOURCE_DIR}/res/empty.png"
    "${CMAKE_SOURCE_DIR}/res/circle.png"
    "${CMAKE_SOURCE_DIR}/res/x.png"
)

set(ENUMS
    "${CMAKE_SOURCE_DIR}/include/TypeOfPlayer.h"
    "${CMAKE_SOURCE_DIR}/include/TypeOfBlock.h"
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(TicTacToe src/main.cpp ${SOURCES} ${HEADERS} ${TEXTURE_FILES} ${ENUMS})

target_link_libraries(TicTacToe sfml-system sfml-window sfml-graphics)


