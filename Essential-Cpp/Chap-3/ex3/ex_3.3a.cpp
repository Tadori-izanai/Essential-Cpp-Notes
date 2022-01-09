/*
    1. 注意可以使用 
        map<string, vector<string>>
    2. 可以使用 typedef
        typedef vector<string> vstring
    3. 从文件中读取, 文件每一行都存有一个 map 信息, 如
        surname child1 child2 child3 ... childN
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<string> vstring;
void populate_map(ifstream &nameFile, map<string, vstring> &families); // 使用 populate_map() 读取文件, 并将内容放到 map 中
void display_map(map<string, vstring> &families, ostream &os);        // display_map 用于显示 map 内容
void query_map(string &family, map<string, vstring> &families);       // 允许用户查询 (若某 family 存在, 就显示姓氏和 children)

int main()
{
    map<string, vstring> families;
    ifstream nameFile("./test_file/fanmily.txt");

    if (!nameFile)
    {
        cerr << "Unable to find families.txt -- Bailing Out!\n";
        return -1;
    }
    populate_map(nameFile, families);
    string family_name;
    while (1){
        cout << "Please enter a family name or q to quit: ";
        cin >> family_name;

        if (family_name == "q")
            break;
        query_map(family_name, families);
    }
    display_map(families, cout);

    return 0;
}

// 使用 populate_map() 读取文件, 并将内容放到 map 中
void populate_map(ifstream &nameFile, map<string, vstring> &families)
{
    string textline; // 存储所读取到的各行
    // getline() 从文件读取一行内容，第三参数指定行末字符 (默认行末字符为换行符)
    while (getline(nameFile, textline)) // gcc 下使用没问题, 从 nameFile 中读取一行, 存储到 textline, 第三参数默认为换行符
    {
        string fam_name;                 // 读取各行第一单词
        vector<string> child;            // 读取各行后几个单词
        string::size_type pos = 0,       // 当前位置
            prev_pos = 0,                // 上一位置
            text_size = textline.size(); // 一行的长度

        // 找出空格来分开单词
        while ((pos = textline.find_first_of(' ', pos)) != string::npos) // npos 是个常数, 表示不存在的位置
        {
            // 计算子字符串终点
            string::size_type end_pos = pos - prev_pos;
            if (!prev_pos)                                     // 零号位的时候
                fam_name = textline.substr(prev_pos, end_pos); // .substr() 用于复制 从 prev_pos 开始的 end_pos 个字符
            else
                child.push_back(textline.substr(prev_pos, end_pos));
            prev_pos = ++pos; // 跳到 ' ' 后方
        }

        // 处理最后一个 child
        if (prev_pos < text_size)
            child.push_back(textline.substr(prev_pos, pos - prev_pos));

        if (!families.count(fam_name)) // 姓氏不在 map 中, 将该姓氏放入 map
            families[fam_name] = child;
        else
            cerr << "Oops, we already have a " << fam_name << " family in our map!\n";
    }
}

// // 尝试仅利用 getline
// void populate_map2(ifstream &nameFile, map<string, vstring> &families) {
//     string textline;
//     while (getline(nameFile, textline)) {
//         string fam_name;
//         vector<string> child;
        

//     }

// }    // 只会写 C-Style, 尝试个鬼 


// display_map 用于显示 map 内容
void display_map(map<string, vstring> &families, ostream &os)
{
    map<string, vstring>::const_iterator it = families.begin(),
                                         end_it = families.end();
    while (it != end_it)
    {
        os << "The " << it->first << " family ";
        if (it->second.empty())
            os << "has no children.\n";
        else
        {
            os << "has " << it->second.size() << " children: ";
            // 遍历 vector it->second
            for (vector<string>::const_iterator iter = it->second.begin(); iter != it->second.end(); iter++)
                os << *iter << " ";
            os << endl;
        }
        it++;
    }
}

// 允许用户查询 (若某 family 存在, 就显示姓氏和 children)
void query_map(string &family, map<string, vstring> &families)
{
    map<string, vstring>::const_iterator it = families.find(family);

    if (it == families.end())
    {
        cout << "Sorry. The " << family << " is not currently entered.\n";
        return;
    }

    cout << "The " << family;
    if (!it->second.size())
        cout << " has no children.\n";
    else
    {
        cout << " has " << it->second.size() << " children: ";
        cout << "has " << it->second.size() << " children: ";
        // 遍历 vector it->second
        for (vector<string>::const_iterator iter = it->second.begin(); iter != it->second.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
}

/*
The  family has 1 children: franz 
The lippman family has 2 children: danny anna 
The mailer family has 2 children: tommy june 
The orlen family has 1 children: orley 
The ranier family has 4 children: alphonse lou robert brodie 
The smith family has 3 children: john henry frieda 
*/

/*
Please enter a family name or q to quit: q
The franz family has no children.
The lippman family has 2 children: danny anna 
The mailer family has 2 children: tommy june 
The orlen family has 1 children: orley 
The ranier family has 4 children: alphonse lou robert brodie 
The smith family has 3 children: john henry frieda 
*/