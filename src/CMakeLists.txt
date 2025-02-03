# Create two separate libraries
add_library(ATMUtil STATIC ATMUtil.cpp)
add_library(User STATIC User.cpp)

# Include directories for headers
target_include_directories(ATMUtil PUBLIC ../include)
target_include_directories(User PUBLIC ../include)

# Create main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link libraries to main executable
target_link_libraries(${PROJECT_NAME} ATMUtil User)
