aux_source_directory(. SRC_LIST)


# 配置头文件信息
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)
add_library(base_algorithm ${SRC_LIST})
