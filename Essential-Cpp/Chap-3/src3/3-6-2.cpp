/*
    // 改为泛型算法
    vector<int> sub_vec(const vector<int> &vec, int val) {
        vector<int> local_vec(vec);	// 使用复制的方式定义一个 vector
        sort(local_vec.begin(), local_vec.end());	// 对副本 vector 排序
        
        vector<int>::iterator iter;
        iter = find_if(local_vec.bigin(), local_vec.end(), bind2nd(grater<int>(), val));
        
        local_vec.erase(iter, local_vec.end());	// 删除后面大于 val 的部分
        return local_vec;
    }
*/

#define _LIBCPP_ENABLE_CXX17_REMOVED_BINDERS // 以使用 bind1st
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template <typename tempType, typename iterType, typename elemType, typename Comp>
void sub(tempType &target, iterType first, iterType last, const elemType &val, Comp pred) // 不支持数组.
{
    tempType local_temp(first, last); // 创建副本
    iterType local_first = local_temp.begin(),
             local_last = local_temp.end();

    sort(local_first, local_last, pred); // 排序
    iterType it = find_if(local_first, local_last, bind1st(pred, val));
    local_temp.erase(it, local_last);
    target = local_temp;
}

template <typename iterType>
void display(iterType, iterType);
int main()
{
    const int elem_size = 8;
    const int val = 8; // 用于比较
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);
    vector<int> less_vec, greater_vec; // 存储过滤结果

    sub(less_vec, ivec.begin(), ivec.end(), val, less<int>());
    cout << "filtering integer array for values less than " << val << ":\n";
    display(less_vec.begin(), less_vec.end());

    sub(greater_vec, ivec.begin(), ivec.end(), val, greater<int>());
    cout << "filtering integer vector for values grater than " << val << ":\n";
    display(greater_vec.begin(), greater_vec.end());

    // vector<int> test;
    // sub(test, ia, ia + elem_size, val, less<int>());         // 对数组不可行.
    // cout << "filtering integer vector for values less than " << val << ":\n";
    // display(test.begin(), test.end());

    return 0;
}

template <typename iterType>
void display(iterType first, iterType last)
{
    for (iterType it = first; it != last; it++)
        cout << *it << ' ';
    cout << endl;
}