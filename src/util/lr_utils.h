#ifndef __LR_UTILS_H__
#define __LR_UTILS_H__

#include <vector>

using std::vector;

struct LALRRule {
    int id;        // corresponding grammar rule id
    int index;     // index of current LHS character
    int lookahead; // index into array of lookahead symbols
};

struct LALRState {
    
};

#endif
