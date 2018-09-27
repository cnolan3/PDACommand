#include "../pda.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <utility>
#include <sstream>

using ::testing::Eq;
using ::testing::Test;

class pdaTest : public Test
{
protected:
    pdaTest() {}
    ~pdaTest() {}

    PDA* p;
    list<pair<string, int> > out;
    std::stringstream ss;

    virtual void SetUp() {

        std::vector<int> inSet;
        inSet.push_back('a');
        inSet.push_back('b');
        inSet.push_back(EMPTY_SYM);

        PDAtTable table(4, inSet);

        table.setTrans(0, 5, EMPTY_SYM, 1, "a" + INIT_SYM);
        table.setTrans(1, 5, EMPTY_SYM, 1, "a");
        table.setTrans(1, EMPTY_SYM, EMPTY_SYM, 2, "" + EMPTY_SYM);
        table.setTrans(2, 6, 'a', 2, "" + EMPTY_SYM);
        table.setTrans(2, EMPTY_SYM, INIT_SYM, 3, "" + EMPTY_SYM);

        std::vector<int> end;
        end.push_back(3);

        p = new PDA(table, end);
    }
    virtual void TearDown() {}
};

/**
 * test a single match with a simple language
**/
TEST_F(pdaTest, language_1_single_match) {
    ss << 5 << 5 << 6 << 6;
    out = p->run(ss);

    EXPECT_EQ(out.size(), 1);
    //EXPECT_EQ(out[0].first, "aabb");
    EXPECT_EQ(out[0].second, 3);
}

/**
 * test multiple matched with a simple language
**
TEST_F(pdaTest, language_1_multi_match) {
    out = p->run("aabbab");

    EXPECT_EQ(out.size(), 2);

    EXPECT_EQ(out[0].first, "aabb");
    EXPECT_EQ(out[0].second, 3);

    EXPECT_EQ(out[1].first, "ab");
    EXPECT_EQ(out[1].second, 3);
}

**
 * test a failed match with a simple language
**
TEST_F(pdaTest, language_1_fail) {
    out = p->run("aab");

    EXPECT_EQ(out.size(), 1);
    EXPECT_EQ(out[0].second, -1);
}
*/
