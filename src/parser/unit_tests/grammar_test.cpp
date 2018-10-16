#include "../grammar.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;
using ::testing::IsNull;
using ::testing::NotNull;

void* func(void** varBuf) {};

class grammarTest : public Test
{
protected:
    grammarTest() {}
    ~grammarTest() {}

    grammar g;

    virtual void SetUp() {
        vector<unsigned int> v;
        v.push_back('a');
        v.push_back('a');
        g.addRule('A', v, NULL);

        v.clear();
        v.push_back('g');
        v.push_back('A');
        g.addRule('B', v, func);
    }

    virtual void TearDown() {}
};

TEST_F(grammarTest, get_single) {
    rule r = g.getRule(0);

    EXPECT_EQ(r.lhs, 'A');
    EXPECT_EQ(r.rhs[0], 'a');
    EXPECT_EQ(r.rhs[1], 'a');
    EXPECT_THAT(r.action, IsNull());
}

TEST_F(grammarTest, get_all) {
    vector<rule> rules = g.getRules();

    EXPECT_EQ(rules.size(), 2);

    EXPECT_EQ(rules[0].lhs, 'A');
    EXPECT_EQ(rules[0].rhs[0], 'a');
    EXPECT_EQ(rules[0].rhs[1], 'a');
    EXPECT_THAT(rules[0].action, IsNull());

    EXPECT_EQ(rules[1].lhs, 'B');
    EXPECT_EQ(rules[1].rhs[0], 'g');
    EXPECT_EQ(rules[1].rhs[1], 'A');
    EXPECT_THAT(rules[1].action, NotNull());
}
