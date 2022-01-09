// #include <iostream>
// #include <vector>
// #include <fstream>
// using namespace std; // 最开始 4 行可以注释掉, 也可以留下
#include "./H2-3.h"

int main()
{
    // ofstream ofil;
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8); // 利用数组赋值
    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);
    cout << "vector after sort: ";
    display(vec);

    return 0;
}

void display(const vector<int> &vec, ostream &os)
{
    for (int i = 0; i < vec.size(); i++)
        os << vec[i] << ' ';
    os << endl;
}

void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec, ofstream *ofil)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[i])
            {
                if (ofil)
                {
                    (*ofil) << "about to call swap!"
                            << " i: " << i << " j: " << j << '\t'
                            << " swapping: " << vec[i] << " with ";
                }
                swap(vec[i], vec[j]);
            }
        }
    }
}