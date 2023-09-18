cmake_minimum_required(VERSION 3.10)
project(QuantFinanceModels)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIR})

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(quant_finance_models "main.cpp" ${SOURCES})
target_link_libraries(quant_finance_models LINK_PUBLIC ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${GTest_LIBRARIES})

<<<<<<< HEAD
## Testing
enable_testing()
include_directories(tests)
file(GLOB_RECURSE TESTS "tests/*.cpp")
add_executable(runUnitTests tests/qfm/asset/test_asset.cpp ${TESTS})
gtest_discover_tests(runUnitTests)
=======
# Testing
add_subdirectory(test)
>>>>>>> f17942a (Add GoogleTest framework)
