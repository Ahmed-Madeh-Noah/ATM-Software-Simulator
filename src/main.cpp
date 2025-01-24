#include "ATMUtil.h"

int main() {
    while (true) {
        auto *currUser = login();
        if (currUser) {
            printf("Welcome %s\n", currUser->username.c_str());
            while (true) {
                const int operation = show_main_menu();
                if (operation == 0)
                    break;
                if (operation == 1)
                    check_balance(currUser);
                else if (operation == 2)
                    withdraw_cash(currUser);
            }
        }
    }
    return 0;
}
