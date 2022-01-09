#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int max_seq(6);           // 构造函数语法, 相当于 const int max_seq = 6;
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    cout << seq_names[2];

    return 0;
}