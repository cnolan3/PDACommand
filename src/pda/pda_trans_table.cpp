/**
 * @file    pda_trans_table.cpp
 *
 * @brief   Transition function object definitions.
 *
 * @author  Connor Nolan
**/

#include "pda_trans_table.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

/**
 * PDAtTable constructor, create 3d transition table
 *
 * @param    numStates number of states in PDA
**/
PDAtTable::PDAtTable(int numStates) 
    : m_numStates(numStates)
{
    m_trans = new vector<move>[numStates * 255 * 255];
}

/**
 * set a transition value
 *
 * @param    state current state value
 * @param    input input value to check for
 * @param    stack stack value to cheack for
 * @param    nState next state value
 * @param    push characters to be pushed onto the stack
**/
void PDAtTable::setTrans(int state, char input, char stack, int nState, std::string push) {
    move tmp;

    tmp.nState = nState;
    tmp.push = push;

    m_trans[state + ((int)input * m_numStates) + ((int)stack * m_numStates * 255)].push_back(tmp);
}

/**
 * get the transition values for a given current state, input and top of stack
 *
 * @param    state current state
 * @param    input input value
 * @param    stack value at top of stack
 *
 * @return   vector of moves that correspond to the current state, input and
 *           top of stack
**/
const vector<move>& PDAtTable::getTrans(int state, char input, char stack) {
    return m_trans[state + ((int)input * m_numStates) + ((int)stack * m_numStates * 255)];
}

/**
 * clear all transitions
**/
void PDAtTable::clear() {
    delete[] m_trans;

    m_trans = new vector<move>[m_numStates * 255 * 255];
}