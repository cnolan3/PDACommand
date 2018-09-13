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

    virtual void SetUp() {}
    virtual void TearDown() {}
};

/**
 * test with language that accepts
 * a^nb^n where n > 0.
 * (ie. ab, aabb, aaaabbbb, etc.)
**/
TEST_F(pdaTest, language_1) {

    int states = 4;
    rule r;
    std::vector<int> endStates;
    std::vector<rule> rules;
    std::pair<std::string, int> out;

    endStates.push_back(3);

    r.state = 0;
    r.input = 'a';
    r.stackSym = INIT_SYM;
    r.nState = 1;
    r.pushSym = "a";
    r.pushSym += INIT_SYM;

    rules.push_back(r);

    r.state = 1;
    r.input = 'a';
    r.stackSym = 'a';
    r.nState = 1;
    r.pushSym = "aa";

    rules.push_back(r);

    r.state = 1;
    r.input = 'b';
    r.stackSym = 'a';
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
    r.pushSym = INIT_SYM;

    rules.push_back(r);

    PDA p(states, rules, endStates);

    p.step('a');

    p.step('a');

    p.step('b');

    p.step('b');

    out = p.step(EMPTY_SYM);

    EXPECT_THAT(out.first, Eq("aabb"));
    EXPECT_THAT(out.second, Eq(3));
}
