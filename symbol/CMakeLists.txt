include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(symbol ${source_cpp})
