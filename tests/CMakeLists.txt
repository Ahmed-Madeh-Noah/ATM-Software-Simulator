# Fetch GoogleTest
add_subdirectory(libs/googletest)
include(GoogleTest)

# Enable testing
enable_testing()

# Add test executable
add_executable(ATMUtil_Test ATMUtil_Test.cpp)
add_executable(User_Test User_Test.cpp)

# Link libraries
target_link_libraries(ATMUtil_Test ATMUtil gtest gtest_main)
target_link_libraries(User_Test User gtest gtest_main)

# Discover tests
gtest_discover_tests(ATMUtil_Test)
gtest_discover_tests(User_Test)
