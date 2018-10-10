/**
 * @file    parse_table.cpp
 *
 * @brief   parse table definitions
 *
 * @author  Connor Nolan
**/

#include "parse_table.h"
#include <climits>
#include <iostream>

using std::cout;
using std::endl;

/**
 * pTable constructor
 *
 * @param    numTerm number of terminals in table
 * @param    numNTerm number of non-terminals in table
 * @param    numStates number of states in table
**/
pTable::pTable(int numStates)
    : m_numStates(numStates)
{
    m_syms = new move[UCHAR_MAX * m_numStates];

    for(int i = 0; i < (UCHAR_MAX * m_numStates); i++) {
        m_syms[i].num = -1;
        m_syms[i].type = none;
    }
}

/**
 * set a terminal entry in table
 *
 * @param    term id of terminal
 * @param    state id of state
 * @param    num number associated with table entry
 * @param    type entry type
**/
void pTable::set(unsigned char sym, int state, int num, moveType type) {
    move m;
    m.num = num;
    m.type = type;

    m_syms[(state * UCHAR_MAX) + sym] = m;
}

/**
 * get terminal entry from table
 *
 * @param    term id of terminal
 * @param    state id of state
 *
 * @return   move for specified terminal
**/
move pTable::get(unsigned char sym, int state) {
    return m_syms[(state * UCHAR_MAX) + sym];
}
