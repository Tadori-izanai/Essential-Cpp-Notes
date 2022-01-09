#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
public:
    // 任何操作函数如果执行成功, 则会返回 true
    bool push(const string &);
    bool pop(string &elem);     // 会将字符串内容置于 elem 中
    bool peek(string &elem);    // 会将字符串内容置于 elem 中
    bool empty();
    bool full();
    int size() // size() 定义于 class 本身中, 其他 member 仅仅声明
    {
        return _stack.size();
    }
private:
    vector<string> _stack; // 习惯上在 data member 之前加上下划线
    // Stack 的元素都被存储在名为 _stack 的 string vector 中.
};


inline bool
Stack::empty() {
    return _stack.empty();
}

bool 
Stack::pop(string &elem) {
    if (empty())
        return false;
    // 获取末尾元素
    elem = _stack.back();   // back() 返回 vector 中末尾元素的引用
    // 删除末尾元素
    _stack.pop_back();      // 删除 vector 中的最后一个元素
    return true;
}

inline bool Stack::full() {
    return _stack.size() == _stack.max_size(); // 和底层 vector 的 max_size() 做比较
}

bool Stack::peek(string &elem) {
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full())
        return false;
    _stack.push_back(elem); // 未满前提下, 将元素插入
    return true;
}



// 定义和并使用 Stack class obj
void fill_stack(Stack &stack, istream &is = cin) {
    string str;
    while (is >> str && !stack.full())
        stack.push(str);

    cout << "Read in " << stack.size() << " elements\n";
}