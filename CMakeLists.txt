cmake_minimum_required(VERSION 3.10)

project(uuid4)
set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)
find_package(GTest MODULE REQUIRED)
find_library(GMOCK_LIBRARIES gmock)
enable_testing()

find_package(fmt CONFIG REQUIRED)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)

# install rules
install(TARGETS uuid4)
