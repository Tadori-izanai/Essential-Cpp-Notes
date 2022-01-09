#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS // 用于使用 bind2nd
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm> // find_if()
using namespace std;

template <typename inputIter, typename outputIter, typename elemType, typename Comp>
outputIter filter(inputIter, inputIter, outputIter, const elemType &, Comp);

int main()
{
    const int elem_size = 8;
    const int val = 8; // 用于比较
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    int ia2[elem_size];           // 存储过滤结果
    vector<int> ivec2(elem_size); // 存储过滤结果

    cout << "filtering integer array for values less than " << val << ":\n";
    filter(ia, ia + elem_size, ia2, val, less<int>()); // 泛型算法用于数组

    cout << "filtering integer vector for values grater than " << val << ":\n";
    filter(ivec.begin(), ivec.end(), ivec2.begin(), val, greater<int>()); // 泛型算法用于 vector

    return 0;
}

template <typename inputIter, typename outputIter, typename elemType, typename Comp>
outputIter filter(inputIter first, inputIter last, outputIter at, const elemType &val, Comp pred)
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    {
        // at->push_back(*first); // 不使用, push_back() 不是容器的共通操作
        // first++;
        cout << "found value: " << *first << endl; // 用于观察进行的情形
        *at++ = *first++;                          // 注意 * 和 ++ 优先级相同
    }
    return at;
}

/*
filtering integer array for values less than 8:
found value: 0
found value: 6
found value: 3
found value: 7
filtering integer vector for values grater than 8:
found value: 12
found value: 43
found value: 21
*/