#include "Users.h"

int subtract(int a, int b) {
    return a - b;
}

Account accounts[3] = {
    {"Ahmed", 123, 123.4},
    {"Madeh", 4567, 567.8},
    {"Noah", 8901, 901.2}
};

string input(const string &prompt) {
    string output;
    printf("Enter %s:", prompt.c_str());
    getline(cin, output);
    if (output.empty()) {
        printf("Cannot accept empty input\n");
        return input(prompt);
    }
    return output;
}

bool get_user(const string &username, int &pin) {
    for (Account &account: accounts) {
        if (account.username == username) {
            pin = account.pin;
            return true;
        }
    }
    return false;
}
