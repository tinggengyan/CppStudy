include_directories(./)
include_directories(../third_party)
aux_source_directory(./ source_cpp)
add_executable(json_demo ${source_cpp})