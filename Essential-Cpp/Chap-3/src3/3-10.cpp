#include <iostream>
#include <fstream>
#include <iterator> // Iterator Inserter, iostream Iterator
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void version1();
void version2();
void version3();

int main()
{
    // version1();
    // version2();
    version3();

    return 0;
}

void version1()
{
    string word;
    vector<string> text;

    while (cin >> word)
        text.push_back(word);
    sort(text.begin(), text.end());

    for (int i = 0; i < text.size(); i++)
        cout << text[i] << ' ';
    cout << endl;
}

void version2() // 使用 iostream Iterator
{
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text)); // 使用 insertation adaptor, 因为为给预留空间.
    sort(text.begin(), text.end());

    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
}

void version3() // 不限于标准 io
{
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");

    if (!in_file || !out_file)
    {
        cerr << "unable to open the necessary files.\n";
        exit(-1);
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));
    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);
}