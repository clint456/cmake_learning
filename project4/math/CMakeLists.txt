#配置静态链接库

#查找当前目录下的所有源文件
#并将源文件目录保存至DIS-SRCS
aux_source_directory(. DIR_SRCS_LIB)

#生成静态链接库
add_library(mathFunction ${DIR_SRCS_LIB})
