cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB SRC_LIST      "${CMAKE_SOURCE_DIR}/src/*.*")
file(GLOB DEMO_LIST     "${CMAKE_SOURCE_DIR}/src/demo/*.*")
file(GLOB CAN_LIST      "${CMAKE_SOURCE_DIR}/src/can/*.*")
file(GLOB BASE_LIST     "${CMAKE_SOURCE_DIR}/src/base/*.*")
file(GLOB LOG_LIST      "${CMAKE_SOURCE_DIR}/src/log/*.*")
file(GLOB SOCKET_LIST   "${CMAKE_SOURCE_DIR}/src/socket/*.*")
#demo config

#add_definitions(-D OPT_DEMO)
#add_definitions(-D LOG_DEMO)

add_executable(Example 
    ${SRC_LIST}  ${CAN_LIST} ${BASE_LIST} 
    ${DEMO_LIST} ${LOG_LIST} ${SOCKET_LIST})

target_link_libraries(Example pthread)

