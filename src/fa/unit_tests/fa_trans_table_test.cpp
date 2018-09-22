#include "../fa_trans_table.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

class tTableTest : public Test
{
protected:
    tTableTest() : t(3) {}
    ~tTableTest() {}

    FAtTable t;
    std::vector<int> out;

    virtual void SetUp() {}
    virtual void TearDown() {}
};

/**
 * test setting and getting a single transition
**/
TEST_F(tTableTest, set_get_single) {
    t.addTrans(0, 1, 'a');
    out = t.getTrans(0, 'a');

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], 1);
}

/**
 * test setting multiple different transitions
**/
TEST_F(tTableTest, set_get_mult) {
    t.addTrans(0, 1, 'a');
    t.addTrans(1, 2, 'b');

    out = t.getTrans(0, 'a');

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], 1);

    out = t.getTrans(1, 'b');

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], 2);
}

/**
 * test setting multiple outputs to the same transition
**/
TEST_F(tTableTest, set_mult_same) {
    t.addTrans(0, 1, 'a');
    t.addTrans(0, 2, 'a');

    out = t.getTrans(0, 'a');

    EXPECT_EQ(out.size(), 2);
    EXPECT_EQ(out[0], 1);
    EXPECT_EQ(out[1], 2);
}
