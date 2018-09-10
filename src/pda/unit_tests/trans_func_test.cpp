#include "../trans_func.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

class tFuncTest : public Test
{
protected:
    tFuncTest() {}
    ~tFuncTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

/**
 * test that moves are set correctly
**/
TEST_F(tFuncTest, set_get) {
    tFunc t(3);

    t.setTrans(0, 'a', 't', 1, "aa");

    int nState;
    std::string push;

    t.getTrans(0, 'a', 't', nState, push);

    EXPECT_THAT(nState, Eq(1));
    EXPECT_THAT(push, Eq("aa"));

}

/**
 * test for correct multiple sets and gets
**/
TEST_F(tFuncTest, set_get_multi) {
    tFunc t(3);

    t.setTrans(0, 'a', 't', 1, "aa");
    t.setTrans(2, 'c', 'e', 0, "a");
    t.setTrans(1, 'a', 'e', 2, "bb");

    int nState;
    std::string push;

    t.getTrans(0, 'a', 't', nState, push);

    EXPECT_THAT(nState, Eq(1));
    EXPECT_THAT(push, Eq("aa"));   

    t.getTrans(1, 'a', 'e', nState, push);

    EXPECT_THAT(nState, Eq(2));
    EXPECT_THAT(push, Eq("bb"));
}

/**
 * test for getting an empty move
**/
TEST_F(tFuncTest, get_null) {
    tFunc t(3);

    int nState;
    std::string push;

    t.getTrans(0, 'a', 't', nState, push);

    EXPECT_THAT(nState, Eq(-1));
    EXPECT_THAT(push, Eq(""));
}

/**
 * test setting a move that's already been set
**/
TEST_F(tFuncTest, set_reset) {
    tFunc t(3);

    // first set
    t.setTrans(0, 'a', 't', 1, "aa");

    int nState;
    std::string push;

    t.getTrans(0, 'a', 't', nState, push);

    EXPECT_THAT(nState, Eq(1));
    EXPECT_THAT(push, Eq("aa"));

    // reset
    t.setTrans(0, 'a', 't', 0, "bb");

    t.getTrans(0, 'a', 't', nState, push);

    EXPECT_THAT(nState, Eq(0));
    EXPECT_THAT(push, Eq("bb"));
}
