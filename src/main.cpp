#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <sstream>
#include "fa/fa.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

void* test(string text);

int main() {

    FAtTable table(4);

    table.addTrans(0, 1, EMPTY_SYM);
    table.addTrans(1, 2, 'a');
    table.addTrans(2, 1, EMPTY_SYM);
    table.addTrans(0, 3, '\n');

    FAAlpha alpha;

    alpha.addAlpha(0, 2, test);
    alpha.addAlpha(1, 3, test);

    FA fa(table, alpha);

    list<token> out = fa.run(cin);

    cout << out.size() << endl;

    while(out.size() > 0) {
        token t = out.front();
        out.pop_front();

        cout << t.id << endl;
    }
    
    return 0;
}

void* test(string text) {
    for(int i = 0; i < text.length(); i++) {
        cout << (int)text[i] << " ";
    }
    cout << endl;
}
