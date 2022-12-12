include_directories(./)
aux_source_directory(./ source_cpp)


add_executable(map_interface ${source_cpp})
