# CppStudy


1. launch.json: "program": "${workspaceFolder}/output/a.out"
2. 新建模块的cmake配置,均将可执行文件输出到,根目录的output文件夹中
3. 且生成物的名字均为 a.out

以上这么做的原因在为了debug方便

## debug 方法
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ../static/
make
F5