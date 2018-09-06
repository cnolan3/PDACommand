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

    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(pdaStackTest, is_empty) {
    PDAStack s;

    EXPECT_THAT(s.is_empty(), Eq(true));
}

TEST_F(pdaStackTest, is_not_empty) {
    PDAStack s;
    s.push('A');

    EXPECT_THAT(s.is_empty(), Eq(false));
}

TEST_F(pdaStackTest, pop_empty) {
    PDAStack s;

    EXPECT_THAT(s.pop(), Eq(0));
}

TEST_F(pdaStackTest, push_pop_empty) {
    PDAStack s;
    s.push('A');
    s.pop();

    EXPECT_THAT(s.pop(), Eq(0));
}

TEST_F(pdaStackTest, push_pop) {
    PDAStack s;
    s.push('A');

    EXPECT_THAT(s.pop(), Eq('A'));
}

TEST_F(pdaStackTest, multi_push) {
    PDAStack s;
    s.push('A');
    s.push('B');
    s.push('C');

    EXPECT_THAT(s.pop(), Eq('C'));

    s.push('D');

    EXPECT_THAT(s.pop(), Eq('D'));
}

TEST_F(pdaStackTest, multi_push_pop) {
    PDAStack s;
    s.push('A');
    s.push('B');
    s.push('C');

    s.pop();

    EXPECT_THAT(s.pop(), Eq('B'));
    EXPECT_THAT(s.pop(), Eq('A'));
}
