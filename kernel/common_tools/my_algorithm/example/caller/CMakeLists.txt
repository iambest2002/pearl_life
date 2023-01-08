# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
include_directories(${PROJECT_SOURCE_DIR}/base_algorithm/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
aux_source_directory(. SRC_LIST)
link_libraries(base_algorithm)
add_executable(client ${SRC_LIST})
