#include "ATMUtil.h"

int main() {
    while (true) {
        string username;
        int pin = 0;
        if (login(username, pin)) {
            printf("Welcome %s\n", username.c_str());
        }
    }
    return 0;
}
