#include <gtest/gtest.h>
#include "ATMUtil.hpp"

TEST(ATMUtilTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
}
