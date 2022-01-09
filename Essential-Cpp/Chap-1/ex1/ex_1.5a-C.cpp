/*
    1. 使用 cstring 头文件中的 strlen()
    2. iostream 操作符 setw() 保证读入长度不超过一定值
    3. 用到 setw(), 必须包含头文件 iomanip
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    const int nm_size = 128; // 分配一个空间
    char usr_name[nm_size];
    cout << "Enter your name: ";
    cin >> setw(nm_size) >> usr_name; // 使用 setw() 操作符

    switch (strlen(usr_name))
    {
    case 0:
        cout << "user with no name\n";
        break;
    case 1:
        cout << "name length should be large than 2\n";
        break;
    case 127:
        cout << "That a very big name";
        break;
    default:
        cout << "Hello, " << usr_name << endl;
        break;
    }

    return 0;
}