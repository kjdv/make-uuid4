cmake_minimum_required(VERSION 3.10)

project(make-uuid4)
set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)
find_package(GTest MODULE REQUIRED)
find_library(GMOCK_LIBRARIES gmock)
enable_testing()

find_package(fmt CONFIG REQUIRED)
find_package(cxxopts CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)

# install rules
install(TARGETS make-uuid4)
