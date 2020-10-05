#ifndef TST_CAPLIBPP_UNIT_TEST_H
#define TST_CAPLIBPP_UNIT_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(CAPLibppTest, caplibpp_unit_test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_CAPLIBPP_UNIT_TEST_H
