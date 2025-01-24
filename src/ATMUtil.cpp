#include "ATMUtil.h"

int add(int a, int b) {
    return a + b;
}

bool login(Account &curr_user) {
    constexpr int maxPinTrials = 3;
    int pin = 1, pinTrials = 0;
    curr_user.username = input("your username");
    if (!get_user(curr_user)) {
        printf("Invalid username\n");
        return false;
    }
    do {
        if (!pin)
            return false;
        if (pinTrials >= maxPinTrials) {
            printf("Maximum PIN entry attempts exceeded\n");
            return false;
        }
        if (pinTrials)
            printf("#%d PIN entry attempts left out of #%d\n", maxPinTrials - pinTrials, maxPinTrials);
        pin = stoi(input("your pin (0 to exit)", "int"));
        pinTrials++;
    } while (pin != curr_user.pin);
    return true;
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

void check_balance(const Account &curr_user) {
    const string balance = convert_to_thousand_separated(curr_user.balance);
    printf("Your credit is %s EGP\n", balance.c_str());
}
