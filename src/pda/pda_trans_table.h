/**
 * @file    pda_trans_table.h
 *
 * @brief   Object to hold and provide easy access to
 *          PDA transition function rules. Assumes that
 *          all ascii values are accepted symbols in the
 *          PDA.
 *
 * @author  Connor Nolan
**/

#ifndef __PDA_TRANS_TABLE_H__
#define __PDA_TRANS_TABLE_H__

#include <string>
#include <vector>
#include "../constants.h"
    
struct move
{
    int nState;
    std::string push;
    void* (*action)();
};

class PDAtTable
{
public:
    PDAtTable(int numStates, std::vector<int> inputSet);
    PDAtTable(const PDAtTable& old_table);

    unsigned int numStates();
    void setTrans(int state, int input, char stack, int nState, std::string push, void* (*action)() = NULL);
    const std::vector<move>& getTrans(int state, char input, char stack);
    void clear();
private:

    unsigned int m_numStates;
    unsigned int m_numInSyms;
    unsigned int m_mapMin;
    unsigned int m_mapMax;
    unsigned int* m_inMap;
    std::vector<move>* m_trans;
};

#endif
