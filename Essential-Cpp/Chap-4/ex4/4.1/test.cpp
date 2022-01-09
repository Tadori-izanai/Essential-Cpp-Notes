// 测试 Stack class 提供的接口
#include <iostream>
#include "Stack.h"

int main()
{
    Stack st;
    string str;

    while (cin >> str && !st.full())    // mac 中使用 ^D 来表示 EOF
        st.push(str);

    if (st.empty()) {
        cout << '\n' << "Oops: no strings were read -- baling out\n";
        return 0;
    }
    st.peek(str);
    if (1 == st.size() && str.empty()) {
        cout << '\n' << "Oops: no strings were read -- bailing out\n";
        return 0;
    }
    cout << '\n' << "Read in " << st.size() << " strings!\n"
        << "The strings, in reverse order: \n";

    while (st.size()) {
        if (st.pop(str))        // 从后往前逐个 pop
            cout << str << ' ';
    }
    cout << '\n' << "There are now " << st.size() << " elements in the stack!\n";

    return 0;
}