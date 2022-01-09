#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cal(vector<int> &, int);
void display(vector<int> &, const string &, ostream & = cout);
int main()
{
    vector<int> pent;
    const string title("Pentagoal Numeric Series");

    if (cal(pent, 0))
        display(pent, title);

    if (cal(pent, 8))
        display(pent, title);

    if (cal(pent, 14))
        display(pent, title);

    if (cal(pent, 138))
        display(pent, title);

    return 0;
}

bool cal(vector<int> &seq, int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "The position " << pos << " is Invalid.\n";
        return false;
    }

    for (int i = seq.size(); i <= pos; i++)
        seq.push_back(i * (3 * i - 1) / 2);

    return true;
}

void display(vector<int> &seq, const string &tit, ostream &os)
{
    os << tit << "\n\t";
    for (int i = 1; i < seq.size(); i++)    // 丢弃 seq[0]
        os << seq[i] << ((i % 10) ? " " : "\n\t");
    os << endl;
}