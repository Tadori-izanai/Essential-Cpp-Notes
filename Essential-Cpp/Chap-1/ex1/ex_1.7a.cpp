#include <iostream>
#include <fstream>
#include <algorithm> // 有泛型编程算法 sort()
#include <string>
#include <vector>

using namespace std;
int main()
{
    // 打开文件
    ifstream in_file("./test_file/mydoc.txt"); // r 模式打开文件
    if (!in_file)
    {
        cerr << "Unable to open the input file\n";
        return -1; // 退出
    }

    ofstream out_file("./test_file/sort.txt"); // w 模式打开文件
    if (!out_file)
    {
        cerr << "Unable to open the output file\n";
        return -2; // 退出
    }

    // 存入 vector
    string word;
    vector<string> text;

    while (in_file >> word) // input 运算符一次输入的是一个 "单词"
        text.push_back(word);

    // 排序
    cout << "Unsorted text: \n";
    for (int i = 0; i < text.size(); i++)
        cout << text[i] << ' ';
    cout << endl;

    sort(text.begin(), text.end());     // 使用 sort() 排序

    // 输出到文件
    out_file << "Sorted text: \n";
    for (int i = 0; i < text.size(); i++)
        out_file << text[i] << ' ';
    out_file << endl;

    return 0;
}