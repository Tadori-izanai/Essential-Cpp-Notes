#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int size = 64;
    vector<int> vec_num(size);
    int arr_num[size];
    int count = 0;
    int sum_arr = 0, sum_vec = 0;

    cout << "Enter a set of integers (q to quit):" << endl;
    while (count < size && cin >> vec_num[count])
    {
        arr_num[count] = vec_num[count];
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        sum_arr += arr_num[i];
        sum_vec += arr_num[i];
    }

    if (count > 0)
    {
        cout << "Sum for vector: " << sum_vec << endl;
        cout << "Sum for array: " << sum_arr << endl;
        cout << "Average for array: " << (double)sum_arr / count << endl;
        cout << "Average for vector: " << (double)sum_vec / count << endl;
    }
    else
        cout << "No input!" << endl;

    return 0;
}