#include <iostream>
#include <vector>
// #include <algorithm>
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

    // // non-const member function
    // bool next(int &val);
    // void next_reset() {
    //     _next = _beg_pos - 1;
    // }

    // 现将其声明为 const
    bool next(int &val) const;
    void next_reset() const {
        _next = _beg_pos - 1;
    }

    void display();
    static void test();

private:
    int _length;    // 元素个数
    int _beg_pos;   // 起始位置
    // int _next;      // 下一个迭代目标
    mutable int _next;      // 现在声明为 mutable

    // static data member
    // static vector<int> _elems;
    static vector<int> _test;
    vector<int> _elems; // 暂时不使用 static
};
void Tri::test() {
    // Tri::_test.push_back(0);
}

// constructor
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

void Tri::display() {
    cout << "(" << beg_pos() << ", " << length() << ") ";
    for (int i = beg_pos() - 1; i < beg_pos() + length() - 1; i++)
        cout << _elems[i] << " ";
}

bool Tri::next(int &val) const {
    if (_next < (beg_pos() + length() - 1)) {
        val = _elems[_next];
        _next++;
        return true;
    }
    else
        return false;
}



// 测试
int sum(const Tri &trian);
int main() {
    Tri tri(4);
    tri.display();      // 书中直接 cout << tri ???? --- 重载了 << 运算符
    cout << " -- sum of elements: " << sum(tri) << endl;

    Tri tri2(4, 3);
    tri2.display();
    cout << " -- sum of elements: " << sum(tri2) << endl;

    Tri tri3(4, 8);
    tri3.display();
    cout << " -- sum of elements: " << sum(tri3) << endl;

    return 0;
}

int sum(const Tri &trian) {
    if (!trian.length())
        return 0;
    int val;
    int sum = 0;
    trian.next_reset();
    while (trian.next(val))
        sum += val;
    return sum;
}