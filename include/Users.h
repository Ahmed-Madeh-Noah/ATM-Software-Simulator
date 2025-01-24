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

string input(const string &prompt);

bool get_user(const string &username, int &pin);

#endif // USERS_H
