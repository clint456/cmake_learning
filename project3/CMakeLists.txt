# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo2)

#查找当前目录下的所有源文件
#并将源文件目录保存至DIS-SRCS
aux_source_directory(. DIR_SRCS)

#添加math子目录
add_subdirectory(math)

#将指定目标生成可执行文件
add_executable(Demo main.cpp)

#将静态链接库指向目标对象
target_link_libraries(Demo mathFunction)
