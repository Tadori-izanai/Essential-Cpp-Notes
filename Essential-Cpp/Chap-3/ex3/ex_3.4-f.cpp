#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// void get_number(vector<int> &, _LIBCPP_FUNC_VIS istream is);
void get_number(vector<int> &, istream &is);        // 此处要加上 & 不然卒 !!!!!!!!!!!!!!!
int main()
{
    // istream_iterator<int> is(cin);
    // istream_iterator<int> eof;
    vector<int> numbers;

    // cout << "Enter some positive integers (q to quit):\n";
    // copy(is, eof, back_inserter(numbers));  // 使用 adapter
    get_number(numbers, cin);

    ofstream odd("./test_file/odd.txt");
    ofstream even("./test_file/even.txt");
    if (!odd || !even) {
        cerr << "Unable to open output files -- Bailing out!\n";
        return -1;
    }

    ostream_iterator<int> os_odd(odd, " ");
    ostream_iterator<int> os_even(even, " ");
    vector<int> num_even;
    vector<int> num_odd;
    
    for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        if (*iter % 2)
            num_odd.push_back(*iter);
        else
            num_even.push_back(*iter);
    }
    copy(num_odd.begin(), num_odd.end(), os_odd);
    copy(num_even.begin(), num_even.end(), os_even);

    return 0;
}

void get_number(vector<int> &numbers, istream &is){
    istream_iterator<int> iit(is);
    istream_iterator<int> eof;

    cout << "Enter some positive integers (q to quit):\n";
    copy(iit, eof, back_inserter(numbers));  // 使用 adapter
}

// void get_number(vector<int> &numbers, _LIBCPP_FUNC_VIS istream is){
//     istream_iterator<int> iit(is);
//     istream_iterator<int> eof;

//     cout << "Enter some positive integers (q to quit):\n";
//     copy(iit, eof, back_inserter(numbers));  // 使用 adapter
// }