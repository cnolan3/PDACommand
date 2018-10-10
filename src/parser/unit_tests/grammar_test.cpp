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
        g.addRule('A', "aa", NULL);
        g.addRule('B', "gA", func);
    }

    virtual void TearDown() {}
};

TEST_F(grammarTest, get_single) {
    rule r = g.getRule(0);

    EXPECT_EQ(r.rhs, 'A');
    EXPECT_EQ(r.lhs, "aa");
    EXPECT_THAT(r.action, IsNull());
}

TEST_F(grammarTest, get_all) {
    vector<rule> rules = g.getRules();

    EXPECT_EQ(rules.size(), 2);

    EXPECT_EQ(rules[0].rhs, 'A');
    EXPECT_EQ(rules[0].lhs, "aa");
    EXPECT_THAT(rules[0].action, IsNull());

    EXPECT_EQ(rules[1].rhs, 'B');
    EXPECT_EQ(rules[1].lhs, "gA");
    EXPECT_THAT(rules[1].action, NotNull());
}
