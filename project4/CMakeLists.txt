# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

#自动将当前源目录和生成目录添加到包含路径。
#如果启用此变量，CMake 会自动将CMAKE_CURRENT_SOURCE_DIR和CMAKE_CURRENT_BINARY_DIR添加到每个目录的包含路径。
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
	   "Use provided math implementation" OFF)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
 # include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} mathFunction)
  #set(A B)将B的值赋给A
endif (USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})

#message("EXTRA_LIBS value is :"${EXTRA_LIBS} )


