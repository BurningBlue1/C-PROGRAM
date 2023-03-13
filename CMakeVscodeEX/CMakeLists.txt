# 指定最低版本要求
cmake_minimum_required(VERSION 3.0)
# 指定项目名称
project(HELLO)
# 指定生成的可执行文件的名字 源文件
add_executable(hello_cmake hello.cpp)
## 此时等价于 g++ hello.cpp -o hello_cmake
