/**
 * @file    pda.cpp
 *
 * @brief   definition of PDA object.
 *
 * @author  Connor Nolan
**/

#include "pda.h"
#include <iostream>

using std::cout;
using std::endl;

/**
 * PDA constructor
 *
 * @param    numStates number of states in PDA
 * @param    rules vector of transition function rules
**/
PDA::PDA(const PDAtTable& table, std::vector<int> endStates) 
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
 * Run the PDA on an input string, returns a list of matched
 * strings and the acceptence states that matched them, in the
 * order that they appear in the input string.
 *
 * @param    input input string
 *
 * @return   vector of pairs of matched strings and the
 *           acceptence states that they matched
**/
list<pair<string, int> > PDA::run(istream& input) {
    list<pair<string, int> > out;
    pair<string, int> tmp;

    do {
        tmp = step(input, 0, "");
        out.push_back(tmp);
    } while(tmp.second >= 0);

    return out;
}

/**
 * Recursively match strings in the input string.
 *
 * @param    curChar reference to index of current character in input string
 * @param    curString current string trying to be matched
 * @param    state id of current state
 *
 * @return   pair of matched string and matched state
**/
pair<string, int> PDA::step(istream& input, int state, string s) {
    pair<string, int> ret;

    ret.first = s;
    ret.second = -1;

    vector<move> trans;
    char tSym;
    char stackSym;

    stackSym = m_stack.pop();
    m_stack.push(stackSym);

    // try with empty input and empty stack symbol
    trans = m_tTable.getTrans(state, EMPTY_SYM, EMPTY_SYM);

    for(int i = 0; i < trans.size(); i++) {
        for(int j = trans[i].push.length() - 1; j >= 0; j--) {
            m_stack.push(trans[i].push[j]);
        }

        ret = step(input, trans[i].nState, s);

        if(ret.second >= 0) {
            if(trans[i].action)
                trans[i].action();

            return ret;
        }

        for(int j = 0; j < trans[i].push.length(); j++) {
            m_stack.pop();
        }
    }

    // try with empty input symbol
    stackSym = m_stack.pop();
    trans = m_tTable.getTrans(state, EMPTY_SYM, stackSym);

    for(int i = 0; i < trans.size(); i++) {
        for(int j = trans[i].push.length() - 1; j >= 0; j--) {
            m_stack.push(trans[i].push[j]);
        }

        ret = step(input, trans[i].nState, s);

        if(ret.second >= 0) {
            if(trans[i].action)
                trans[i].action();

            return ret;
        }

        for(int j = 0; j < trans[i].push.length(); j++) {
            m_stack.pop();
        }
    }
    m_stack.push(stackSym);

    // try with empty stack symbol
    if(!input.get(tSym)) {
        ret.second = -2;
        tSym = NULL_SYM;
    }

    ret.first = s + tSym;

    trans = m_tTable.getTrans(state, (int)tSym, EMPTY_SYM);

    for(int i = 0; i < trans.size(); i++) {
        for(int j = trans[i].push.length() - 1; j >= 0; j--) {
            m_stack.push(trans[i].push[j]);
        }

        ret = step(input, trans[i].nState, s + tSym);

        if(ret.second >= 0) {
            if(trans[i].action)
                trans[i].action();

            return ret;
        }

        for(int j = 0; j < trans[i].push.length(); j++) {
            m_stack.pop();
        }
    }

    // try without empty symbols
    stackSym = m_stack.pop();
    trans = m_tTable.getTrans(state, (int)tSym, stackSym);

    for(int i = 0; i < trans.size(); i++) {
        for(int j = trans[i].push.length() - 1; j >= 0; j--) {
            m_stack.push(trans[i].push[j]);
        }

        ret = step(input, trans[i].nState, s + tSym);

        if(ret.second >= 0) {
            if(trans[i].action)
                trans[i].action();

            return ret;
        }

        for(int j = 0; j < trans[i].push.length(); j++) {
            m_stack.pop();
        }
    }

    input.putback(tSym);
    m_stack.push(stackSym);

    if(m_endStates[state]) {
        ret.first = s;
        ret.second = state;
    }

    return ret;
}
