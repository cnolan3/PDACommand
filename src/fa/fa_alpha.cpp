#include "fa_alpha.h"

FAAlpha::FAAlpha() {

}

void FAAlpha::addAlpha(int id, int state, void* (*action)(string text)) {
    alphaToken a;
    a.id = id;
    a.state = state;
    a.action = action;

    alpha.push_back(a);
}

vector<alphaToken> FAAlpha::getList() {
    return alpha;
}
