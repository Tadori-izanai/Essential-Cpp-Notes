#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vals;
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    ofstream odd("./test_file/odd.txt");
    ofstream even("./test_file/even.txt");
    ostream_iterator<int> os_odd(odd, " ");
    ostream_iterator<int> os_even(even, "\n");

    if (!even || !odd)
    {
        cerr << "Unable to open the output files.\n";
        return -1;
    }

    cout << "Enter some integers (q to quit):\n";
    copy(is, eof, back_inserter(vals));

    vector<int> val_odd;
    vector<int> val_even;

    for (vector<int>::iterator iter = vals.begin(); iter != vals.end(); iter++)
    {
        if (*iter % 2)
            val_odd.push_back(*iter);
        else
            val_even.push_back(*iter);
    }

    copy(val_even.begin(), val_even.end(), os_even);
    copy(val_odd.begin(), val_odd.end(), os_odd);

    return 0;
}