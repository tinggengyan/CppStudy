include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(default_delete ${source_cpp})
