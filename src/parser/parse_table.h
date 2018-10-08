/**
 * @file    parse_table.h
 *
 * @brief   parse table object to be used with the various
 *          types of LR parsers.
 *
 * @author  Connor Nolan
**/

#ifndef __PARSE_TABLE__
#define __PARSE_TABLE__

enum moveType {
    accept,
    reduce,
    shift,
    gotoState,
    none
};

struct move
{
    int num;
    moveType type;
};

class pTable
{
public:
    pTable(int numSym, int numStates);

    void set(char sym, int state, int num, moveType type);

    move get(char sym, int state);
private:
    int m_numSym;
    int m_numStates;

    move* m_syms;
};

#endif
