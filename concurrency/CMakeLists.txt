include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(concurrency ${source_cpp})
