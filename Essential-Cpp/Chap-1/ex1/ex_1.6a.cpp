// 使用 vector
#include <iostream>
#include <vector>
// #include <string>
using namespace std;

int main()
{
    vector<int> ivec;
    int ival;
    int sum = 0;

    while (cin >> ival)       // 将输入的数据逐个存入 ival
        ivec.push_back(ival); // ??

    for (int i = 0; i < ivec.size(); i++)
        sum += ivec[i];

    int ave = sum / ivec.size();
    cout << "Sum of " << ivec.size()
         << " elements: " << sum
         << ". Average: " << ave
         << endl;
         
    return 0;
}