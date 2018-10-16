#ifndef __TOKENS_H__
#define __TOKENS_H__

#include <string>

using std::string;

struct token
{
    unsigned int id;
    void* val;
    bool ignore;
};

struct alphaToken
{
    unsigned int id;
    int state;
    void* (*action)(string text);
    bool ignore;
};

enum tokenType
{
    terminal,
    nonterminal
};

#endif
