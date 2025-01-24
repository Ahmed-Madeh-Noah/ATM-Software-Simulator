#include <gtest/gtest.h>
#include "Users.h"

TEST(UsersTest, SubtractTest) {
    EXPECT_EQ(subtract(5, 3), 2);
    EXPECT_EQ(subtract(10, 15), -5);
    EXPECT_EQ(subtract(0, 0), 0);
}
