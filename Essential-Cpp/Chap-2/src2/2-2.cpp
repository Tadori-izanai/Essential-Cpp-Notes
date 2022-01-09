// #define MY_DEBUG
#include <iostream>
#include <vector>
using namespace std;

#ifdef MY_DEBUG // 注意要写在 std 下方
#include <fstream>
ofstream ofil("text_out1");
#endif // DEBUG

void display(vector<int>);
// void swap(int, int);
void swap(int &, int &);            // 改为传址 (pass by reference)
// void bubble_sort(vector<int>);
void bubble_sort(vector<int> &);    // 改为传址
int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);    // 利用数组赋值
    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);
    cout << "vector after sort: ";
    display(vec);

    return 0;
}

void display(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

// void swap(int val1, int val2)
void swap(int &val1, int &val2)     // 最简单的方法是将参数声明为一个 reference
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

// void bubble_sort(vector<int> vec)
void bubble_sort(vector<int> &vec)  // 此处也要传址
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[i])
            {
#ifdef MY_DEBUG
                ofil << "about to call swap!"
                     << " i: " << i << " j: " << j << '\t'
                     << " swapping: " << vec[i] << " with " << vec[j] << endl;
#endif // DEBUG
                swap(vec[i], vec[j]);
            }
        }
    }
}