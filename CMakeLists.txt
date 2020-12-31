cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB SRC_LIST  "${CMAKE_SOURCE_DIR}/src/*.*")
file(GLOB DEMO_LIST "${CMAKE_SOURCE_DIR}/src/demo/*.*")
file(GLOB CAN_LIST  "${CMAKE_SOURCE_DIR}/src/can/*.*")
file(GLOB BASE_LIST "${CMAKE_SOURCE_DIR}/src/base/*.*")

#demo config

# add_definitions(-D OPT_DEMO)


add_executable(Example ${SRC_LIST} ${DEMO_LIST} ${CAN_LIST} ${BASE_LIST})

