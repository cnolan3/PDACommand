/**
 * @file    fa.h
 *
 * @brief   non-deterministic finite automaton to be generated by regular expressions
 *          and used for lexical analysis of a document.
 *
 * @author  Connor Nolan
**/

#ifndef __FA_H__
#define __FA_H__

#include <vector>
#include "trans_table.h"

class FA
{
public:
    FA(int numStates);

private:
    int m_numStates;
    tTable m_tTable;
};

#endif
