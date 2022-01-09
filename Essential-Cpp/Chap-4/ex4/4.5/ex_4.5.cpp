#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix m;
    cout << m << endl;

    elemType ar[16] = {
        1., 0., 0., 0., 
        0., 1., 0., 0., 
        0., 0., 1., 0., 
        0., 0., 0., 1.
    };
    Matrix id(ar);
    cout << id << endl;

    Matrix m2(id);  // default memberwise initialization (没有提供 copy)
    // Matrix m2 = id;
    m = id;         // 没有经过 overload 仍可以运行
    cout << m2 << endl;
    cout << m << endl;

    elemType ar2[16] = {
        1.3, 0.4, 2.6, 8.2,
        6.2, 1.7, 1.3, 8.3,
        4.2, 7.4, 2.7, 1.9,
        6.3, 8.1, 5.6, 6.6
    };
    Matrix m3(ar2);
    cout << m3 << endl;
    Matrix m4 = m3 * id;    // 测试乘法
    cout << m4 << endl;
    Matrix m5 = m3 + m4;    // 测试加法
    cout << m5 << endl;
    m3 += m4;               // 测试复合赋值
    cout << m3 << endl;

    return 0;
}