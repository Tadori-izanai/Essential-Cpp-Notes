#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string elemType;

class Stack {
public:
    virtual ~Stack() {}
    virtual bool pop(elemType &) = 0;
    virtual bool push (const elemType &) = 0;
    virtual bool peek(int index, elemType &) = 0;

    virtual int top() const = 0;
    virtual int size() const = 0;

    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print(ostream & = cout) const = 0;     // 注意 & 和 = 之间需要有空格
};


// 实现一个栈
class LIFO_Stack : public Stack {
public:
    // constructor
    LIFO_Stack(int capacity = 0) : _top(0) {
        if (capacity)
            _stack.reserve(capacity);
    }

    int size() const {
        return _stack.size();
    }
    bool empty() const {
        return ! _top;          // _top 为 0 时, 空栈
    }
    bool full() const {
        return (size() >= _stack.max_size());   // 4611686018427387903
    }
    int top() const {
        return _top;
    }
    void print(ostream &os = cout) const;

    bool pop(elemType &elem);               // 删除末尾元素
    bool push(const elemType &elem);        
    // bool peek(int, elemType &) {
    //     return false;               // ???
    // }
    bool peek(int index, elemType &elem) {      // 引入 Peekback_Stack
        if (empty())
            return false;
        if (index < 0 || index >= size())
            return false;

        elem = _stack[index];
        return true;
    }

private:
    vector<elemType> _stack;
    int _top;
};

