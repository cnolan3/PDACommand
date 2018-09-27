/**
 * @file    pda_trans_table.cpp
 *
 * @brief   Transition function object definitions.
 *
 * @author  Connor Nolan
**/

#include "pda_trans_table.h"
#include <iostream>
#include <cstring>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

/**
 * PDAtTable constructor, create 3d transition table
 *
 * @param    numStates number of states in PDA
**/
PDAtTable::PDAtTable(int numStates, std::vector<int> inputSet) 
    : m_numStates(numStates)
{
    m_numInSyms = inputSet.size();

    unsigned int mapSize;
    m_mapMax = 0;
    m_mapMin = UINT_MAX;
    for(int i = 0; i < inputSet.size(); i++) {
        if(inputSet[i] > m_mapMax)
            m_mapMax = inputSet[i];

        if(inputSet[i] < m_mapMin)
            m_mapMin = inputSet[i];
    }

    if(m_mapMax >= m_mapMin)
        mapSize = m_mapMax - m_mapMin;
    else
        mapSize = 0;

    m_inMap = new unsigned int[mapSize];

    for(int i = 0; i < mapSize; i++) {
        m_inMap[i] = UINT_MAX;
    }

    for(int i = 0; i < inputSet.size(); i++) {
        m_inMap[inputSet[i] - m_mapMin] = i;
    }

    m_trans = new vector<move>[numStates * m_numInSyms * 255];
}

/**
 * PDAtTable copy constructor
 *
 * @param    old_table table to copy from
**/
PDAtTable::PDAtTable(const PDAtTable& old_table) {
    this->m_numStates = old_table.m_numStates;
    this->m_numInSyms = old_table.m_numInSyms;
    this->m_mapMin = old_table.m_mapMin;
    this->m_mapMax = old_table.m_mapMax;

    int mapSize = old_table.m_mapMax - old_table.m_mapMin;
    this->m_inMap = new unsigned int[mapSize];
    memcpy(this->m_inMap, old_table.m_inMap, sizeof(unsigned int) * mapSize);

    int s = old_table.m_numStates * old_table.m_numInSyms * 255;
    this->m_trans = new std::vector<move>[s];
    memcpy(this->m_trans, old_table.m_trans, sizeof(std::vector<move>) * s);
}

/**
 * get number of states
 *
 * @return   number of states
**/
unsigned int PDAtTable::numStates() {
    return m_numStates;
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
void PDAtTable::setTrans(int state, int input, char stack, int nState, std::string push) {
    if(input == NULL_SYM)
        return;

    move tmp;

    tmp.nState = nState;
    tmp.push = push;

    if(input < m_mapMin || input > m_mapMax)
        return;

    int in = input - m_mapMin;

    if(m_inMap[in] == UINT_MAX)
        return;

    m_trans[state + (in * m_numStates) + ((int)stack * m_numStates * m_numInSyms)].push_back(tmp);
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
    if(input < m_mapMin || input > m_mapMax || input == NULL_SYM)
        return *(new vector<move>);

    int in = input - m_mapMin;

    return m_trans[state + (in * m_numStates) + ((int)stack * m_numStates * m_numInSyms)];
}

/**
 * clear all transitions
**/
void PDAtTable::clear() {
    delete[] m_trans;

    m_trans = new vector<move>[m_numStates * m_numInSyms * 255];
}
