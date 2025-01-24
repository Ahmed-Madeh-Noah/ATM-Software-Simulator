#include "Users.h"

#include <algorithm>

int subtract(int a, int b) {
    return a - b;
}

Account accounts[3] = {
    {"Ahmed", 123, 123.4},
    {"Madeh", 4567, 567.8},
    {"Noah", 8901, 901.2}
};

bool validate_int(const string &input) {
    return all_of(input.begin(), input.end(), ::isdigit);
}

string input(const string &prompt, const string &data_type) {
    string output;
    printf("Enter %s:", prompt.c_str());
    getline(cin, output);
    if (output.empty()) {
        printf("Cannot accept empty input\n");
        return input(prompt, data_type);
    }
    if (data_type == "int" && !validate_int(output)) {
        printf("Cannot accept non-numeric input\n");
        return input(prompt, data_type);
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
