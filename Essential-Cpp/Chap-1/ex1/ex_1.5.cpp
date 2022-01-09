#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int size = 11;
    string s_obj;     // 使用 string 对象
    char s_arr[size]; // C-style

    // 使用 string
    cout << "Enter your name :";
    while (cin >> s_obj, s_obj.length() < 2)
    {
        cerr << "name length should be more than 1!\n"
             << "Enter again!\n";
    }
    cout << "Hello, "
         << s_obj << endl;

    return 0;
}