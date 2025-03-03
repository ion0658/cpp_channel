add_subdirectory(channel)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    broadcast.cpp
    mpsc.cpp
    receiver.cpp
    sender.cpp
)
