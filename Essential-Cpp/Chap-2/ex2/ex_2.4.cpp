#include <iostream>
#include <vector>
using namespace std;

inline bool check_validity(int);
const vector<int> *pent(int pos);
bool pent_elem(int, int &);

int main()
{
    int elem;

    if (pent_elem(8, elem))
        cout << "element 8 is " << elem << endl;

    if (pent_elem(88, elem))
        cout << "element 88 is " << elem << endl;

    if (pent_elem(12, elem))
        cout << "element 12 is " << elem << endl;

    if (pent_elem(64, elem))
        cout << "element 64 is " << elem << endl;

    return 0;
}

inline bool check_validity(int pos)
{
    if (pos <= 0 || pos > 32)
    {
        cerr << "Invalid position: " << pos << endl;
        return false;
    }
    return true;
}

bool pent_elem(int pos, int &elem)
{
    if (check_validity(pos))
    {
        elem = (*pent(pos))[pos];
        return true;
    }
    return false;
}

const vector<int> *pent(int pos)
{
    static vector<int> seq;

    for (int i = seq.size(); i <= pos; i++)
        seq.push_back(i * (3 * i - 1) / 2);

    return &seq;
}