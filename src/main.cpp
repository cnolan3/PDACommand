#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <sstream>
#include "pda/pda.h"
#include "fa/fa.h"

using std::cout;
using std::cin;
using std::endl;

void* concat();
void* orop();
void* paren();
void* constant();
void* kleenes();
void* oneormore();
void* quant();
void* newline();

int main() {
    std::vector<int> inset;

    inset.push_back('S');
    inset.push_back('E');
    inset.push_back('A');
    inset.push_back('Q');
    inset.push_back('c');
    inset.push_back('|');
    inset.push_back('+');
    inset.push_back('*');
    inset.push_back('(');
    inset.push_back(')');
    inset.push_back('{');
    inset.push_back('}');
    inset.push_back('n');
    inset.push_back(',');
    inset.push_back('\n');

    PDAtTable p(3, inset);

    string s = "S";
    s += INIT_SYM;
    p.setTrans(0, EMPTY_SYM, EMPTY_SYM, 1, s);
    p.setTrans(1, EMPTY_SYM, 'S', 1, "E");

    // rules
    p.setTrans(1, EMPTY_SYM, 'E', 1, "(E)A", paren);
    p.setTrans(1, EMPTY_SYM, 'E', 1, "cA", constant);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "EA", concat);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "|EA", orop);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "+A", oneormore);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "*A", kleenes);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "QA", quant);
    p.setTrans(1, EMPTY_SYM, 'A', 1, "");
    p.setTrans(1, EMPTY_SYM, 'Q', 1, "{n}");
    p.setTrans(1, EMPTY_SYM, 'Q', 1, "{,n}");
    p.setTrans(1, EMPTY_SYM, 'Q', 1, "{n,}");
    p.setTrans(1, EMPTY_SYM, 'Q', 1, "{n,n}");

    // terminals
    p.setTrans(1, 'c', 'c', 1, ""); // character
    p.setTrans(1, '|', '|', 1, ""); // |
    p.setTrans(1, '+', '+', 1, ""); // +
    p.setTrans(1, '*', '*', 1, ""); // *
    p.setTrans(1, '(', '(', 1, ""); // (
    p.setTrans(1, ')', ')', 1, ""); // )
    p.setTrans(1, '{', '{', 1, ""); // {
    p.setTrans(1, '}', '}', 1, ""); // }
    p.setTrans(1, 'n', 'n', 1, ""); // number
    p.setTrans(1, ',', ',', 1, ""); // ,
//    p.setTrans(1, '\n', EMPTY_SYM, 1, "", newline);

    // match
    p.setTrans(1, EMPTY_SYM, INIT_SYM, 2, "");

    // set up PDA
    std::vector<int> end;
    
    end.push_back(2);

    PDA pda(p, end);

    // run
    std::list<std::pair<std::string, int> > out = pda.run(cin);

    while(out.size() > 0) {
        cout << out.front().first << " " << out.front().second << endl;
        out.pop_front();
    }

    return 0;
}

void* concat() {
    cout << "concat" << endl;
}

void* orop() {
    cout << "or" << endl;
}  

void* paren() {
    cout << "paren" << endl;
}

void* constant() {
    cout << "constant" << endl;
}

void* kleenes() {
    cout << "kleenes" << endl;
}

void* oneormore() {
    cout << "one or more" << endl;
}

void* quant() {
    cout << "quant" << endl;
}

void* newline() {
    cout << "newline" << endl;
}
