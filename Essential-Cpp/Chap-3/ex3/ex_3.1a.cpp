#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void init_exclusive_set(set<string> &);
void process_file(map<string, int> &, const set<string> &, ifstream &);
void user_query(map<string, int> &);
// void user_query(const map<string, int> &);
void display_word_count(map<string, int> &, ofstream &);
// void display_word_count(const map<string, int> &, ofstream &);
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
    init_exclusive_set(exclude_set);

    map<string, int> word_count;
    process_file(word_count, exclude_set, ifile);
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

void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile)
{
    string word;
    while (ifile >> word)
    {
        if (exclude_set.count(word)) // !! 注意检查 set 中某元素是否存在, 可以使用 count() !!
            continue;
        word_count[word]++;
    }
}

void user_qeury(map<string, int> &word_map)
{
    string search_word;
    cout << "Enter a word to search (q to quit): ";
    cin >> search_word;
    while (search_word.size() && search_word != "q")
    {
        map<string, int>::const_iterator it;
        if ((it = word_map.find(search_word)) != word_map.end())
            cout << it->first << " occurs " << it->second << " times.\n";
        else
            cout << " was not found in text.\n";
        cout << "\nAnother search? (q to quit): ";
        cin >> search_word;
    }
}

void user_query(map<string, int> &word_map)
// void user_query(const map<string, int> &word_map)
{
    string search_word;
    cout << "Enter a word to search (q to quit): ";
    cin >> search_word;
    while (search_word.size() && search_word != "q")
    {
        map<string, int>::const_iterator it;
        if ((it = word_map.find(search_word)) != word_map.end())
            cout << it->first << " occurs " << it->second << " times.\n";
        else
            cout << search_word << " was not found in text.\n";
        cout << "\nAnother search? (q to quit): ";
        cin >> search_word;
    }
}

void display_word_count(map<string, int> &word_map, ofstream &os)
// void display_word_count(const map<string, int> &word_map, ofstream &os)
{
    map<string, int>::iterator iter = word_map.begin(),
                               end_it = word_map.end();
    while (iter != end_it)
    {
        os << iter->first << " ( " << iter->second << " ) " << endl;
        iter++;
    }
    os << endl;
}