#include "../fa.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

class faTest : public Test
{
protected:
    faTest() {}
    ~faTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};
