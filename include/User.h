#ifndef USERS_H
#define USERS_H

#include <iostream>

using namespace std;

int subtract(int a, int b);

struct Account {
    string username;
    int pin;
    double balance;
};

extern Account accounts[3];

bool validate_int(const string &input);

string input(const string &prompt, const string &data_type = "string");

Account *get_user(const string &username);

string remove_trailing_zeros(const double &balance);

string convert_to_thousand_separated(const double &balance);

bool change_pin_inputs(int &pin, const string &needed_pin = "old");

#endif // USERS_H
