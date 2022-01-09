#include <iostream>
#include <vector>
#include "ex51.h"

ostream &operator<<(ostream &os, const Stack &rhs) {
    rhs.print(os);
    return os;
}

bool LIFO_Stack::pop(elemType &elem) {
    if (empty())
        return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool LIFO_Stack::push(const elemType &elem) {
    if (full())
        return false;
    _stack.push_back(elem);
    _top++;
    return true;
}   

void LIFO_Stack::print(ostream &os) const {     // 声明处已经指定了 os 默认值为 cout
    vector<elemType>::const_reverse_iterator rit = _stack.rbegin(),
                                            rend = _stack.rend();
    os << "\n\t";
    while (rit != rend)
        os << *rit++ << "\n\t";
    os << endl;
}





// int main()
// {
//     vector<int> ivec;
//     cout << ivec.max_size();

//     return 0;
// }