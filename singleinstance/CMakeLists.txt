include_directories(./)
aux_source_directory(./ source_cpp)


add_executable(single_instance ${source_cpp})
