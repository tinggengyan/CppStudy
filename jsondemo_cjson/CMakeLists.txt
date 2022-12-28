include_directories(./)
include_directories(../third_party)


file(GLOB_RECURSE cppFiles ./*.cpp)
file(GLOB_RECURSE cFiles ../third_party/cjson/*.c)



add_executable(cjsonDemo ${cppFiles} ${cFiles})