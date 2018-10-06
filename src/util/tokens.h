#ifndef __TOKENS_H__
#define __TOKENS_H__

#include <string>

using std::string;

struct token
{
    int id;
    void* val;
};

struct alphaToken
{
    int id;
    int state;
    void* (*action)(string text);
};

#endif
