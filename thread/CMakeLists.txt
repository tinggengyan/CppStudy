include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(thread_main ${source_cpp} ../or/main.cpp)
