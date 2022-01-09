#include <iostream>
#include <vector>
using namespace std;

// 先给出 Tri_iterator 的定义, 让 Tri 可将其声明为 friend
class Tri_iterator {
public:
    // constructor
    Tri_iterator(int index): _index(index - 1) {
    }
    bool operator==(const Tri_iterator &) const;
    bool operator!=(const Tri_iterator &) const; // 二元的绑定前面的 obj	()
    int operator*() const;
    Tri_iterator &operator++();		// 前置 prefix
    Tri_iterator operator++(int);	// 后置 postfix
private:
    void check_integrity() const;
    int _index;
};

class Tri {
    friend class Tri_iterator;
public:
    typedef Tri_iterator iterator;	// 可以让用户不必知道 iterator class 的实际名称
    // constructor
    Tri(int len = 1, int bp = 1);   // default constructor
    Tri(const Tri &);
    // const member function
    int length() const {
        return _length;
    }
    int beg_pos() const {
        return _beg_pos;
    }
    int elem(int pos) const;
    bool next(int &val) const;
    void next_reset() const {
        _next = _beg_pos - 1;
    }
    // static member function
    static bool is_elem(int);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length, int beg_pos, ostream &os = cout);

    Tri_iterator begin() const {
        return Tri_iterator(_beg_pos);          // constructor 返回值 ???
    }
    Tri_iterator end() const {
        return Tri_iterator(_beg_pos + _length);
    }
    
    // 4-10.cpp 所需, 考虑函数重载
    void length(int val) {
        _length = val;
    }
    void beg_pos(int val) {
        _beg_pos = val;
    }

private:
    int _length;    // 元素个数
    int _beg_pos;   // 起始位置
    mutable int _next;  // 下一个迭代目标

    // static data member
    static const int _max_elems = 1024;
    static vector<int> _elems;
};


// iterator 的定义
// 提供 == 定义
inline bool Tri_iterator::operator==(const Tri_iterator &rhs) const {
    return (_index == rhs._index);
}
// 提供 != 定义
inline bool Tri_iterator::operator!=(const Tri_iterator &rhs) const {
    return !(*this == rhs);
}
// 提供 * 定义
inline int Tri_iterator::operator*() const {
    check_integrity();
    return Tri::_elems[_index];
}
// 提供 ++ 定义
inline Tri_iterator &Tri_iterator::operator++() {
    ++_index;
    check_integrity();
    return *this;
} // 返回类型有 reference ???
inline Tri_iterator Tri_iterator::operator++(int) {
    Tri_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
} // 返回类型无 reference ???

inline void Tri_iterator::check_integrity() const {
    // if (_index >= Tri::_max_elems)
    //     throw iterator_overflow();       // 暂时不实现 throw
    if (_index >= Tri::_elems.size())
        Tri::gen_elements(_index + 1);
}