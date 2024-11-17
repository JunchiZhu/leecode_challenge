cmake_minimum_required(VERSION 3.27)
project(code_with_son)
set(CMAKE_CXX_STANDARD 14)
# 儿子 cmake section
add_executable(code_with_son_hanfu hanfu/main.cpp)


# 爸爸 cmake section
add_executable(helper junchi/helper.cpp
        junchi/helper.h)
add_executable(linked_list junchi/linked_list.cpp)
add_executable(day_one junchi/day_one.cpp)
add_executable(day_two junchi/day_two.cpp)
add_executable(day_three junchi/day_three.cpp)

