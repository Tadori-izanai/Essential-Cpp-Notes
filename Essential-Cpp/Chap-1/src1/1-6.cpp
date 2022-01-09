#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int *pi;
    if (pi)
        cout << pi << endl;
    int *pj = 0;
    cout << pj << endl;

    // 测试
    // const int size = 5;
    // int data[size] = {
    //     1, 1, 2, 3, 5
    // };
    // vector<int> fibonacci(data, data + size);
    // if (!fibonacci.empty(), 5 == fibonacci[4])  // 利用数组初始化
    //     cout << 5 << endl;

    // for (int i = 0; i < 5; i++)
    //     fibonacci[i] = 0;
    
    // if (fibonacci.empty())
    //     cout << "empty\n";
    // else {
    //     for (int i = 0; i < 5 ; i++)
    //         cout << fibonacci[i] << ' ';
    //     cout << endl;
    // }

    // vector<int> pell(size);
    // if (pell.empty())
    //     cout << "pell is empty.\n";
    // else
    //     cout << "pell.empty() = " << pell.empty() << endl;

    return 0;
}