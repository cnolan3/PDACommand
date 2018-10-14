#include "../parse_funcs.h"

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

    virtual void SetUp() {}

    virtual void TearDown() {}
};
