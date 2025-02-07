# Disable GoogleTest optional features
set(BUILD_GMOCK OFF CACHE BOOL "Disable building googlemock" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest" FORCE)

# Fetch GoogleTest
add_subdirectory(external/googletest)
include(GoogleTest)

# Add the User test
add_executable(User_Test User_Test.cpp)
target_link_libraries(User_Test User gtest gtest_main)
gtest_discover_tests(User_Test)

# Add the ATMUtil test
add_executable(ATMUtil_Test ATMUtil_Test.cpp)
target_link_libraries(ATMUtil_Test ATMUtil User gtest gtest_main)
gtest_discover_tests(ATMUtil_Test)
