# Fetch GoogleTest
add_subdirectory(libs/googletest)
include(GoogleTest)

# Enable testing
enable_testing()

# Add test executable
add_executable(ATMUtil_Test test_ATMUtil.cpp)
add_executable(Users_Test test_Users.cpp)

# Link libraries
target_link_libraries(ATMUtil_Test ATMUtil gtest gtest_main)
target_link_libraries(Users_Test Users gtest gtest_main)

# Discover tests
gtest_discover_tests(ATMUtil_Test)
gtest_discover_tests(Users_Test)
