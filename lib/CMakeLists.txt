file(GLOB public_headers include/*.hh include/*.h)
file(GLOB sources *.cc *.cpp *.c *.hh *.h)

add_library(uuid4_common
    ${public_headers}
    ${sources}
)

set_target_properties(uuid4_common PROPERTIES PUBLIC_HEADER "${public_headers}")
target_include_directories(uuid4_common
    PUBLIC
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
      "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>"
)


target_link_libraries(uuid4_common
    PUBLIC fmt::fmt
)

