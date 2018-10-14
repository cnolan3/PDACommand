/**
 * @file    parse_funcs.cpp
 *
 * @author  Connor Nolan
**/

#include "parse_funcs.h"
#include <climits>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

/**
 * run the parse table
 *
 * @param    pt parse table to use
 * @param    g grammar to use
 * @param    input list of input tokens
 *
 * @return   status of parse, 1 for succuss, 0 for fail
**/
int runParse(pTable& pt, grammar& g, list<token>& input) {
    vector<token> tStack; // token stack
    vector<int> sStack;   // state stack

    move m;

    sStack.push_back(0);

    while(1) {


        list<token>::iterator tlistit;

        cout << sStack[0] << " ";
        for(int i = 1; i < sStack.size(); i++) {
            cout << (int)tStack[i - 1].id << " " << sStack[i] << " ";
        }

        cout << "    ";

        for(tlistit = input.begin(); tlistit != input.end(); ++tlistit) {
            cout << (int)(*tlistit).id << " ";
        }

        cout << "    ";


        // if either input or state stack if empty
        // return fail
        if(sStack.size() == 0 || input.size() == 0)
            return 0;

        // get move for current token and state
        m = pt.get(input.front().id, sStack.back());

        if(m.type == shift)
            cout << "shift";
        else if(m.type == reduce)
            cout << "reduce";
        else if(m.type == accept)
            cout << "accept";
        else if(m.type == gotoState)
            cout << "goto";
        else if(m.type == none)
            cout << "fail";

        cout << " " << m.num << endl;

        // take action depending on type of move
        if(m.type == shift) {
            tStack.push_back(input.front());
            input.pop_front();
            sStack.push_back(m.num);
        }
        else if(m.type == reduce) {
            rule r = g.getRule(m.num);
            void** varBuf = new void*[r.lhs.size()];

            for(int i = r.lhs.size() - 1; i >= 0; i--) {
                if(r.lhs[i] == tStack.back().id) {
                    varBuf[i] = tStack.back().val;
                    tStack.pop_back();
                    sStack.pop_back();
                }
                else
                    return 0;
            }

            token t;
            t.id = r.rhs;
            t.val = NULL;

            if(r.action)
                t.val = r.action(varBuf);

            tStack.push_back(t);

            move tmp = pt.get(tStack.back().id, sStack.back());

            sStack.push_back(tmp.num);
        }
        else if(m.type == accept) {
            break;
        }
        else if(m.type == none) {
            return 0;
        }
    }

    return 1;
}

/**
 * generate a LALR parse table
 *
 * @param    g grammar
 * 
 * @return   parse table from g
**/
pTable& LALR(grammar& g) {
    vector<rule> rules;
    tokenType* types = new tokenType[UCHAR_MAX];
    pTable* pt;

    // classify all symbols as terminal or nonterminal
    for(int i = 0; i < UCHAR_MAX; i++) {
        types[i] = empty;
    }

    rules = g.getRules();

    for(int i = 0; i < rules.size(); i++) {
        rule r = rules[i];

        types[r.rhs] = nonterminal;
        
        for(int j = 0; j < r.lhs.size(); j++) {
            if(types[r.lhs[j]] == empty)
                types[r.lhs[j]] = terminal;
        }
    }
}
