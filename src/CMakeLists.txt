# Create the User library
add_library(User STATIC User.cpp)
target_include_directories(User PUBLIC ../include)

# Create the ATMUtil library
add_library(ATMUtil STATIC ATMUtil.cpp)
target_include_directories(ATMUtil PUBLIC ../include)

# Create main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link libraries to main executable
target_link_libraries(${PROJECT_NAME} ATMUtil User)
