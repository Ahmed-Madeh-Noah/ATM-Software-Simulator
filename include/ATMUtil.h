#ifndef ATMUTIL_H
#define ATMUTIL_H

#include "Users.h"

int add(int a, int b);

Account *login();

size_t get_max_string_length(const string operations[6]);

void display_menu(const string operations[6]);

int show_main_menu();

void check_balance(const Account *curr_user);

void withdraw_cash(Account *curr_user);

void deposit_cash(Account *curr_user);

#endif //ATMUTIL_H
