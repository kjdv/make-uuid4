file(GLOB sources *.c *.cc *.cpp *.h *.hh)

add_executable(uuid4_test ${sources})
target_link_libraries(uuid4_test uuid4_common ${GMOCK_LIBRARIES} GTest::GTest GTest::Main)

gtest_discover_tests(uuid4_test)
