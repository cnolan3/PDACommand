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

class tFunc
{
public:
    tFunc(int numStates);

    void setTrans(int state, char input, char stack, int nState, std::string push);
    void getTrans(int state, char input, char stack, int& nState, std::string& push);
private:
    
    struct move
    {
        int nState;
        std::string push;
    };

    int m_numStates;
    move* m_trans;
};

#endif
