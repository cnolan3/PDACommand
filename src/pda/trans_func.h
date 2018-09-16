/**
 * @file    trans_func.h
 *
 * @brief   Object to hold and provide easy access to
 *          PDA transition function rules. Assumes that
 *          all ascii values are accepted symbols in the
 *          PDA.
 *
 * @author  Connor Nolan
**/

#ifndef __TRANS_FUNC_H__
#define __TRANS_FUNC_H__

#include <string>
#include <vector>
    
struct move
{
    int nState;
    std::string push;
};

class tFunc
{
public:
    tFunc(int numStates);

    void setTrans(int state, char input, char stack, int nState, std::string push);
    const std::vector<move>& getTrans(int state, char input, char stack);
    void clear();
private:

    int m_numStates;
    std::vector<move>* m_trans;
};

#endif
