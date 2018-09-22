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

int main() {

    FAtTable table(8);
    table.addTrans(0, 1, EMPTY_SYM);
    table.addTrans(1, 2, 'b');
    table.addTrans(2, 1, EMPTY_SYM);
    table.addTrans(2, 7, EMPTY_SYM);
    table.addTrans(1, 3, 'a');
    table.addTrans(3, 4, 'a');
    table.addTrans(4, 1, EMPTY_SYM);
    table.addTrans(4, 7, EMPTY_SYM);
    table.addTrans(0, 5, '\n');
    table.addTrans(0, 6, ' ');

    std::vector<int> end;
    end.push_back(7);
    end.push_back(5);
    end.push_back(6);

    FA fa(table, end);

    std::list<std::pair<std::string, int> > out;

    out = fa.run(cin);

    while(out.size() > 0) {
        std::pair<std::string, int> tmp = out.front();
        out.pop_front();

        for(int i = 0; i < tmp.first.length(); i++) {
            if(tmp.first[i] == '\n')
                cout << "\\n";
            else
                cout << tmp.first[i];
        }

        cout << " " << tmp.second << endl;
    }

    return 0;
}
