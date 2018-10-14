/**
 * @file    fa_alpha.cpp
 *
 * @brief   Finite automaton alphabet object.
 *
 * @author  Connor Nolan
**/

#include "fa_alpha.h"
#include "../util/constants.h"

/**
 * FAAlpha constructor
**/
FAAlpha::FAAlpha() {

}

/**
 * Add a character to the alphabet
 *
 * @param    id id of character
 * @param    state fa acceptance state that corresponds to character
 * @param    action function the executes on match
**/
void FAAlpha::addAlpha(unsigned int id, int state, void* (*action)(string text), bool ignore) {
    // should not be able to set an id to the sentinel character
    if(id == SENTINEL)
        return;

    alphaToken a;
    a.id = id;
    a.state = state;
    a.action = action;
    a.ignore = ignore;

    alpha.push_back(a);
}

/**
 * get the alphabet list
 *
 * @return   vector of alphabet tokens
**/
vector<alphaToken> FAAlpha::getList() {
    return alpha;
}
