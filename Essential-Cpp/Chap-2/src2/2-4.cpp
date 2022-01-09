#include <iostream>
#include <vector>
using namespace std;

const vector<int> *fibon_seq(int);
int main()
{
    int pos;
    int elem;

    cout << "Enter a position (q to quit): ";
    while (cin >> pos)
    {
        if (fibon_seq(pos))
            cout << "elem # " << pos << " is " << (*fibon_seq(pos + 1))[pos] << endl;   // size 是 (pos + 1)
        else
            cout << "Sorry. Could not calculate element # " << pos << endl;
        cout << "\nEnter a position (q to quit): ";
    }

    return 0;
}

const vector<int> *fibon_seq(int size)
{
    const int max_size = 1024;
    static vector<int> elems; // 局部静态对象, 一个空的 vector

    if (size <= 0 || size > max_size) // 超出范围
    {
        cerr << "fibon_seq(): oops, invalid size "
             << size
             << "can't fulfill request.\n";
        return 0;
    }

    for (int i = elems.size(); i < size; i++)
    {
        if (0 == i || 1 == i)
            elems.push_back(1); // push_back() 会将数值放在 vector 末端
        else
            elems.push_back(elems[i - 1] + elems[i - 2]);
    }
    return &elems;
}