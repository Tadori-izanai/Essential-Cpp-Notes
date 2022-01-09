#include <iostream>
// #include <string>    // 去掉无任何报错, 草
using namespace std; // 去掉之后显示 string, cout, cin 无定义

int main()
{
    string user_name;
    cout << "Please enter your  first name: ";
    cin >> user_name;
    cout << '\n'
         << "Hello, "
         << user_name
         << " ... and good bye";

    return 0;
}