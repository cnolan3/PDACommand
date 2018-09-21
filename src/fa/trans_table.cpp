/**
 * @file    trans_table.cpp
 *
 * @brief   definitions of tTable object.
 *
 * @author  Connor Nolan
**/

#include "trans_table.h"

/**
 * tTable constructor
 *
 * @param    numStates number of states in automata
**/
tTable::tTable(int numStates)
    : m_numStates(numStates)
{
    m_table = new std::vector<int>[m_numStates * 255];
}

/**
 * add a transition to the table, can define multiple outputs
 * for each transition.
 *
 * @param    from id of state to transition from
 * @param    to id of state to transition to
 * @param    sym symbol to transition on
**/
void tTable::addTrans(int from, int to, char sym) {
    // if given state ids are out of bounds, return
    if(from < 0 || from >= m_numStates || to < 0 || to >= m_numStates)
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
const std::vector<int>& tTable::getTrans(int from, char sym) {
     // if given state ids are out of bounds, return empty vector
    if(from < 0 || from >= m_numStates)
        return *(new std::vector<int>);
    
    return m_table[(from * 255) + (int)sym];
}
