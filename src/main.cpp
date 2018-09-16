#include <iostream>
#include <vector>
#include <utility>
#include "pda/pda.h"

using std::cout;
using std::endl;

int main() {

    rule r;
    vector<rule> rules;
    vector<int> end;

    r.state = 0;
    r.input = 'a';
    r.stackSym = EMPTY_SYM;
    r.nState = 1;
    r.pushSym = 'a';
    r.pushSym += INIT_SYM;

    rules.push_back(r);

    r.state = 1;
    r.input = 'a';
    r.stackSym = EMPTY_SYM;
    r.nState = 1;
    r.pushSym = "a";

    rules.push_back(r);

    r.state = 1;
    r.input = EMPTY_SYM;
    r.stackSym = EMPTY_SYM;
    r.nState = 2;
    r.pushSym = EMPTY_SYM;

    rules.push_back(r);

    r.state = 2;
    r.input = 'b';
    r.stackSym = 'a';
    r.nState = 2;
    r.pushSym = EMPTY_SYM;

    rules.push_back(r);

    r.state = 2;
    r.input = EMPTY_SYM;
    r.stackSym = INIT_SYM;
    r.nState = 3;
    r.pushSym = EMPTY_SYM;

    rules.push_back(r);

    end.push_back(3);

    PDA p(4, rules, end);

    vector<pair<string, int> > out;

    out = p.run("abaabb");

    for(int i = 0; i < out.size(); i++) {
        cout << out[i].first << " " << out[i].second << endl;
    }

    return 0;
}
