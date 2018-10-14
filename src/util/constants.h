/**
 * @file    constants.h
 *
 * @brief   defines symbol aliases for PDA and FA
 *
 * @author  Connor Nolan
**/
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <climits>

// this symbol is always excluded from all
// symbol sets, should never be used to create
// rules for a transition table.
#define NULL_SYM 0

// initial stack symbol for PDA.
#define INIT_SYM 1

// empty transition symbol.
#define EMPTY_SYM 2

// end symbol for LR parser string
#define END_SYM UINT_MAX - 1

#define SENTINEL UINT_MAX

#endif
