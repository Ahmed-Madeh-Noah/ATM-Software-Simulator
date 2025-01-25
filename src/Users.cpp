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
        printf("Cannot accept an empty input\n");
        return input(prompt, data_type);
    }
    if (data_type == "int" && !validate_int(output)) {
        printf("Cannot accept non-numeric input\n");
        return input(prompt, data_type);
    }
    return output;
}

Account *get_user(const string &username) {
    for (Account &account: accounts)
        if (account.username == username)
            return &account;
    return nullptr;
}

string remove_trailing_zeros(const double &balance) {
    string output = to_string(balance);
    for (size_t index = output.size() - 1; index > output.find('.') + 1; index--) {
        if (output[index] == '0')
            output.erase(index, 1);
        else
            break;
    }
    return output;
}

string convert_to_thousand_separated(const double &balance) {
    string string_balance = remove_trailing_zeros(balance);
    size_t dotPos = string_balance.find('.');
    for (int index = dotPos; index > 0; index--) {
        if (index != dotPos && (dotPos - index) % 3 == 0)
            string_balance.insert(index, ",");
    }
    return string_balance;
}
