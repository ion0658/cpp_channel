if (ENABLE_HEADER_ONLY)
    add_library(${PROJECT_NAME} INTERFACE)
    target_include_directories(
        ${PROJECT_NAME}
            INTERFACE
                ${PROJECT_SOURCE_DIR}/include
    )
else()
    if (ENABLE_SHARED)
        add_library(${PROJECT_NAME} SHARED)
    else()
        add_library(${PROJECT_NAME} STATIC)
    endif()
    target_include_directories(
        ${PROJECT_NAME}
            PUBLIC
                ${PROJECT_SOURCE_DIR}/include
    )
    add_subdirectory(declarations)
    target_compile_options(
        ${PROJECT_NAME} PRIVATE
            $<$<CXX_COMPILER_ID:MSVC>: /W4>
            $<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
    )
    include(GenerateExportHeader)
    generate_export_header(
    ${PROJECT_NAME}
        EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/cpp_channel_export.hpp
    )
    target_include_directories(
        ${PROJECT_NAME}
            PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

    install(
        TARGETS
            ${PROJECT_NAME}
        RUNTIME
            DESTINATION bin
        LIBRARY
            DESTINATION lib
        ARCHIVE
            DESTINATION lib
    )
    install(
        DIRECTORY
            ${PROJECT_SOURCE_DIR}/include
            DESTINATION include
    )
endif()
