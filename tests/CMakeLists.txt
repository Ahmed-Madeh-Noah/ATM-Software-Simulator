include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(User_Test User_Test.cpp)
target_link_libraries(User_Test gtest_main User)
add_test(NAME User_Test COMMAND User_Test)

add_executable(ATMUtil_Test ATMUtil_Test.cpp)
target_link_libraries(ATMUtil_Test gtest_main ATMUtil User)
add_test(NAME ATMUtil_Test COMMAND ATMUtil_Test)

set_target_properties(User_Test ATMUtil_Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
