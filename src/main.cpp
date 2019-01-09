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

void* t1(void** varBuf);
void* t2(void** varBuf);
void* t3(void** varBuf);
void* a(string text);
void* b(string text);

int main() {
    /*
    pTable pt(10);
    pt.set(0, 0, 7, shift);
    pt.set(1, 0, 9, shift);
    pt.set(3, 0, 1, gotoState);
    pt.set(4, 0, 2, gotoState);
    pt.set(END_SYM, 1, 0, accept);
    pt.set(0, 2, 4, shift);
    pt.set(1, 2, 6, shift);
    pt.set(4, 2, 3, gotoState);
    pt.set(END_SYM, 3, 0, reduce);
    pt.set(0, 4, 4, shift);
    pt.set(1, 4, 6, shift);
    pt.set(4, 4, 5, gotoState);
    pt.set(END_SYM, 5, 1, reduce);
    pt.set(END_SYM, 6, 2, reduce);
    pt.set(0, 7, 7, shift);
    pt.set(1, 7, 9, shift);
    pt.set(4, 7, 8, gotoState);
    pt.set(0, 8, 1, reduce);
    pt.set(1, 8, 1, reduce);
    pt.set(0, 9, 2, reduce);
    pt.set(1, 9, 2, reduce);
    */

    vector<unsigned int> s;
    s.push_back('X');
    s.push_back('X');

    grammar g;
    g.addRule('S', s, t1);

    s.clear();
    s.push_back('a');
    s.push_back('X');

    g.addRule('X', s, t2);

    s.clear();
    s.push_back('b');

    g.addRule('X', s, t3);

    LALR(g);

    /*
    FAtTable ft(17);
    ft.addTrans(0, 1, '\n');
    ft.addTrans(0, 2, 32);
    ft.addTrans(0, 3, EMPTY_SYM);
    ft.addTrans(3, 4, '0');
    ft.addTrans(3, 5, '1');
    ft.addTrans(3, 6, '2');
    ft.addTrans(3, 7, '3');
    ft.addTrans(3, 8, '4');
    ft.addTrans(3, 9, '5');
    ft.addTrans(3, 10, '6');
    ft.addTrans(3, 11, '7');
    ft.addTrans(3, 12, '8');
    ft.addTrans(3, 13, '9');
    ft.addTrans(4, 14, EMPTY_SYM);
    ft.addTrans(5, 14, EMPTY_SYM);
    ft.addTrans(6, 14, EMPTY_SYM);
    ft.addTrans(7, 14, EMPTY_SYM);
    ft.addTrans(8, 14, EMPTY_SYM);
    ft.addTrans(9, 14, EMPTY_SYM);
    ft.addTrans(10, 14, EMPTY_SYM);
    ft.addTrans(11, 14, EMPTY_SYM);
    ft.addTrans(12, 14, EMPTY_SYM);
    ft.addTrans(13, 14, EMPTY_SYM);
    ft.addTrans(14, 3, EMPTY_SYM);
    ft.addTrans(14, 15, EMPTY_SYM);
    ft.addTrans(0, 16, 'a');

    FAAlpha alpha;
    alpha.addAlpha(0, 15, a);
    alpha.addAlpha(1, 16, b);
    alpha.addAlpha(2, 1, NULL, true);
    alpha.addAlpha(3, 2, NULL, true);

    FA fa(ft, alpha);

    list<token> tList;

    tList = fa.run(cin);

    list<token>::iterator it;
    for(it = tList.begin(); it != tList.end(); ++it) {
        cout << (int)(*it).id << " ";
    }
    cout << endl;

    runParse(pt, g, tList); 
    */
}

void* t1(void** varBuf) {
//    cout << "S -> XX" << endl;
    int a = *((int*)varBuf[0]) * *((int*)varBuf[1]);
//    cout << a << endl;
}

void* t2(void** varBuf) {
//    cout << "X -> aX" << endl;
    int a = *((int*)varBuf[0]);
    int b = *((int*)varBuf[1]);
    int* c = new int(a + b);
    return c;
}

void* t3(void** varBuf) {
//    cout << "X -> b" << endl;
    return varBuf[0];
}

void* a(string text) {
    return new int(stoi(text));
}

void* b(string text) {
    return new int(0);
}
