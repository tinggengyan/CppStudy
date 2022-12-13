include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(c_cpp_string_chararray ${source_cpp})
