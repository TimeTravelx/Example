cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)

# file(GLOB SRC_LIST      "${CMAKE_SOURCE_DIR}/src/*.*")
# file(GLOB DEMO_LIST     "${CMAKE_SOURCE_DIR}/src/demo/*.*")
# file(GLOB CAN_LIST      "${CMAKE_SOURCE_DIR}/src/can/*.*")
# file(GLOB BASE_LIST     "${CMAKE_SOURCE_DIR}/src/base/*.*")
# file(GLOB LOG_LIST      "${CMAKE_SOURCE_DIR}/src/log/*.*")
# file(GLOB SOCKET_LIST   "${CMAKE_SOURCE_DIR}/src/socket/*.*")

# aux_source_directory(${CMAKE_SOURCE_DIR}/src/demo   DEMO_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/can    CAN_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/base   BASE_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/log    LOG_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/socket SOCKET_LIST)
#demo config

#add_definitions(-D OPT_DEMO)
#add_definitions(-D LOG_DEMO)

# add_executable(Example 
#     ${SRC_LIST}  ${CAN_LIST} ${BASE_LIST} 
#     ${DEMO_LIST} ${LOG_LIST} ${SOCKET_LIST})

add_executable(opt_demo src/demo/opt_demo.cpp)
add_executable(socket-tcp src/demo/socket_tcp_demo.cpp ${SOCKET_LIST} ${LOG_LIST})
target_link_libraries(socket-tcp pthread)
add_executable(std-thread src/demo/std_thread_demo.cpp)
target_link_libraries(std-thread pthread)

add_executable(tcp-socket-server src/demo/tcp-server.cpp)
add_executable(tcp-socket-client src/demo/tcp-client.cpp)
# target_link_libraries(Example pthread)

