#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    const int size = 5;
    int ar1[size] = {1, 3, 5, 7, 9};
    int ar2[size] = {0, 2, 4, 6, 8};
    vector<int> vec1(ar1, ar1 + size);
    vector<int> vec2(ar2, ar2 + size);
    // vector<int> res;  // 此处必须分配空间, 否则出现运行错误
    vector<int> res(size);

    transform(vec1.begin(), vec1.end(), vec2.begin(), res.begin(), plus<int>());

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;

    return 0;
}

/*
    1 5 9 13 17 
*/