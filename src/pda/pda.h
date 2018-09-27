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
#include <list>
#include <string>
#include <utility>
#include <istream>
#include "pda_stack.h"
#include "pda_trans_table.h"
#include "../constants.h"

using std::string;
using std::vector;
using std::pair;
using std::istream;
using std::list;

class PDA
{
public:
    PDA(const PDAtTable& table, std::vector<int> endStates);

    list<pair<string, int> > run(istream& input);
private:

    pair<string, int> step(istream& input, int state, string s);

    int m_numStates;
    int* m_endStates;
    string m_input;
    PDAStack m_stack;
    PDAtTable m_tTable;
};

#endif
