#include <iostream>
#include <vector>
#include <utility>
#include "pda/pda.h"

using std::cout;
using std::endl;

int main() {

    rule r;
    vector<rule> rules;

    PDA p(4, rules);

    vector<pair<string, int> > out;

    out = p.run("abaabb");

    for(int i = 0; i < out.size(); i++) {
        cout << out[i].first << " " << out[i].second << endl;
    }

    return 0;
}
