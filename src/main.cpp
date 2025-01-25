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
                else if (operation == 3)
                    deposit_cash(currUser);
                else if (operation == 4)
                    transfer_balance(currUser);
                else if (operation == 5) {
                    if (!change_pin(currUser))
                        break;
                }
            }
        }
    }
    return 0;
}
