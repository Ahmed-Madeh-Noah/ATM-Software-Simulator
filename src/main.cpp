#include "ATMUtil.h"

int main() {
    while (true) {
        string username;
        int pin = 0;
        if (login(username, pin)) {
            printf("Welcome %s\n", username.c_str());
            while (true) {
                const int operation = show_main_menu();
                if (operation == 0)
                    break;
            }
        }
    }
    return 0;
}
