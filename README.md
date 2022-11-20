# Cmake_Learning

## 基础使用方法 ##

```cmake
cmake_minimum_required(VERSION <min>）
```
- `<min>`可选的是每个 CMake 版本的 形式

``` cmake
PROJECT(projectname [CXX] [C] [Java]) 
```

- 指定工程的名称
- 指定工程支持的语言（可以忽略，默认支持所有语言）


```cmake 
add_executable(<name> 
               [EXCLUDE_FROM_ALL]
               [source1] [source2 ...])
```

 - `<name>`构建可执行文件的名称
 - `[EXCLUDE_FROM_ALL]`这里可以设置ture or false
 - `[source1] [source2 ...]` 源文件名



``` cmake 
aux_source_directory(<dir> <variable>)
# 查找<dir>目录下的所有源文件
# 并将名称保存到 <variable> 变量中
```

```cmake
add_subdirectory(source_dir)
# source_dir将子目录添加到生成中。
```

```cmake
include_directories ([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
# 将指定目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径。
# 这个与add_subdirectory作用相同
 ```

```cmake
target_link_libraries(<target> ... <item>... ...)
# 将静态链接库指向目标对象
```
- `<item>`静态链接库
- `<target>` 需要链接的对象

```cmake 
set(<variable> <value>... [PARENT_SCOPE])
# 将普通变量、缓存变量或环境变量设置为给定值。
```
> 例如
> ```cmake
> set (VALUE_1 "default value")
> set (VALUE_2 "default value")
>
> set (VALUE_1 "value 1")  # A
> set (VALUE_2 ${VALUE_2} "value 2")  # B
>
>message("value 1:" ${VALUE_1})
> message("value 2:" ${VALUE_2})
> ```
> - 输出结果:
> ```
> ...
> value 1:value 1
> value 2:default valuevalue 2
> ...
> ````

```cmake
option(<variable> "<help_text>" [value])
# 提供用户可以选择性选择的布尔选项。
```
> 例如
>```cmake
># 是否使用自己的 MathFunctions 库
>option (USE_MYMATH
>	   "Use provided math implementation" OFF)
>```

```cmake
configure_file(<input> <output>
               [COPYONLY] [ESCAPE_QUOTES] [@ONLY]
               [NEWLINE_STYLE [UNIX|DOS|WIN32|LF|CRLF] ])
```

- configure_file 主要实现如下两个功能:

> -  将 `<input>` 文件里面的内容全部复制到 `<output>` 文件中；
> - 根据参数规则，替换 @VAR@ 或 ${VAR} 变量；

通俗来说： 让普通文件，也能使用CMake中的变量

>>例如
>>
>> ```cmake
>>cmake_minimum_required(VERSION 3.5)
>>
>>project(Tutorial)
>>
>>message(STATUS "PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
>>message(STATUS "PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})
>>
>>set(CMAKEDEFINE_VAR1 1)
>>set(CMAKEDEFINE_VAR2 0)
>>
>>set(DEFINE_VAR1 1)
>>set(DEFINE_VAR2 0)
>>
>>
>>configure_file (
>>  "${PROJECT_SOURCE_DIR}/Config.h.in"
>>  "${PROJECT_BINARY_DIR}/Config.h"
>>  )
>>
>>include_directories("$PROJECT_SOURCE_DIR")
>>
>>add_executable(DEMO tutorial.cpp)
>>```

