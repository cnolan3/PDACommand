#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <sstream>
#include "fa/fa.h"
#include "parser/parse_funcs.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

void* test(string text);

int main() {
    pTable pt(5, 10);
    pt.set(0, 0, 7, shift);
    pt.set(1, 0, 9, shift);
    pt.set(3, 0, 1, gotoState);
    pt.set(4, 0, 2, gotoState);
    pt.set(2, 1, 0, accept);
    pt.set(0, 2, 4, shift);
    pt.set(1, 2, 6, shift);
    pt.set(4, 2, 3, gotoState);
    pt.set(2, 3, 0, reduce);
    pt.set(0, 4, 4, shift);
    pt.set(1, 4, 6, shift);
    pt.set(4, 4, 5, gotoState);
    pt.set(2, 5, 1, reduce);
    pt.set(2, 6, 2, reduce);
    pt.set(0, 7, 7, shift);
    pt.set(1, 7, 9, shift);
    pt.set(4, 7, 8, gotoState);
    pt.set(0, 8, 1, reduce);
    pt.set(1, 8, 1, reduce);
    pt.set(0, 9, 2, reduce);
    pt.set(1, 9, 2, reduce);

    string s = "";
    s += 4;
    s += 4;

    grammar g;
    g.addRule(3, s, NULL);

    s = "";
    s += (char)0;
    s += 4;

    g.addRule(4, s, NULL);

    s = "";
    s += 1;

    g.addRule(4, s, NULL);

    list<token> tlist;
    token t;
    t.id = (char)0;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)1;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)0;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)0;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)1;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)0;
    t.val = NULL;

    tlist.push_back(t);

    t.id = (char)2;
    t.val = NULL;

    tlist.push_back(t);

    runParse(pt, g, tlist); 
}
