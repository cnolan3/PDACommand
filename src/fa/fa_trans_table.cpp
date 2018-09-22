/**
 * @file    fa_trans_table.cpp
 *
 * @brief   definitions of FAtTable object.
 *
 * @author  Connor Nolan
**/

#include "fa_trans_table.h"
#include "../constants.h"

/**
 * FAtTable constructor
 *
 * @param    numStates number of states in automata
**/
FAtTable::FAtTable(int numStates)
    : m_numStates(numStates)
{
    // Because all the vectors corresponding to the NULL_SYM
    // will always be empty, it could be seen as a waste of
    // memory to include vectors for all 256 possible char
    // values. However, including these allows for the NULL_SYM
    // to be defined as any ascii value.
    m_table = new std::vector<int>[m_numStates * 255];
}

/**
 * FAtTable copy constructor
 *
 * @param    old_table table to copy from
**/
FAtTable::FAtTable(const FAtTable& old_table) {
    this->m_numStates = old_table.m_numStates;

    this->m_table = old_table.m_table;
}

/**
 * get number of states in table
 *
 * @return   number of states
**/
int FAtTable::numStates() {
    return m_numStates;
}

/**
 * add a transition to the table, can define multiple outputs
 * for each transition.
 *
 * @param    from id of state to transition from
 * @param    to id of state to transition to
 * @param    sym symbol to transition on
**/
void FAtTable::addTrans(int from, int to, char sym) {
    // if given state ids are out of bounds, return
    if(from < 0 || from >= m_numStates || to < 0 || to >= m_numStates)
        return;

    // if the given symbol is the NULL_SYM, return
    if(sym == NULL_SYM)
        return;
    
    m_table[(from * 255) + (int)sym].push_back(to);

}

/**
 * get a list of next states for a given transition
 *
 * @param    from id of state to trasition from
 * @param    sym symbol to transition on
 *
 * @return   vector of possible next states
**/
const std::vector<int>& FAtTable::getTrans(int from, char sym) {
     // if given state ids are out of bounds, return empty vector
    if(from < 0 || from >= m_numStates)
        return *(new std::vector<int>);
    
    return m_table[(from * 255) + (int)sym];
}
