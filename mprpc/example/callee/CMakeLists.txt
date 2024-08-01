
aux_source_directory(. SRC_LIST)
add_executable(provider ${SRC_LIST} ../user.pb.cc)
target_link_libraries(provider mprpc protobuf) 