#include "ATMUtil.h"

int main() {
    while (true) {
        Account currUser;
        if (login(currUser)) {
            printf("Welcome %s\n", currUser.username.c_str());
            while (true) {
                const int operation = show_main_menu();
                if (operation == 0)
                    break;
                else if (operation == 1)
                    check_balance(currUser);
                else if (operation == 2)
                    withdraw_cash(currUser.balance);
                for (Account &account: accounts) {
                    printf("Account username: %s, Account PIN: %d, Account balance: %f\n", account.username,
                           account.pin, account.balance);
                }
            }
        }
    }
    return 0;
}
