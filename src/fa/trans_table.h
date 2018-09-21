/**
 * @file    trans_table.h
 *
 * @brief   transition table for non-deterministic finite automaton
 *
 * @author  Connor Nolan
**/

#ifndef __TRANS_TABLE_H__
#define __TRANS_TABLE_H__

#include <vector>

class tTable
{
public:
    tTable(int numStates);

    void addTrans(int from, int to, char sym);
    const std::vector<int>& getTrans(int from, char sym);
private:
    int m_numStates;
    std::vector<int>* m_table;
};

#endif
