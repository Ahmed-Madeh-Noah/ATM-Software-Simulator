# Fetch GoogleTest
add_subdirectory(libs/googletest)
include(GoogleTest)

# Enable testing
enable_testing()

# Add the User test
add_executable(User_Test User_Test.cpp)
target_link_libraries(User_Test User gtest gtest_main)
gtest_discover_tests(User_Test)

# Add the ATMUtil test
add_executable(ATMUtil_Test ATMUtil_Test.cpp)
target_link_libraries(ATMUtil_Test ATMUtil User gtest gtest_main)
gtest_discover_tests(ATMUtil_Test)
