/**
 * @file    fa_alpha.h
 *
 * @brief   Finite automaton alphabet object.
 *
 * @author  Connor Nolan
**/

#ifndef __FA_ALPHA_H__
#define __FA_ALPHA_H__

#include <vector>
#include <string>
#include "../util/tokens.h"

using std::vector;

class FAAlpha
{
public:
    FAAlpha();

    void addAlpha(char id, int state, void* (*action)(string text));
    vector<alphaToken> getList();
private:
    vector<alphaToken> alpha;
};

#endif
