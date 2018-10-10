#include "../parse_table.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

class parseTableTest : public Test
{
protected:
    parseTableTest() : pt(3) {}
    ~parseTableTest() {}

    pTable pt;

    virtual void SetUp() {
        pt.set(0, 0, 3, accept);
        pt.set(2, 1, 2, reduce);
        pt.set(1, 2, 7, shift);
        pt.set(0, 1, 1, gotoState);
    }

    virtual void TearDown() {}
};

TEST_F(parseTableTest, get_single_one) {
    move m = pt.get(0, 0);

    EXPECT_EQ(m.num, 3);
    EXPECT_EQ(m.type, accept);
}

TEST_F(parseTableTest, get_single_two) {
    move m = pt.get(2, 1);

    EXPECT_EQ(m.num, 2);
    EXPECT_EQ(m.type, reduce);
}

TEST_F(parseTableTest, get_single_three) {
    move m = pt.get(1, 2);

    EXPECT_EQ(m.num, 7);
    EXPECT_EQ(m.type, shift);
}

TEST_F(parseTableTest, get_single_four) {
    move m = pt.get(0, 1);

    EXPECT_EQ(m.num, 1);
    EXPECT_EQ(m.type, gotoState);
}
