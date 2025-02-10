#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>

int subtract(int a, int b);

struct Account {
    std::string username;
    int pin;
    double balance;
};

extern Account accounts[3];

bool validate_int(const std::string &input);

std::string input(const std::string &prompt, const std::string &data_type = "std::string");

Account *get_user(const std::string &username);

std::string remove_trailing_zeros(const double &balance);

std::string convert_to_thousand_separated(const double &balance);

bool change_pin_inputs(int &pin, const std::string &needed_pin = "old");

#endif // USERS_H
