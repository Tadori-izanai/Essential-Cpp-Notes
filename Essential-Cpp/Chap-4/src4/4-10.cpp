#include <iostream>
#include "Tri10.h"
using namespace std;

vector<int> Tri::_elems;    // 注意要给出 static member 的定义 !   (non-const( )

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

ostream &operator<<(ostream &os, const Tri &rhs) {
    os << "(" << rhs.beg_pos() << ", " << rhs.length() << ") ";
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}

istream &operator>>(istream &is, Tri &rhs) {
    char ch1, ch2;
    int bp, len;
    // 这里假设输入是 (3, 6) 6 10 15 21 28 36
    is >> ch1 >> bp >> ch2 >> len;
    // 设定 rhs 的三个 data member
    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.next_reset();   // 归位
    return is;
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

void Tri::display(int length, int beg_pos, ostream &os) {
    gen_elements(beg_pos + length - 1);
    for (int i = beg_pos - 1; i < beg_pos + length - 1; i++)
       cout << _elems[i] << ' ';
    cout << endl;
}

int main()
{
    Tri tri(6, 3);
    cout << tri << '\n';
    Tri tri2;
    cin >> tri2;
    cout << tri2;    

    return 0;
}