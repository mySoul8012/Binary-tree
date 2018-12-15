# cmake版本
cmake_minimum_required(VERSION 3.13)
# 项目名称
project(untitled4)

# 设置编译器
SET(CMAKE_CXX_COMPILER "g++")

# 设置编译选项 支持寻找二进制的库文件
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fPIC" )

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp src/model/tree/BitNode.cpp src/model/tree/BitNode.h src/model/tree/Tree.cpp src/model/tree/Tree.h src/model/thread/thread.cpp src/model/thread/thread.h src/model/HuffmanCoding/HuffmanCoding.cpp src/model/HuffmanCoding/HuffmanCoding.h)

#添加头文件搜索路径
include_directories(/usr/local/ /usr/include/)

#添加库文件搜索路径
link_directories(/usr/lib /usr/local/lib)

