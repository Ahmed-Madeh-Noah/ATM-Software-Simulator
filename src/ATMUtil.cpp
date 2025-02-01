#include "ATMUtil.hpp"

int add(const int a, const int b) {
    return a + b;
}

Account *login() {
    int pin = 1, pinTrials = 0;
    auto *const curr_user = get_user(input("your username"));
    if (!curr_user) {
        printf("Invalid username\n");
        return nullptr;
    }
    do {
        constexpr int maxPinTrials = 3;
        if (!pin)
            return nullptr;
        if (pinTrials >= maxPinTrials) {
            printf("Maximum PIN entry attempts exceeded\n");
            return nullptr;
        }
        if (pinTrials)
            printf("#%d PIN entry attempts left out of #%d\n", maxPinTrials - pinTrials, maxPinTrials);
        pin = stoi(input("your PIN (0 to exit)", "int"));
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

void transfer_balance(Account *const curr_user) {
    const string recipient_username = input("the username of the recipient (0 to exit)");
    if (recipient_username != "0") {
        auto *const recipient = get_user(recipient_username);
        if (!recipient) {
            printf("Invalid username\n");
            return;
        }
        if (curr_user->username == recipient_username) {
            printf("Cannot transfer balance to yourself\n");
            return;
        }
        const int amount = stoi(input("the amount to transfer (0 to exist)", "int"));
        if (amount != 0) {
            if (amount > curr_user->balance)
                printf("Not enough balance to transfer\n");
            else {
                printf("Successfully transferred %s EGP balance to %s\n",
                       convert_to_thousand_separated(amount).c_str(), recipient->username.c_str());
                curr_user->balance -= amount;
                recipient->balance += amount;
            }
        }
    }
}

bool change_pin(Account *const curr_user) {
    int oldPin;
    if (change_pin_inputs(oldPin)) {
        if (oldPin != curr_user->pin)
            printf("Wrong old PIN. Exiting ...\n");
        else {
            int newPin, confirmationPin;
            if (change_pin_inputs(newPin, "new") && change_pin_inputs(confirmationPin, "confirmation")) {
                if (newPin == confirmationPin)
                    curr_user->pin = newPin;
                else
                    printf("New PIN and the confirmation PIN do not match\n");
            }
            return true;
        }
    }
    return false;
}
