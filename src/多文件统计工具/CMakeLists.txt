cmake_minimum_required(VERSION 3.16)
project(recruit_stats LANGUAGES C)

# TODO: 显式设置 C11，并把全部实现文件加入可执行目标。
# 这里注意要开启强制使用C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(main main.c stats.c format.c)
