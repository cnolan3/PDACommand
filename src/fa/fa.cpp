/**
 * @file    fa.cpp
 *
 * @author  Connor Nolan
**/

#include "fa.h"

/**
 * FA constructor
 *
 * @param    table transition table to use in FA
**/
FA::FA(const FAtTable& table, const std::vector<int>& endStates)
    : m_tTable(table)
{
    m_numStates = m_tTable.numStates();

    m_endStates = new int[m_numStates];

    for(int i = 0; i < m_numStates; i++) {
        m_endStates[i] = 0;
    }

    for(int i = 0; i < endStates.size(); i++) {
        m_endStates[endStates[i]] = 1;
    }
}

/**
 * run FA on a stream of characters
 *
 * @param    input input stream
 *
 * @return   list of matched states and strings in order
**/
std::list<std::pair<std::string, int> > FA::run(std::istream& input) {
    std::list<std::pair<std::string, int> > out;
    std::pair<std::string, int> tmp;

    do {
        tmp = step(input, 0, "");
        out.push_back(tmp);
    } while(tmp.second >= 0);

    return out;
}

/**
 * recursively step through FA. Returned state id is
 * -1 if no state is matched, and -2 if end of file is
 *  reached.
 *
 * @param    input input stream
 * @param    state state to go to
 *
 * @return   pair of matched state id and matched string
**/
std::pair<std::string, int> FA::step(std::istream& input, int state, std::string s) {

    std::pair<std::string, int> ret;

    ret.first = s;
    ret.second = -1;

    std::vector<int> trans;
    char tSym;

    // try with empty symbol
    trans = m_tTable.getTrans(state, EMPTY_SYM);

    for(int i = 0; i < trans.size(); i++) {
        ret = step(input, trans[i], s);

        // if branch was successful, return
        if(ret.second >= 0)
            return ret;
    }

    // try with transition symbol
    // if input stream is empty, return end of stream state
    if(!input.get(tSym)) {
        ret.second = -2;
        tSym = NULL_SYM;
    }

    // in case of a fail state, report
    // the unrecognized symbol
    ret.first = s + tSym;

    trans = m_tTable.getTrans(state, tSym);

    for(int i = 0; i < trans.size(); i++) {
        ret = step(input, trans[i], s + tSym);

        // if branch was successful, return
        if(ret.second >= 0)
            return ret;
    }

    input.putback(tSym);

    if(m_endStates[state]) {
        ret.first = s;
        ret.second = state;
    }

    // return fail state
    return ret;
}
