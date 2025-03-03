add_executable(mpsc_example mpsc.cpp)
target_link_libraries(mpsc_example cpp_channel)

add_executable(broadcast_example broadcast.cpp)
target_link_libraries(broadcast_example cpp_channel)
