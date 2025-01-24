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

bool get_user(Account &curr_user);

string remove_trailing_zeros(const string &balance);

string convert_to_thousand_separated(const double &balance);

#endif // USERS_H
