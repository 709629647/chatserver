
#配置头文件搜索路径  -I
#include_directories()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#配置库文件搜索路径 -L
#link_directories()
set(SRC_LIST testmuduo.cpp)
add_executable(testserver ${SRC_LIST})
target_link_libraries(testserver muduo_net muduo_base pthread)
 