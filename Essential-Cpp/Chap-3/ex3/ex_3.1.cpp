#include <iostream>
#include <set>
#include <string>
#include <map>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

void init_exclusive_set(set<string> &);
void process_file(map<string, int> &, const set<string> &, ifstream &);
void user_query(map<string, int> &);
void display_word_count(map<string, int> &, ofstream &);
int main()
{
    ifstream ifile("./test_file/column.txt");
    ofstream ofile("./test_file/column.map");
    if (!ifile || !ofile)
    {
        cerr << "Unbale to open file -- bailing out!\n";
        return -1;
    }
    set<string> exclude_set;
    init_exclusive_set(exclude_set); // 获取要排除的字眼

    map<string, int> word_count;
    process_file(word_count, exclude_set, ifile); // 将各字眼存入 word_count (有排除)
    user_query(word_count);
    display_word_count(word_count, ofile);

    return 0;
}

void init_exclusive_set(set<string> &init_set)
{
    static string _words[25] = {
        "the", "and", " but", "that", "are", "been", "can", "a",
        "could", "did", "for", "of", "had", "have", "him", "his",
        "her", "its", "is", "were", " which", " when", "with", "would"};
    init_set.insert(_words, _words + 25);
}

// void process_file(map<string, int> &wc, const set<string> &init_set, ifstream &inf)
// {
//     istream_iterator<string> is(inf);
//     istream_iterator<string> eof;

//     vector<string> words;
//     copy(is, eof, back_inserter(words)); // 将所有单词存入 vector words
//     for (int i = 0; i < words.size(); i++)
//         wc[words[i]]++;
//     for (set<string>::iterator iter = init_set.begin(); iter != init_set.end(); iter++)
//     {
//         if (wc.find(*iter) != wc.end())
//             wc.erase(*iter);
//     }
// }

void process_file(map<string, int> &wc, const set<string> &init_set, ifstream &inf)
{
    string w;

    while (inf >> w)
    {
        if (init_set.count(w))  // 使用 count 来查看 set 中是否存在元素
            continue;
        wc[w]++;
    }
}

void user_query(map<string, int> &wc) // 需要去掉 const ??????
{
    string check;
    cout << "Enter a word to be checked (enter # to quit): ";
    while (cin >> check && check != string("#"))
    {
        if (wc.count(check))
            cout << "Word \'" << check << "\' appears " << wc[check] << " times.\n";
        else
            cout << "Word \'" << check << "\' doesn't exist\n";

        cout << "\nEnter a word to be checked (enter # to quit): ";
    }
}

void display_word_count(map<string, int> &wc, ofstream &ofile) // 去掉了 const 才不报错 ???????
{
    int index = 0;
    cout << "\nResults are as below:\n";
    for (map<string, int>::iterator iter = wc.begin(); iter != wc.end(); iter++)
    {
        cout << iter->first << ": " << iter->second << "  ";
        ofile << iter->first << ": " << iter->second << "  ";
        if (0 == ++index % 5)
        {
            cout << endl;
            ofile << endl;
        }
    }
}