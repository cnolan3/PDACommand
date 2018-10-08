/**
 * @file    fa.cpp
 *
 * @author  Connor Nolan
**/

#include <climits>
#include "fa.h"

/**
 * FA constructor
 *
 * @param    table transition table to use in FA
 * @param    alpha output alphabet
**/
FA::FA(const FAtTable& table, FAAlpha& alpha)
    : m_tTable(table)
{
    m_numStates = m_tTable.numStates();

    vector<alphaToken> at = alpha.getList();

    int max = 0;

    for(int i = 0; i < at.size(); i++) {
        if(at[i].state > max)
            max = at[i].state;
    }

    max++;
    m_tokenTable = new alphaChar[max];

    for(int i = 0; i < max; i++) {
        m_tokenTable[i].id = CHAR_MAX;
        m_tokenTable[i].action = NULL;
    }

    for(int i = 0; i < at.size(); i++) {
        m_tokenTable[at[i].state].id = at[i].id;
        m_tokenTable[at[i].state].action = at[i].action;
    }
}

/**
 * run FA on a stream of characters
 *
 * @param    input input stream
 *
 * @return   list of matched states and strings in order
**/
std::list<token> FA::run(std::istream& input) {
    std::list<token> out;
    token tmp;

    do {
        tmp = step(input, 0, "");
        out.push_back(tmp);
    } while(tmp.id >= 0);

    return out;
}

/**
 * recursively step through FA. Returned state id is
 * -1 if no state is matched, and -2 if end of file is
 *  reached.
 *
 * @param    input input stream
 * @param    state state to go to
 * @param    s string being matched
 *
 * @return   token that is returned from match
**/
token FA::step(std::istream& input, int state, std::string s) {
    token ret;

    ret.id = CHAR_MAX;
    ret.val = NULL;

    std::vector<int> trans;
    char tSym;

    // try with empty symbol
    trans = m_tTable.getTrans(state, EMPTY_SYM);

    for(int i = 0; i < trans.size(); i++) {
        ret = step(input, trans[i], s);

        // if branch was successful, return
        if(ret.id >= 0)
            return ret;
    }

    // try with transition symbol
    // if input stream is empty, return end of stream state
    if(!input.get(tSym)) {
        //ret.id = -2;
        tSym = NULL_SYM;
    }

    // in case of a fail state, report
    // the unrecognized symbol
    //ret.first = s + tSym;

    trans = m_tTable.getTrans(state, tSym);

    for(int i = 0; i < trans.size(); i++) {
        ret = step(input, trans[i], s + tSym);

        // if branch was successful, return
        if(ret.id < CHAR_MAX)
            return ret;
    }

    input.putback(tSym);

    if(m_tokenTable[state].id >= 0) {
        ret.id = m_tokenTable[state].id;

        if(m_tokenTable[state].action)
            ret.val = m_tokenTable[state].action(s);
    }

    // return fail state
    return ret;
}
