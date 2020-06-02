add_executable(uuid4 main.cc)
target_link_libraries(uuid4 PUBLIC cxxopts::cxxopts uuid4_common)
