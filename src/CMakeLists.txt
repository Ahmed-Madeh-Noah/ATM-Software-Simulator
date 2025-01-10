add_library(ATMUtil ATMUtil.cpp ../include/ATMUtil.h)

target_include_directories(ATMUtil PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(ATM_Software_Simulator main.cpp
        ATMUtil.cpp)

target_link_libraries(ATM_Software_Simulator ATMUtil)
