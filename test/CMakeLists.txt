file(GLOB sources *.c *.cc *.cpp *.h *.hh)

add_executable(uuid4-test ${sources})
target_link_libraries(uuid4-test uuid4-common ${GMOCK_LIBRARIES} GTest::GTest GTest::Main)

gtest_discover_tests(uuid4-test)
