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
            }
        }
    }
    return 0;
}
