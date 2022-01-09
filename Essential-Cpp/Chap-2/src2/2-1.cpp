#include <iostream>
using namespace std;

// 函数声明
bool fibon_elem(int, int &);
// & 表示形参为引用类型, 引用与实参进行绑定, 作为实参的别名
// 所以, 使用引用类型, 传入实参后, 函数对引用的操作, 就是对实参的操作 !
bool print_sequence(int);
int main()
{
    int pos;
    int elem;

    cout << "Enter a position (q to quit): ";
    while (cin >> pos)
    {
        if (fibon_elem(pos, elem))
        {
            cout << "elem # " << pos << " is " << elem << endl;
            print_sequence(pos);
        }
        else
            cout << "Sorry. Could not calculate element # " << pos << endl;
        cout << "\nEnter a position (q to quit): ";
    }

    return 0;
}

bool fibon_elem(int pos, int &elem)
{
    // 检查位置是否合理
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    elem = 1; // 位置为 1 和 2 时, elem 的值为 1
    int n2 = 1, n1 = 1;

    for (int i = 3; i <= pos; i++)
    {
        elem = n1 + n2;
        n2 = n1;
        n1 = elem;
    }

    return true;
}

bool print_sequence(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos << " -- cannot handle request!\n";
        return false;
    }

    cout << "The Fibonacci Sequence for " << pos << " position:\n\t";
    // 所有位置都会打印 1 1, 只有 1 == pos 除外
    switch (pos)
    {
    default:
    case 2:
        cout << "1 ";
    case 1:
        cout << "1 ";
        break;
    }

    int elem;
    for (int i = 3; i <= pos; i++)
    {
        fibon_elem(i, elem);
        cout << elem << ((i % 10) ? " " : "\n\t");
    }
    cout << endl;

    return true; // 隐式退出点, 此处需要有 return !
}