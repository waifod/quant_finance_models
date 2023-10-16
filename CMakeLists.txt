cmake_minimum_required(VERSION 3.10)
project(QuantFinanceModels
  VERSION 1.0
  DESCRIPTION "Quantitative Finance Models (QFM) library and CLI application"
  LANGUAGES CXX
)

# CMake configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Dependencies
find_package(Boost 1.65 COMPONENTS program_options REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(CURL REQUIRED)

# Library
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(QuantFinanceModels SHARED ${SOURCES})
target_include_directories(QuantFinanceModels
  PUBLIC include
  PRIVATE ${Boost_INCLUDE_DIR} ${CURL_INCLUDE_DIR})
target_link_libraries(QuantFinanceModels
  PRIVATE ${Boost_LIBRARIES} ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)

# Executable (CLI application)
add_executable(quant_finance_models "main.cpp")
target_include_directories(quant_finance_models
  PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(quant_finance_models PRIVATE QuantFinanceModels ${Boost_LIBRARIES})

# Add tests
add_subdirectory(test)
