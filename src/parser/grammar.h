/**
 * @file    grammar.h
 *
 * @brief   object to hold grammar information.
 *
 * @author  Connor Nolan
**/

#ifndef __GRAMMAR_H__
#define __GRAMMAR_H__

#include <vector>
#include <string>

using std::vector;
using std::string;

struct rule
{
    unsigned int lhs;
    vector<unsigned int> rhs;
    void* (*action)(void** varBuf);
};

class grammar
{
public:
    grammar();

    void addRule(int lhs, vector<unsigned int> rhs, void* (*action)(void** varBuf));
    rule getRule(int id);
    vector<rule> getRules();
private:
    vector<rule> m_rules;
};

#endif
