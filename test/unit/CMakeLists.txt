# Test framework
find_package(GTest REQUIRED)

# Unit test runner (executable)
file(GLOB_RECURSE UNIT_TEST_SOURCES "*.cpp")
add_executable(QuantFinanceModelsUnitTestRunner ${UNIT_TEST_SOURCES})
target_include_directories(QuantFinanceModelsUnitTestRunner
  PRIVATE ${GTest_INCLUDE_DIR})
target_link_libraries(QuantFinanceModelsUnitTestRunner
  PRIVATE QuantFinanceModels GTest::gtest_main)
