/**
 * @file    pda.cpp
 *
 * @brief   definition of PDA object.
 *
 * @author  Connor Nolan
**/

#include "pda.h"

#include <iostream>

/**
 * PDA constructor
 *
 * @param    numStates number of states in PDA
 * @param    rules vector of transition function rules
 * @param    endStates vector of accptance states
**/
PDA::PDA(int numStates, std::vector<rule> rules, std::vector<int> endStates) 
    : m_numStates(numStates), m_state(0), m_line("")
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

    // push initial symmbol (1) onto stack
    m_stack.push(INIT_SYM);
}

/**
 * step through next character in PDA. returns the matched string
 * and the id of the acceptance state if the string is matched, 
 * returns -1 as the state id if not matched.
 *
 * @param    next next character
 *
 * @return   pair containing the matched string and
 *           the acceptance state number.
**/
std::pair<std::string, int> PDA::step(char next) {
    int nState;
    std::string push;

    m_line += next;

    //m_tFunc->getTrans(m_state, next, m_stack.pop(), nState, push);

    m_state = nState;

    for(int i = push.length() - 1; i >= 0; i--) {
        if(push[i] != EMPTY_SYM)
            m_stack.push(push[i]);
    }

    std::pair<std::string, int> p(m_line, -1);

    if(m_endStates[m_state])
        p.second = m_state;

    return p;
}

/**
 * reset the PDA
**/
void PDA::reset() {
    m_stack.clear();
    m_stack.push(INIT_SYM);

    m_state = 0;

    m_line = "";
}

/**
 * reset and clear transition function rules
**/
void PDA::clear() {
    this->reset();

    m_tFunc->clear();
}
