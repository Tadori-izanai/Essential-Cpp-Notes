#include <iostream>
#include <vector>
using namespace std;

// 修改基类
class num_sequ {
public:
    virtual ~num_sequ() {}
    virtual const char *what_am_i() const = 0;

    // virtual int elem(int pos) const = 0;
    int elem(int pos) const;
    // virtual ostream & print(ostream &os = cout) const = 0;
    ostream &print(ostream &os = cout) const;

    static int max_elems() {
        // return _max_elems;
        return 64;
    }

    // 新增
    int length() const {
        return _length;
    }
    int beg_pos() const {
        return _beg_pos;
    }

protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;
    // const static int _max_elems = 1024;

    // 新增
    num_sequ(int len, int bp, vector<int> &re)
        : _length(len), _beg_pos(bp), _relems(re) { }
    // 新增 data member
    int _length;
    int _beg_pos;
    vector<int> &_relems;       // 用来指向派生类某个 static vector
};

// 定义派生类
// 此时派生类序列只需编写自身独特部分:
// gen_elems(), what_am_i(), static vector, constructor
class Fibonacci: public num_sequ {
public:
    // Fibonacci(int len = 1, int beg_pos = 1);     // 书上给的什么说唱 constructor ??
    Fibonacci(int len = 1, int beg_pos = 1)         // 修改的 constructor
        : num_sequ(len, beg_pos, _elems) { }

    virtual const char *what_am_i() const {
        return "Fibonacci";
    }
protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};
vector<int> Fibonacci::_elems;


// member function 定义
ostream &operator<<(ostream &os, const num_sequ &ns) {
    return ns.print(os);
}
bool num_sequ::check_integrity(int pos, int size) const {
    if (pos <= 0 || pos > 64) {
        // 同前
        cerr << "! invalid position: " << pos
            << "Cannot honor request\n";
        return false;
    }
    if (pos > size)
        gen_elems(pos);	// 通过 virtual 来调用派生类的 gen_elems() 
    return true;
}

int num_sequ::elem(int pos) const {
    if (!check_integrity(pos, _relems.size()))
        return 0;
    if (pos > _relems.size())
        gen_elems(pos);	// 注意此操作必须加 scope, 写为 Fibonacci::gen_elems(pos)
    	// 此处指明 Fibonacci:: 希望跳过虚函数机制 (使得函数在编译时就完成解析)
    return _relems[pos - 1];
}

void Fibonacci::gen_elems(int pos) const {
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() <= pos) {
        int n1 = _elems[_elems.size() - 1];
        int n2 = _elems[_elems.size() - 2];
        for (int i = _elems.size(); i <= pos; i++) {
            int elem = n1 + n2;
            _elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

ostream &num_sequ::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if (end_pos > _relems.size())	// 检查元素是否足够
        gen_elems(end_pos);
    while (elem_pos < end_pos)
        os << _relems[elem_pos++] << ' ';
    return os;
}

int main() {
    Fibonacci fib;
    cout << "fib: beginning at element 1 for 1 element: " << fib << endl;

    Fibonacci fib2(16);
    cout << "fib2: beginning at element 1 for 16 elements: " << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib3: beginning at element 12 for 8 elements: " << fib3 << endl;


    num_sequ *ps = &fib;
    // ps->gen_elems(64);               // 报错
    // ps->Fibonacci::gen_elems(64);    // 报错
     



    return 0;
}