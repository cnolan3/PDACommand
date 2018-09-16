#include "../pda_stack.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

class pdaStackTest : public Test
{
protected:
    pdaStackTest() {}
    ~pdaStackTest() {}

    PDAStack s;

    virtual void SetUp() {}
    virtual void TearDown() {}
};

/**
 * test the is_empty function
**/
TEST_F(pdaStackTest, is_empty) {
    EXPECT_EQ(s.is_empty(), true);
}

/**
 * test the is_empty function
**/
TEST_F(pdaStackTest, is_not_empty) {
    s.push('A');

    EXPECT_EQ(s.is_empty(), false);
}

/**
 * test popping an empty stack
**/
TEST_F(pdaStackTest, pop_empty) {
    EXPECT_EQ(s.pop(), 0);
}

/**
 * test pushing and then popping, then popping an
 * empty stack
**/
TEST_F(pdaStackTest, push_pop_empty) {
    s.push('A');
    s.push('B');
    s.pop();
    s.pop();

    EXPECT_EQ(s.pop(), 0);
}

/**
 * test pushing and the popping
**/
TEST_F(pdaStackTest, push_pop) {
    s.push('A');

    EXPECT_EQ(s.pop(), 'A');
}

/**
 * test pushing  multiple times
**/
TEST_F(pdaStackTest, multi_push) {
    s.push('A');
    s.push('B');
    s.push('C');

    EXPECT_EQ(s.pop(), 'C');

    s.push('D');

    EXPECT_EQ(s.pop(), 'D');
}

/**
 * test pushing  multiple times and the popping
**/
TEST_F(pdaStackTest, multi_push_pop) {
    s.push('A');
    s.push('B');
    s.push('C');

    s.pop();

    EXPECT_EQ(s.pop(), 'B');
    EXPECT_EQ(s.pop(), 'A');
}

/**
 * test clear function
**/
TEST_F(pdaStackTest, clear) {
    s.push('A');
    s.push('B');
    s.push('C');

    s.clear();

    EXPECT_EQ(s.is_empty(), true);
    EXPECT_EQ(s.pop(), 0);
}
