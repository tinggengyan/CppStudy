
include_directories(./lib)

aux_source_directory(./ src)

add_executable(simpleReadWriteLock ${src})
