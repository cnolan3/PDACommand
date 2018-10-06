/**
 * @file    fa_trans_table.h
 *
 * @brief   transition table for non-deterministic finite automaton
 *
 * @author  Connor Nolan
**/

#ifndef __TRANS_TABLE_H__
#define __TRANS_TABLE_H__

#include <vector>

using std::vector;

class FAtTable
{
public:
    FAtTable(int numStates);
    FAtTable(const FAtTable& old_table);

    int numStates();
    void addTrans(int from, int to, char sym);
    const vector<int>& getTrans(int from, char sym);
private:
    int m_numStates;
    std::vector<int>* m_table;
};

#endif
