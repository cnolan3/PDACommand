#ifndef __TOKENS_H__
#define __TOKENS_H__

#include <string>

using std::string;

struct token
{
    unsigned char id;
    void* val;
    bool ignore;
};

struct alphaToken
{
    unsigned char id;
    int state;
    void* (*action)(string text);
    bool ignore;
};

#endif
