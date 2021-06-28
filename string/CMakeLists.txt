include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(string ${source_cpp})
