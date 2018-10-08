#ifndef __TOKENS_H__
#define __TOKENS_H__

#include <string>

using std::string;

struct token
{
    char id;
    void* val;
};

struct alphaToken
{
    char id;
    int state;
    void* (*action)(string text);
};

#endif
