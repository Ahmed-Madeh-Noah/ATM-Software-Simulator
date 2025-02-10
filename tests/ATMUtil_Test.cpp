#include <gtest/gtest.h>
#include "ATMUtil.h"

TEST(ATMUtilTest, AddTest) {
    EXPECT_EQ(ATMUtil::add(2, 3), 5);
    EXPECT_EQ(ATMUtil::add(-1, 1), 0);
    EXPECT_EQ(ATMUtil::add(0, 0), 0);
}
