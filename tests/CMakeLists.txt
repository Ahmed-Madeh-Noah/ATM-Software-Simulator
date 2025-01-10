project(Google_tests)

add_subdirectory(libs/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Google_Tests_run test_ATMUtil.cpp)

target_link_libraries(Google_Tests_run ATMUtil)

target_link_libraries(Google_Tests_run gtest gtest_main)
