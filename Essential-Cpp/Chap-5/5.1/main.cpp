#include "ex51.h"
#include <iostream>
#include <string>
using namespace std;

ostream &operator<<(ostream &os, const Stack &rhs);     // 引用其他文件的函数, 要声明
void peek(Stack &st, int index) {        // 参数是 基类的 reference
    cout << endl;
    string t;
    if (st.peek(index, t))
        cout << "Peek: " << t;
    else
        cout << "peek failed!";
    cout << endl;
}

int main()
{
    LIFO_Stack st;
    string str;
    while (cin >> str && !st.full())
        st.push(str);
    
    cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
    peek(st, st.top() - 1);
    cout << st;

    LIFO_Stack pst;
    while (!st.empty()) {
        string t;
        if (st.pop(t))
            pst.push(t);
    }

    cout << "About to call peek() with Peekback_Stack" << endl;
    peek(pst, pst.top() - 1);
    cout << pst;

    return 0;
}