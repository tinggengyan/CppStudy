include_directories(./)
aux_source_directory(./ source_cpp)

add_executable(http ${source_cpp} Stream.cpp Stream.h BufferStream.cpp BufferStream.h SocketStream.cpp SocketStream.h common.h common.cpp HttpParser.h stream_line_reader.cpp stream_line_reader.h)
