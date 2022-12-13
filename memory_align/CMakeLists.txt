include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(memory_align ${source_cpp})