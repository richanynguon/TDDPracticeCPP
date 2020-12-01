cmake_minimum_required(VERSION 3.9.0)
set (CMAKE_CXX_STANDARD 17)
project(cpp_proj VERSION 0.1.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(CTest)
enable_testing()

add_executable(cpp_proj main.cpp)

add_executable(cpp_proj_tests ./Tests/main.cpp ./Tests/tests.cpp)
target_link_libraries(cpp_proj_tests ${GTEST_LIBRARIES})

gtest_add_tests(TARGET cpp_proj_tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
