#include <iostream>
#include <vector>
#include <algorithm>
#include "Tri.h"
using namespace std;

// static data member 的定义
vector<int> Tri::_elems;

// constructor 定义
Tri::Tri(const Tri &rhs)
    : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) // 使用成员初始化列表
{ }
Tri::Tri(int len, int bp) {
    // int arri[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // for (int i = 0; i < 12; i++)
    //     _elems.push_back(arri[i]);    
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
        return;
    }
    if (_elems.size() < length) {
        int i = _elems.size() ? _elems.size() + 1 : 1;
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
    Tri tri(20);
    Tri::iterator it = tri.begin();
    Tri::iterator end_it = tri.end();

    cout << "Triangular Series of " << tri.length() << " elements\n";
    // cout << tri << endl;
    while (it != end_it){
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
    return 0;
}