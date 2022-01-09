#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS // 以使用 bind1st
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator> // back_insert()
using namespace std;

template <typename inputIter, typename outputIter, typename elemType, typename comp>
outputIter filter(inputIter, inputIter, outputIter, const elemType &, comp);

int main()
{
    const int elem_size = 8;
    const int val = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for values less than " << val << ":\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), val, greater<int>());

    return 0;
}

template <typename inputIter, typename outputIter, typename elemType, typename comp>
outputIter filter(inputIter first, inputIter last, outputIter at, const elemType &val, comp pred)
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}