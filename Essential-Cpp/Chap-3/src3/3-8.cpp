#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int ia[10] = {1, 3, 5, 8, 5, 3, 1, 5, 8, 1};
    vector<int> vec(ia, ia + 10);
    // set<int> iset(vec.begin(), vec.end());
    set<int> iset(ia, ia + 10);

    for (set<int>::iterator it = iset.begin(); it != iset.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}

/*
1 3 5 8 
*/