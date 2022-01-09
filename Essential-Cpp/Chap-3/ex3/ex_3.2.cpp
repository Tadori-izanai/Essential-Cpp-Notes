/*
    1. function object 的定义:
        
        ```cpp
        class lessThan {
        public:
            bool operator()(const string &s1, const string &s2) {
                return (s1.size() < s2.size());
            }
        };
        ```

    2. 上述 function object 的调用方式:

        ```cpp
        sort(text.begin(), text.end(), lessThan());
        ```
*/

// #define DEBUG
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm> // sort()
using namespace std;

// class lessThan
// {
// public:
//     bool opeartor(const string &s1, const string &s2)
//     {
//         return (s1.size() < s2.size());
//     }
// };

bool lessThan(const string &s1, const string &s2) // 不会定义和使用 function object, 则自定义一个函数
{
    return (s1.size() < s2.size());
}

int main()
{
    ifstream ifile("./test_file/document.txt");
    ofstream ofile("./test_file/document.sort");
    if (!ifile || !ofile)
    {
        cerr << "Unable to open file -- bailing out!\n";
        return -1;
    }

    vector<string> text;
    string w;
    while (ifile >> w)
        text.push_back(w);

#ifdef DEBUG
    cout << text[0];
#endif // DEBUG

    sort(text.begin(), text.end());           // 可先按照字母顺序排一遍
    sort(text.begin(), text.end(), lessThan); // lessThan 无 () (传入的是函数指针(), 是 function object)

#ifdef DEBUG
    cout << text[0];
#endif // DEBUG

    ostream_iterator<string> os(ofile, "\n");
    copy(text.begin(), text.end(), os); // 利用 iotsream iterator 输出

#ifdef DEBUG
    ostream_iterator<string> o1s(cout, "\n");
    copy(text.begin(), text.end(), o1s); // 利用 iotsream iterator 输出
#endif                                   // DEBUG

    return 0;
}