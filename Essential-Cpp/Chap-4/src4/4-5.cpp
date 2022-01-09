#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Tri {
public:
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
    

private:
    int _length;    // 元素个数
    int _beg_pos;   // 起始位置
    mutable int _next;  // 下一个迭代目标

    // static data member
    static const int _max_elems = 1024;
    static vector<int> _elems;
};

// static data member 的定义
vector<int> Tri::_elems;

// constructor 定义
Tri::Tri(const Tri &rhs)
    : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) // 使用成员初始化列表
{ }
Tri::Tri(int len, int bp) {
    int arri[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < 12; i++)
        _elems.push_back(arri[i]);    

    _length = len;
    _beg_pos = bp;
}

// static member function 定义
void Tri::gen_elems_to_value(int value) {
    int i = _elems.size();
    if (!i) {
        _elems.push_back(1);
        i = 1;
    }
    while (_elems[i - 1] < value && i < _max_elems) {
        // cout << "elems to value: " << i * (i + 1) / 2 << endl;   // 调试时使用
        i++;
        _elems.push_back(i * (i + 1) / 2);   
    }
    if (i == _max_elems)
        cerr << "Triangular Sequence: oops: value too large " << value << " -- exceeds max size of " << _max_elems << endl;
}
void Tri::gen_elements(int length) {
    if (length < 0 || length > _max_elems) {
        cerr << "Program error\n";
        return ;
    }
    if (_elems.size() < length) {
        int i = _elems.size() ? _elems.size() + 1: 1;
        for (; i <= length; i++)
            _elems.push_back(i * (i + 1) / 2);
    }
}
bool Tri::is_elem(int value) {
    if (!_elems.size() || _elems[_elems.size() - 1] < value)
        gen_elems_to_value(value);  // Triangular 序列升序, 当前最大值小于所给的 value 时, 扩充
    
    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = find(_elems.begin(), end_it, value);
    return (found_it != end_it);
}



// 测试
int main() {
    char ch;
    bool more = true;

    while (more) {
        cout << "Enter value: ";
        int ival;
        cin >> ival;

        bool is_elem = Tri::is_elem(ival);
        cout << ival
            << (is_elem ? " is " : " is not ")
            << "an elements in the Triangular series.\n"
            << "Another value? (y/n) ";
        cin >> ch;
        if ('n' == ch || 'N' == ch)
            more = false;
    }
    return 0;
}