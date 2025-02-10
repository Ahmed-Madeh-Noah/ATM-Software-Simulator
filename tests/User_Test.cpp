#include <gtest/gtest.h>
#include "User.h"

TEST(UserTest, SubtractTest) {
    EXPECT_EQ(User::subtract(5, 3), 2);
    EXPECT_EQ(User::subtract(10, 15), -5);
    EXPECT_EQ(User::subtract(0, 0), 0);
}
