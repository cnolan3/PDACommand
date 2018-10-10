/**
 * @file    parse_table.h
 *
 * @brief   parse table object to be used with the various
 *          types of LR parsers. All ascii values are 
 *          accepted symbols.
 *
 * @author  Connor Nolan
**/

#ifndef __PARSE_TABLE__
#define __PARSE_TABLE__

enum moveType 
{
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
    pTable(int numStates);

    void set(unsigned char sym, int state, int num, moveType type);

    move get(unsigned char sym, int state);
private:
    int m_numStates;

    move* m_syms;
};

#endif
