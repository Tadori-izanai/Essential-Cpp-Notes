#include <iostream>
#include "Stack.h"

int main() {
    Stack st;
    string str;
    while (cin >> str && !st.full())
        st.push(str);

    cout << '\n' << "Read in " << st.size() << " strings!\n";
    cin.clear();    // 清除 EOF 的设定, 卒
    cin.sync();     // 卒

    cout << "what word to search for? ";
    cin >> str;

    bool found = st.find(str);
    int count = found ? st.count(str) : 0;

    cout << str << (found ? " is " : "isn\'t ") << "in the stack. ";
    if (found)
        cout << "It occurs " << count << " times\n";

    return 0;
}