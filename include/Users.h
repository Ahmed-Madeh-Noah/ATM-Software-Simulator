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

extern Account accounts[];

bool validate_int(const string &input);

string input(const string &prompt, const string &data_type = "string");

bool get_user(Account &curr_user);

#endif // USERS_H
