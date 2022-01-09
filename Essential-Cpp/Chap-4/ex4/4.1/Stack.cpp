// Stack 的 non-inline member function 的定义
#include "Stack.h"
#include <algorithm>    // 使用泛型算法 find 和 count

bool Stack::pop(string &elem) {
    if (empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
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
    _stack.push_back(elem);
    return true;
}

// 以下 4.2 新增
bool Stack::find(const string &elem) {
    // 在 find 前使用 ::, 来使用全局的 find() 函数, 来作区分
    if (::find(_stack.begin(), _stack.end(), elem) == _stack.end())
        return false;
    else
        return true;
}

int Stack::count(const string &elem) {
    return ::count(_stack.begin(), _stack.end(), elem); // 同样使用 ::    
}