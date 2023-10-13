cmake_minimum_required(VERSION 3.10)
project(QuantFinanceModels
  VERSION 1.0
  DESCRIPTION "Quantitative Finance Models"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*,boost-*,cppcoreguidelines-*,google-*,performance-*,portability-*,modernize-*)

find_package(Boost 1.65 REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(CURL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(quant_finance_models "main.cpp" ${SOURCES})

target_include_directories(quant_finance_models
  PUBLIC include
  PRIVATE ${Boost_INCLUDE_DIR} ${CURL_INCLUDE_DIR}
)
target_link_libraries(quant_finance_models
  LINK_PRIVATE ${Boost_LIBRARIES} ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)

add_subdirectory(test)
