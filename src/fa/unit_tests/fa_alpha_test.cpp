#include "../fa_alpha.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::IsNull;
using ::testing::NotNull;
using ::testing::Test;

void* func(string text) {};

class faAlphaTest : public Test
{
protected:
    faAlphaTest() {}
    ~faAlphaTest() {}

    FAAlpha alpha;
    vector<alphaToken> get;

    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(faAlphaTest, add_single) {
    alpha.addAlpha('a', 0, NULL);
    
    get = alpha.getList();

    EXPECT_EQ(get.size(), 1);
    EXPECT_EQ(get[0].id, 'a');
    EXPECT_EQ(get[0].state, 0);
    EXPECT_THAT(get[0].action, IsNull());
    EXPECT_EQ(get[0].ignore, false);
}

TEST_F(faAlphaTest, add_two) {
    alpha.addAlpha('a', 0, NULL);
    alpha.addAlpha('b', 1, NULL);

    get = alpha.getList();

    EXPECT_EQ(get.size(), 2);

    EXPECT_EQ(get[0].id, 'a');
    EXPECT_EQ(get[0].state, 0);
    EXPECT_THAT(get[0].action, IsNull());
    EXPECT_EQ(get[0].ignore, false);

    EXPECT_EQ(get[1].id, 'b');
    EXPECT_EQ(get[1].state, 1);
    EXPECT_THAT(get[1].action, IsNull());
    EXPECT_EQ(get[1].ignore, false);
}

TEST_F(faAlphaTest, add_action) {
    alpha.addAlpha('a', 0, func);

    get = alpha.getList();

    EXPECT_EQ(get.size(), 1);
    EXPECT_EQ(get[0].id, 'a');
    EXPECT_EQ(get[0].state, 0);
    EXPECT_THAT(get[0].action, NotNull());
    EXPECT_EQ(get[0].ignore, false);
}

TEST_F(faAlphaTest, add_ignore) {
    alpha.addAlpha('a', 0, NULL, true);

    get = alpha.getList();

    EXPECT_EQ(get.size(), 1);
    EXPECT_EQ(get[0].id, 'a');
    EXPECT_EQ(get[0].state, 0);
    EXPECT_THAT(get[0].action, IsNull());
    EXPECT_EQ(get[0].ignore, true);
}
