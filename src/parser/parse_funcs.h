/**
 * @file    parse_funcs.h
 *
 * @brief   general parser functions that dont need a full class
 *          of their own.
 *
 * @author  Connor Nolan
**/

#ifndef __PARSE_FUNCS_H__
#define __PARSE_FUNCS_H__

#include <list>
#include "../util/tokens.h"
#include "parse_table.h"
#include "grammar.h"

using std::list;

int runParse(pTable& pt, grammar& g, list<token>& input);

#endif
