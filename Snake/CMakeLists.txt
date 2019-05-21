cmake_minimum_required(VERSION 3.5)

set(libraryName snakelogiclib)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++14")

FILE(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

set(snakeLogicInclude "${CMAKE_CURRENT_SOURCE_DIR}/" PARENT_SCOPE)

add_library(${libraryName} STATIC ${SRCS} )

