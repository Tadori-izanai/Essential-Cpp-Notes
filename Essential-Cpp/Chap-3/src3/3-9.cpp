// 引用 3.6 中的 filter(), 在调用其时, 使用 vector 的 back_insert
// 若只在 vector 末端插入元素, 效率高, 因此选用 back_inserter
#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS // 以使用 bind1st
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator> // back_insert()
using namespace std;

template <typename inputIter, typename outputIter, typename elemType, typename Comp>
outputIter filter(inputIter, inputIter, outputIter, const elemType &, Comp);

int main()
{
    const int elem_size = 8;
    const int val = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    int ia2[elem_size]; // 存储过滤结果
    // vector<int> ivec2(elem_size); // 存储过滤结果, 不使用 adapter 时, 需要先分配空间
    vector<int> ivec2; // 存储过滤结果, 使用 adapter, 不需要分配空间

    cout << "filtering integer array for values less than " << val << ":\n";
    filter(ia, ia + elem_size, ia2, val, less<int>()); // 内置数组不支持插入操作

    cout << "filtering integer vector for values grater than " << val << ":\n";
    // filter(ivec.begin(), ivec.end(), ivec2.begin(), val, greater<int>());
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), val, greater<int>()); // 此处使用 back_iterator

    return 0;
}

template <typename inputIter, typename outputIter, typename elemType, typename Comp>
outputIter filter(inputIter first, inputIter last, outputIter at, const elemType &val, Comp pred)
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    {
        cout << "found value: " << *first << endl;
        *at++ = *first++;      // 利用 iterator 赋值
    }
    return at;
}