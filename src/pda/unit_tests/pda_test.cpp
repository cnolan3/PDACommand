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
