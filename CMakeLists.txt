cmake_minimum_required(VERSION 3.0)
project(pearl_house)

# 设置so库生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/base_algorithm/include)
# 设置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC")


# 添加第三方的库
set(INC_DIR /usr/local/include/)
set(LINK_DIR /usr/local/lib)
 
include_directories(${INC_DIR})
link_directories(${LINK_DIR})


# 加载子目录
add_subdirectory(kernel/base_algorithm)
