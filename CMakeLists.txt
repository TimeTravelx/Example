cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/demo DEMO_LIST)
#demo config

add_definitions(-D OPT_DEMO)



add_executable(Example ${SRC_LIST} ${DEMO_LIST})

