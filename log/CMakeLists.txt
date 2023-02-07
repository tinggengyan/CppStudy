include_directories(./)
aux_source_directory(./ source_cpp)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    ADD_DEFINITIONS(-DDebug)
endif ()

add_executable(log ${source_cpp})
