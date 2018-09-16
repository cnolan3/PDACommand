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
 * @param    endStates vector of accptance states
**/
PDA::PDA(int numStates, vector<rule> rules, vector<int> endStates) 
    : m_numStates(numStates), m_state(0)
{
    // create acceptance states list, 1 if acceptance, 0 if not
    m_endStates = new char[m_numStates];

    for(int i = 0; i < m_numStates; i++) {
        m_endStates[i] = 0;
    }

    for(int i = 0; i < endStates.size(); i++) {
        m_endStates[endStates[i]] = 1;
    }

    // create transition functions
    m_tFunc = new tFunc(m_numStates);

    for(int i = 0; i < rules.size(); i++) {
        m_tFunc->setTrans(rules[i].state, rules[i].input, rules[i].stackSym, rules[i].nState, rules[i].pushSym);
    }
}

/**
 * Recursively run the PDA on an input string, returns a list
 * of matchedstrings and the acceptence states that matched them,
 * in the order that they appear in the input string.
 *
 * @param    input input string
 *
 * @return   vector of pairs of matched strings and the
 *           acceptence states that they matched
**/
vector<pair<string, int> > PDA::run(string input) {
    m_input = input;
    vector<pair<string, int> > ret;
    pair<string, int> tmp;
    int curChar = 0;

    do {
      tmp = run_rec(curChar, "", 0);
      ret.push_back(tmp);
      m_stack.clear();
    } while(curChar < m_input.length() && tmp.second >= 0);

    return ret;
}

pair<string, int> PDA::run_rec(int& curChar, string curString, int state) {

    pair<string, int> ret;
    ret.second = -2;
    char top;

    // return success if acceptence state is reached
    if(m_endStates[state]) {
        pair<string, int> ret;
        ret.first = curString;
        ret.second = state;
        return ret;
    }

    // return fail state if past end of input string
    if(curChar > m_input.length()) {
        pair<string, int> ret;
        ret.first = curString;
        ret.second = -1;
        return ret;
    }

    vector<move> mv;

    // try empty input character and empty stack character
    mv = m_tFunc->getTrans(state, EMPTY_SYM, EMPTY_SYM);

    for(int i = 0; i < mv.size(); i++) {
        for(int j = mv[i].push.length() - 1; j >= 0; j--) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.push(mv[i].push[j]);
        }
        
        ret = run_rec(curChar, curString, mv[i].nState);

        // return immediately if branch was successful
        if(ret.second >= 0)
            return ret;

        // if this branch was not successful, undo changes
        // made to the stack
        for(int j = 0; j < mv[i].push.length(); j++) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.pop();
        }
    }

    // try empty input character
    top = m_stack.pop();
    mv = m_tFunc->getTrans(state, EMPTY_SYM, top);

    for(int i = 0; i < mv.size(); i++) {
        for(int j = mv[i].push.length() - 1; j >= 0; j--) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.push(mv[i].push[j]);
        }
        
        ret = run_rec(curChar, curString, mv[i].nState);

        // return immediately if branch was successful
        if(ret.second >= 0)
            return ret;

        // if this branch was not successful, undo changes
        // made to the stack
        for(int j = 0; j < mv[i].push.length(); j++) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.pop();
        }
    }

    m_stack.push(top);

    // try empty stack character
    mv = m_tFunc->getTrans(state, m_input[curChar], EMPTY_SYM);

    for(int i = 0; i < mv.size(); i++) {
        for(int j = mv[i].push.length() - 1; j >= 0; j--) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.push(mv[i].push[j]);
        }
        
        curChar++;
        ret = run_rec(curChar, curString + m_input[curChar - 1], mv[i].nState);

        // return immediately if branch was successful
        if(ret.second >= 0)
            return ret;

        // if this branch was not successful, undo changes
        // made to the stack
        for(int j = 0; j < mv[i].push.length(); j++) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.pop();
        }

        curChar--;
    }

    // try with input character and stack character
    top = m_stack.pop();
    mv = m_tFunc->getTrans(state, m_input[curChar], top);

    for(int i = 0; i < mv.size(); i++) {
        for(int j = mv[i].push.length() - 1; j >= 0; j--) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.push(mv[i].push[j]);
        }
        
        curChar++;
        ret = run_rec(curChar, curString + m_input[curChar - 1], mv[i].nState);

        // return immediately if branch was successful
        if(ret.second >= 0)
            return ret;

        // if this branch was not successful, undo changes
        // made to the stack
        for(int j = 0; j < mv[i].push.length(); j++) {
            if(mv[i].push[j] != EMPTY_SYM)
                m_stack.pop();
        }

        curChar--;
    }

    m_stack.push(top);

    // return fail state if nothing was successful
    if(ret.second == -2) {
        ret.first = curString;
        ret.second = -1;
    }

    return ret;

}
