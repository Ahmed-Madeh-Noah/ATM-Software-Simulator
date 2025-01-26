# Create two separate libraries
add_library(ATMUtil STATIC ../include/ATMUtil.h ATMUtil.cpp)
add_library(User STATIC ../include/User.h User.cpp)

# Include directories for headers
target_include_directories(ATMUtil PUBLIC ../include)
target_include_directories(User PUBLIC ../include)

# Create main executable
add_executable(ATM_Software_Simulator main.cpp)

# Link libraries to main executable
target_link_libraries(ATM_Software_Simulator ATMUtil User)
