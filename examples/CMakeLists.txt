add_executable(mpsc_example mpsc.cpp)
target_link_libraries(mpsc_example cpp_channel)

install(TARGETS mpsc_example DESTINATION examples)

add_executable(broadcast_example broadcast.cpp)
target_link_libraries(broadcast_example cpp_channel)

install(TARGETS broadcast_example DESTINATION examples)
