#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename iterType, typename elemType>
iterType find(iterType, iterType, elemType &); // 第三参数加 const 报错
int main()
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia + asize);

    int *pia = find(ia, ia + asize, 1024);
    if (pia != ia + asize)
        cout << "find 1024 in ia\n";

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 13);
    if (it != ivec.end())
        cout << "find 13 in ivec\n";

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 8);
    if (iter != ilist.end())
        cout << "find 8 in ilist\n";

    return 0;
}

template <typename iterType, typename elemType>
iterType find(iterType first, iterType last, elemType &value) // 第三参数加 const 报错
{
    for (; first != last; ++first)
    {
        if (value == *first)
            return first;
    }
    return last;
}