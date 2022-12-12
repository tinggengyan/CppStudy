include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(array_and_vector ${source_cpp})
