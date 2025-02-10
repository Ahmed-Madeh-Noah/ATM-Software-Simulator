#include "ATMUtil.h"

int main() {
    while (true) {
        auto *currUser = ATMUtil::login();
        if (currUser) {
            printf("Welcome %s\n", currUser->username.c_str());
            while (true) {
                const int operation = ATMUtil::show_main_menu();
                if (operation == 0)
                    break;
                if (operation == 1)
                    ATMUtil::check_balance(currUser);
                else if (operation == 2)
                    ATMUtil::withdraw_cash(currUser);
                else if (operation == 3)
                    ATMUtil::deposit_cash(currUser);
                else if (operation == 4)
                    ATMUtil::transfer_balance(currUser);
                else if (operation == 5) {
                    if (!ATMUtil::change_pin(currUser))
                        break;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
