#include "User.h"
#include <algorithm>

namespace User {
    int subtract(const int a, const int b) {
        return a - b;
    }

    Account accounts[3] = {
        {"Ahmed", 123, 123.4},
        {"Madeh", 4567, 567.8},
        {"Noah", 8901, 901.2}
    };

    bool validate_int(const std::string &input) {
        return all_of(input.begin(), input.end(), ::isdigit);
    }

    std::string input(const std::string &prompt, const std::string &data_type) {
        std::string output;
        printf("Enter %s:", prompt.c_str());
        std::getline(std::cin, output);
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

    Account *get_user(const std::string &username) {
        for (Account &account: accounts)
            if (account.username == username)
                return &account;
        return nullptr;
    }

    std::string remove_trailing_zeros(const double &balance) {
        std::string output = std::to_string(balance);
        for (size_t index = output.size() - 1; index > output.find('.') + 1; index--) {
            if (output[index] == '0')
                output.erase(index, 1);
            else
                break;
        }
        return output;
    }

    std::string convert_to_thousand_separated(const double &balance) {
        std::string string_balance = remove_trailing_zeros(balance);
        size_t dotPos = string_balance.find('.');
        for (size_t index = dotPos; index-- > 0;) {
            if (index != dotPos && (dotPos - index) % 3 == 0)
                string_balance.insert(index, ",");
        }
        return string_balance;
    }

    bool change_pin_inputs(int &pin, const std::string &needed_pin) {
        if (needed_pin == "old")
            pin = stoi(input("your old PIN (0 to exist)", "int"));
        else if (needed_pin == "new")
            pin = stoi(input("your new PIN (0 to exist)", "int"));
        else if (needed_pin == "confirmation")
            pin = stoi(input("your new PIN again for confirmation (0 to exist)", "int"));
        if (!pin) {
            if (needed_pin == "new")
                printf("This is treated as exiting not a new PIN\n");
            else if (needed_pin == "confirmation")
                printf("This is treated as exiting not a new PIN confirmation\n");
            return false;
        }
        return true;
    }
}
