#ifndef ATMUTIL_H
#define ATMUTIL_H

#include "User.h"

namespace ATMUtil {
    int add(int a, int b);

    User::Account *login();

    size_t get_max_string_length(const std::string operations[6]);

    void display_menu(const std::string operations[6]);

    int show_main_menu();

    void check_balance(const User::Account *curr_user);

    void withdraw_cash(User::Account *curr_user);

    void deposit_cash(User::Account *curr_user);

    void transfer_balance(User::Account *curr_user);

    bool change_pin(User::Account *curr_user);
}

#endif //ATMUTIL_H
