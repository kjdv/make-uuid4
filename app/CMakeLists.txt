add_executable(make-uuid4 main.cc)
target_link_libraries(make-uuid4 PUBLIC cxxopts::cxxopts uuid4-common)
