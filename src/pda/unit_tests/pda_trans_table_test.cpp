#include "../pda_trans_table.h"

#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using std::vector;
using ::testing::Eq;
using ::testing::Test;

class PDAtTableTest : public Test
{
protected:
    PDAtTableTest() {}
    ~PDAtTableTest() {}

    PDAtTable* t;
    vector<move> v;

    virtual void SetUp() {
        std::vector<int> in;
        in.push_back('a');
        in.push_back('c');

        t = new PDAtTable(3, in); 

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
TEST_F(PDAtTableTest, set_get) {

    v = t->getTrans(2, 'c', 'd');

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0].nState, 0);
    EXPECT_EQ(v[0].push, "G");
}

/**
 * test adding multiple moves to one transition
**/
TEST_F(PDAtTableTest, set_mult_one_trans) {

    v = t->getTrans(0, 'a', 't');

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0].nState, 1);
    EXPECT_EQ(v[0].push, "aa");

    EXPECT_EQ(v[1].nState, 2);
    EXPECT_EQ(v[1].push, "bb");
}

/**
 * test the clear function
**/
TEST_F(PDAtTableTest, set_clear) {

    t->clear();

    v = t->getTrans(0, 'a', 't');

    EXPECT_EQ(v.size(), 0);
}

/**
 * test the copy constructor
**/
TEST_F(PDAtTableTest, copy_constructor) {
 
    PDAtTable t2(*t);

    v = t2.getTrans(2, 'c', 'd');

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0].nState, 0);
    EXPECT_EQ(v[0].push, "G");
   
}
