cmake_minimum_required(VERSION 3.10)

project(uuid4)
set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)
find_package(GTest MODULE REQUIRED)
find_library(GMOCK_LIBRARIES gmock)
enable_testing()


add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(examples)

# install rules
install(TARGETS uuid4
        EXPORT Uuid4Targets
        ARCHIVE DESTINATION lib COMPONENT lib
        PUBLIC_HEADER DESTINATION include/uuid4 COMPONENT dev
)
install(FILES Uuid4Config.cmake DESTINATION share/uuid4)

install(EXPORT Uuid4Targets DESTINATION share/uuid4 NAMESPACE Uuid4::)
export(TARGETS uuid4 NAMESPACE Uuid4:: FILE ${CMAKE_CURRENT_BINARY_DIR}/Uuid4Targets.cmake)
