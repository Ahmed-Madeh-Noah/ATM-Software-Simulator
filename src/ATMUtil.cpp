#include "ATMUtil.h"

int add(int a, int b) {
    return a + b;
}

Account *login() {
    constexpr int maxPinTrials = 3;
    int pin = 1, pinTrials = 0;
    auto *curr_user = get_user(input("your username"));
    if (!curr_user) {
        printf("Invalid username\n");
        return nullptr;
    }
    do {
        if (!pin)
            return nullptr;
        if (pinTrials >= maxPinTrials) {
            printf("Maximum PIN entry attempts exceeded\n");
            return nullptr;
        }
        if (pinTrials)
            printf("#%d PIN entry attempts left out of #%d\n", maxPinTrials - pinTrials, maxPinTrials);
        pin = stoi(input("your pin (0 to exit)", "int"));
        pinTrials++;
    } while (pin != curr_user->pin);
    return curr_user;
}

size_t get_max_string_length(const string operations[6]) {
    size_t maxLength = 0;
    for (int i = 0; i < 6; i++)
        if (operations[i].length() > maxLength)
            maxLength = operations[i].length();
    return maxLength;
}

void display_menu(const string operations[6]) {
    const size_t maxLength = get_max_string_length(operations) + 4;
    for (int i = 0; i < 6; i++) {
        printf("\t[%d] %s", i, operations[i].c_str());
        if (i % 2) {
            printf("\n");
        } else {
            size_t padding = maxLength - operations[i].length();
            printf("%s", string(padding, ' ').c_str());
        }
    }
}

int show_main_menu() {
    const string operations[6] = {
        "Sign out", "Check your balance",
        "Withdraw cash", "Deposit cash",
        "Transfer balance", "Change PIN"
    };
    display_menu(operations);
    const int opNum = stoi(input("the operation number you want to make", "int"));
    if (opNum < 0 || opNum > 5) {
        printf("Invalid operation number\n");
        return show_main_menu();
    }
    return opNum;
}

void check_balance(const Account *const curr_user) {
    const string string_balance = convert_to_thousand_separated(curr_user->balance);
    printf("Your credit is %s EGP\n", string_balance.c_str());
}

void withdraw_cash(Account *const curr_user) {
    const int amount = stoi(input("the amount to withdraw (0 to exist)", "int"));
    if (amount != 0) {
        if (amount > curr_user->balance)
            printf("Not enough balance to withdraw\n");
        else if (amount % 50)
            printf("Only 50, 100, and 200 EGP bills are available\n");
        else {
            printf("Successfully withdrawn %s EGP balance\n", convert_to_thousand_separated(amount).c_str());
            curr_user->balance -= amount;
        }
    }
}

void deposit_cash(Account *const curr_user) {
    const int amount = stoi(input("the amount to deposit (0 to exist)", "int"));
    if (amount != 0) {
        if (amount % 50)
            printf("Only 50, 100, and 200 EGP bills are allowed\n");
        else {
            printf("Successfully deposited %s EGP balance\n", convert_to_thousand_separated(amount).c_str());
            curr_user->balance += amount;
        }
    }
}
