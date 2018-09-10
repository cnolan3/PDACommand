/**
 * @file    trans_func.cpp
 *
 * @brief   Transition function object definitions.
 *
 * @author  Connor Nolan
**/

#include "trans_func.h"
#include <iostream>

using std::cout;
using std::endl;

/**
 * tFunc constructor, create 3d transition table
 *
 * @param    numStates number of states in PDA
**/
tFunc::tFunc(int numStates) 
    : m_numStates(numStates)
{
    m_trans = new move[numStates * 255 * 255];

    move* tmp;
    for(int i = 0; i < (numStates * 255 * 255); i++) {
        tmp = &m_trans[i];

        tmp->nState = -1;
        tmp->push = "";
    }
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
void tFunc::setTrans(int state, char input, char stack, int nState, std::string push) {
    move* tmp = &m_trans[state + ((int)input * m_numStates) + ((int)stack * m_numStates * 255)];

    tmp->nState = nState;
    tmp->push = push;
}

/**
 * get the transition value for a given current state, input and top of stack
 *
 * @param    state current state
 * @param    input input value
 * @param    stack value at top of stack
 * @param    nState reference to next state value
 * @param    push reference to value to push onto stack
**/
void tFunc::getTrans(int state, char input, char stack, int& nState, std::string& push) {
    move* tmp = &m_trans[state + ((int)input * m_numStates) + ((int)stack * m_numStates * 255)];

    nState = tmp->nState;
    push = tmp->push;
}
