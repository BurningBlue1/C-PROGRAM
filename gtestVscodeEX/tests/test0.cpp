#include "test.h"
#include "gtest/gtest.h"

TEST(TESTCASE, test0)
{
    EXPECT_EQ(0, 0);
    EXPECT_EQ("a", "a");
}

TEST(TESTCASE, test1)
{
    TestClass tmp;
    EXPECT_EQ(1, tmp.GetVar());
}