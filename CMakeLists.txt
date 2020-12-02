cmake_minimum_required(VERSION 3.9.0)
set (CMAKE_CXX_STANDARD 17)
project(cpp_proj VERSION 0.1.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(CTest)
enable_testing()

file(GLOB MAIN_SOURCE_FILES "./*.cpp")
file(GLOB TEST_SOURCE_FILES "./Tests/*.cpp" "./Tests/Mocks/*.cpp")

add_executable(cpp_proj main.cxx ${MAIN_SOURCE_FILES})

add_executable(cpp_proj_tests ${MAIN_SOURCE_FILES} ${TEST_SOURCE_FILES})
target_link_libraries(cpp_proj_tests ${GTEST_LIBRARIES} "/usr/local/lib/libgmock.a")

gtest_discover_tests(cpp_proj_tests)