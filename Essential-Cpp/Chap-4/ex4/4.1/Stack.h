// 类定义的头文件
#include <string>
#include <vector>
using namespace std;

class Stack {
public:
    bool push (const string &);
    bool pop(string &elem);
    bool peek(string &elem);
    // 定义在主体内的 inline function:
    bool empty() const {
        return _stack.empty();
    }
    bool full() const {
        return _stack.size() == _stack.max_size();
    }
    int size() const {
        return _stack.size();
    }

    // 4.2 新增
    bool find(const string &);
    int count(const string &);
private:
    vector<string> _stack;
};