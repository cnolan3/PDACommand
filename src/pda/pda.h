/**
 * @file    pda.h
 *
 * @brief   Pushdown automata object declaration. Creates states from 0 - numStates
 *          rather than taking a defined list of states, state 0 is always the
 *          initial state. All ascii characters are valid symbols for input and the
 *          stack. Initial stack symbol is not pushed onto the stack by default, and
 *          the first state, state 0, cannot be an acceptence state. Acceptence 
 *          states are defined by finding the initial symbol at the top of the stack, 
 *          therefore, acceptence states do not need to be explicitely defined.
 *
 * @author  Connor Nolan
**/

#ifndef __PDA_H__
#define __PDA_H__

#include <vector>
#include <string>
#include <utility>
#include "pda_stack.h"
#include "pda_trans_table.h"
#include "../constants.h"

using std::string;
using std::vector;
using std::pair;

struct rule
{
    int state;
    char input;
    char stackSym;
    int nState;
    string pushSym;
};

class PDA
{
public:
    PDA(int numStates, vector<rule> rules);

    vector<pair<string, int> > run(string input);
private:

    pair<string, int> run_rec(int& curChar, string curString, int state);

    int m_numStates;
    string m_input;
    PDAStack m_stack;
    PDAtTable* m_tTable;
};

#endif
