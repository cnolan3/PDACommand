/**
 * @file    pda.h
 *
 * @brief   Pushdown automata object declaration
 *
 * @author  Connor Nolan
**/

#ifndef __PDA_H__
#define __PDA_H__

#include "pda_stack.h"

class PDA
{
public:
    PDA();

private:
    int m_state;
    PDAStack m_stack;
};

#endif
