#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    vector<int> numbers;

    cout << "Enter some integers (q to quit):\n";
    copy(is, eof, back_inserter(numbers));  // 使用 adapter

    ofstream odd("./test_file/odd.txt");
    ofstream even("./test_file/even.txt");
    if (!odd || !even) {
        cerr << "Unable to open output files!\n";
        return -1;
    }

    ostream_iterator<int> os_odd(odd, " ");
    ostream_iterator<int> os_even(even, " ");
    vector<int> num_even;
    vector<int> num_odd;
    
    for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
        if (*iter % 2)
            num_odd.push_back(*iter);
        else
            num_even.push_back(*iter);
    }
    copy(num_odd.begin(), num_odd.end(), os_odd);
    copy(num_even.begin(), num_even.end(), os_even);

    return 0;
}
