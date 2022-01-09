#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main()
{
    int ival;
    deque<int> a_line;

    // while (cin >> ival){
    //     a_line.push_back(ival);

    //     int curr_value = a_line.front();
    //     cout << curr_value << endl;

    //     a_line.pop_front();         // 删除最前端元素
    // }

    int init[3] = {1, 3, 5};
    vector<int> ivec(init, init + 3); // 给初值
    vector<int>::iterator it;
    cout << "Enter a integer(q to quit): ";
    while (cin >> ival)
    {
        it = ivec.begin();
        while (it != ivec.end())
        {
            if (*it >= ival)
            {
                ivec.insert(it, ival);
                break; // 插入后退出循环
            }
            // ivec.insert(it, ival);
            it++;
        }
        if (it == ivec.end())
            ivec.insert(it,ival);

        for (int i = 0; i < ivec.size(); i++)
            cout << ivec[i] << ' ';
        cout << endl;
        cout << "Enter a integer(q to quit): ";
    }

    return 0;
}