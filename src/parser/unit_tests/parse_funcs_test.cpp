#include "../fa.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>
#include <list>
#include <iostream>

using std::stringstream;
using std::list;
using std::cout;
using std::endl;
using ::testing::Eq;
using ::testing::Test;
using ::testing::IsNull;

void* funcOne(string text) {
    return new int(1);
}

void* funcTwo(string text) {
    return new int(stoi(text));
}

class faTest : public Test
{
protected:
    faTest() : table(16) {}
    ~faTest() {}

    FAtTable table;
    FAAlpha alpha;
    FA* fa;
    list<token> out;

    virtual void SetUp() {
        table.addTrans(0, 1, EMPTY_SYM);
        table.addTrans(1, 2, 'a');
        table.addTrans(2, 1, EMPTY_SYM);
        table.addTrans(2, 3, 'b');
        table.addTrans(2, 4, 'c');
        table.addTrans(3, 5, EMPTY_SYM);
        table.addTrans(4, 5, EMPTY_SYM);
        table.addTrans(0, 6, EMPTY_SYM);
        table.addTrans(6, 7, 'c');
        table.addTrans(7, 6, EMPTY_SYM);
        table.addTrans(7, 8, 'd');
        table.addTrans(8, 9, EMPTY_SYM);
        table.addTrans(0, 10, 32);
        table.addTrans(0, 11, EMPTY_SYM);
        table.addTrans(11, 12, '0');
        table.addTrans(11, 13, '1');
        table.addTrans(12, 14, EMPTY_SYM);
        table.addTrans(13, 14, EMPTY_SYM);
        table.addTrans(0, 15, 'g');

        alpha.addAlpha(0, 5, NULL);
        alpha.addAlpha(1, 9, NULL);
        alpha.addAlpha(2, 10, NULL, true);
        alpha.addAlpha(3, 14, funcTwo);
        alpha.addAlpha(4, 15, funcOne);

        fa = new FA(table, alpha);
    }

    virtual void TearDown() {}
};

TEST_F(faTest, single_match_one) {
    stringstream ss;

    ss << "ab";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 2);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, single_match_two) {
    stringstream ss;

    ss << "aaac";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 2);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, single_match_three) {
    stringstream ss;

    ss << "cccd";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 2);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 1);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, single_match_fail) {
    stringstream ss;

    ss << "aabc";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 2);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, multi_match_one) {
    stringstream ss;

    ss << "abac";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 3);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, multi_match_two) {
    stringstream ss;

    ss << "abccdaac";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 4);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 1);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, multi_match_ignore) {
    stringstream ss;

    ss << "ab ccd";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 3);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 1);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, multi_match_value) {
    stringstream ss;

    ss << "aabg";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 3);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 4);
    EXPECT_EQ(*((int*)t.val), 1);
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}

TEST_F(faTest, multi_match_text_value) {
    stringstream ss;

    ss << "ab01";

    out = fa->run(ss);

    EXPECT_EQ(out.size(), 4);

    token t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 0);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 3);
    EXPECT_EQ(*((int*)t.val), 0);
    EXPECT_EQ(t.ignore, false);

    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, 3);
    EXPECT_EQ(*((int*)t.val), 1);
    EXPECT_EQ(t.ignore, false);
 
    t = out.front();
    out.pop_front();

    EXPECT_EQ(t.id, END_SYM);
    EXPECT_THAT(t.val, IsNull());
    EXPECT_EQ(t.ignore, false);
}
