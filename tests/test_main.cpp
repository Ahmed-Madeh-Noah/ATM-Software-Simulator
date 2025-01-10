#include <gtest/gtest.h>
#include "ATMUtil.h"

TEST(Add, PostiveNumbers) {
    EXPECT_EQ(add(10, 1), 11);
}

TEST(Add, NegativeNumbers) {
    EXPECT_EQ(add(-11, -2), -13);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
