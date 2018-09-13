/**
 * @file    pda.h
 *
 * @brief   Pushdown automata object declaration. Creates states from 0 - numStates
 *          rather than taking a defined list of states, state 0 is always the
 *          initial state. All ascii characters are valid symbols for input and the
 *          stack.
 *
 * @author  Connor Nolan
**/

#ifndef __PDA_H__
#define __PDA_H__

// define special symbols
#define INIT_SYM 1
#define EMPTY_SYM 2

#include <vector>
#include <string>
#include <utility>
#include "pda_stack.h"
#include "trans_func.h"

struct rule
{
    int state;
    char input;
    char stackSym;
    int nState;
    std::string pushSym;
};

class PDA
{
public:
    PDA(int numStates, std::vector<rule> rules, std::vector<int> endStates);

    std::pair<std::string, int> step(char next);
    void reset();
    void clear();
private:
    std::string m_line;
    int m_numStates;
    int m_state;
    char* m_endStates;
    PDAStack m_stack;
    tFunc* m_tFunc;
};

#endif
