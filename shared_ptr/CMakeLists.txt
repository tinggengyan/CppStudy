include_directories(./)
aux_source_directory(./ source_cpp)


add_executable(shared_ptr ${source_cpp} main.cpp Request.cpp Request.h)
