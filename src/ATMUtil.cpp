#include "ATMUtil.h"

int add(int a, int b) {
    return a + b;
}

bool login(string &username, int &pin) {
    string inputPin;
    constexpr int maxPinTrials = 3;
    int pinTrials = 0;
    username = input("your username");
    if (!get_user(username, pin)) {
        printf("Invalid username\n");
        return false;
    }
    do {
        if (inputPin == "-1")
            return false;
        if (pinTrials >= maxPinTrials) {
            printf("Maximum PIN entry attempts exceeded\n");
            return false;
        }
        if (pinTrials)
            printf("#%d PIN entry attempts left out of #%d\n", maxPinTrials - pinTrials, maxPinTrials);
        inputPin = input("your pin (-1 to exit)");
        pinTrials++;
    } while (stoi(inputPin) != pin);
    return true;
}
