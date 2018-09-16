#include "../trans_func.h"

#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using std::vector;
using ::testing::Eq;
using ::testing::Test;

class tFuncTest : public Test
{
protected:
    tFuncTest() {}
    ~tFuncTest() {}

    tFunc* t;
    vector<move> v;

    virtual void SetUp() {
        t = new tFunc(3); 

        t->setTrans(0, 'a', 't', 1, "aa");
        t->setTrans(0, 'a', 't', 2, "bb");
        t->setTrans(2, 'c', 'd', 0, "G");
        t->setTrans(2, 'c', 'e', 1, "F");
    }

    virtual void TearDown() {}
};

/**
 * test that moves are set correctly
**/
TEST_F(tFuncTest, set_get) {

    v = t->getTrans(2, 'c', 'd');

    EXPECT_THAT(v.size(), Eq(1));
    EXPECT_THAT(v[0].nState, Eq(0));
    EXPECT_THAT(v[0].push, Eq("G"));
}

/**
 * test adding multiple moves to one transition
**/
TEST_F(tFuncTest, set_mult_one_trans) {

    v = t->getTrans(0, 'a', 't');

    EXPECT_THAT(v.size(), Eq(2));
    EXPECT_THAT(v[0].nState, Eq(1));
    EXPECT_THAT(v[0].push, Eq("aa"));

    EXPECT_THAT(v[1].nState, Eq(2));
    EXPECT_THAT(v[1].push, Eq("bb"));
}

/**
 * test the clear function
**/
TEST_F(tFuncTest, set_clear) {

    t->clear();

    v = t->getTrans(0, 'a', 't');

    EXPECT_THAT(v.size(), Eq(0));
}
