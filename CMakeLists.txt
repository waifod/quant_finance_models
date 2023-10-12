cmake_minimum_required(VERSION 3.10)
project(QuantFinanceModels)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.75 COMPONENTS json REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(quant_finance_models "main.cpp" ${SOURCES})
target_link_libraries(quant_finance_models LINK_PUBLIC ${Boost_LIBRARIES} ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)

# Testing
add_subdirectory(test)
