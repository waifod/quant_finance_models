cmake_minimum_required(VERSION 3.10)
project(QuantFinanceModels)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(quant_finance_models "main.cpp" ${SOURCES})

# add_subdirectory(test)
