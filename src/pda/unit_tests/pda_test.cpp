#include "../pda.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

using ::testing::Eq;
using ::testing::Test;

class pdaTest : public Test
{
protected:
    pdaTest() {}
    ~pdaTest() {}

    PDA* p;
    vector<pair<string, int> > out;

    virtual void SetUp() {
        rule r;
        vector<rule> rules;

        r.state = 0;
        r.input = 'a';
        r.stackSym = EMPTY_SYM;
        r.nState = 1;
        r.pushSym = "a";
        r.pushSym += INIT_SYM;

        rules.push_back(r);

        r.state = 1;
        r.input = 'a';
        r.stackSym = EMPTY_SYM;
        r.nState = 1;
        r.pushSym = "a";

        rules.push_back(r);

        r.state = 1;
        r.input = EMPTY_SYM;
        r.stackSym = EMPTY_SYM;
        r.nState = 2;
        r.pushSym = EMPTY_SYM;

        rules.push_back(r);

        r.state = 2;
        r.input = 'b';
        r.stackSym = 'a';
        r.nState = 2;
        r.pushSym = EMPTY_SYM;

        rules.push_back(r);

        r.state = 2;
        r.input = EMPTY_SYM;
        r.stackSym = INIT_SYM;
        r.nState = 3;
        r.pushSym = EMPTY_SYM;

        rules.push_back(r);

        p = new PDA(4, rules);
    }
    virtual void TearDown() {}
};

/**
 * test a single match with a simple language
**/
TEST_F(pdaTest, language_1_single_match) {
    out = p->run("aabb");

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0].first, "aabb");
    EXPECT_EQ(out[0].second, 3);
}

/**
 * test multiple matched with a simple language
**/
TEST_F(pdaTest, language_1_multi_match) {
    out = p->run("aabbab");

    EXPECT_EQ(out.size(), 2);

    EXPECT_EQ(out[0].first, "aabb");
    EXPECT_EQ(out[0].second, 3);

    EXPECT_EQ(out[1].first, "ab");
    EXPECT_EQ(out[1].second, 3);
}

/**
 * test a failed match with a simple language
**/
TEST_F(pdaTest, language_1_fail) {
    out = p->run("aab");

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0].second, -1);
}
