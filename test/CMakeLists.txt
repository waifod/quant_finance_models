## Testing
find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIR})
enable_testing()
include_directories(../include)
file(GLOB_RECURSE UNIT_TEST_SOURCES "*.cpp")
add_executable(runUnitTests ${SOURCES} ${UNIT_TEST_SOURCES})
target_link_libraries(
  runUnitTests
  GTest::gtest_main
)
gtest_discover_tests(runUnitTests)