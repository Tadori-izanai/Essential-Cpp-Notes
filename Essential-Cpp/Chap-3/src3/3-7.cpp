#include <iostream>
#include <map>
#include <string>
using namespace std;

void test1()
{
    map<string, int> words;
    int count = 0;
    words["vermeer"] = 0;

    if (!(count = words["vermeer"]))           // vermeer 不存在于 words map 中
        cout << "vermeer is not $\\exists$\n"; // ???
}

void test2()
{
    map<string, int> words;
    words["vermeer"] = 1;

    int count = 0;
    map<string, int>::iterator it = words.find("vermeer");
    if (it != words.end())
        count = it->second;
    cout << count << endl;
}

void test3()
{
    map<string, int> words;
    words["vermeer"] = 2;

    int count = 0;
    string search_word("vermeeer");
    if (words.count(search_word)) // 存在
        count = words[search_word];
    cout << count << endl;
}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}