#include <iostream>
#include <vector>
using namespace std;

// 抽象基类的定义
class num_sequ {
public:
    virtual ~num_sequ() {}; // 此类无 non-static data member, 设计 constructor 无 ee, 但是要提供析构函数
    virtual int elem(int pos) const = 0;            // 返回 pos 位置上的元素的值
    virtual const char *what_am_i() const = 0;      // 返回确切的数列类型
    static int max_elems() {						// 返回所支持的最大位置值 (不需要 virtual)
        return _max_elems;
    }
    virtual ostream & print(ostream &os = cout) const = 0;

protected:    // 派生类必须调用的
    virtual void gen_elems(int pos) const = 0;		// 与派生类型相关, 定为 virtual
    bool check_integrity(int pos) const;			// 对所有派生类均适用, 不需要 virtual
    const static int _max_elems = 1024;
};

// 提供 check_integrity 以及 output 运算符重载
bool num_sequ::check_integrity(int pos) const {
    if (pos <= 0 || pos > _max_elems) {
        cerr << "! invalid position: " << pos
            << "Cannot honor request\n";
        return false;
    }
    return true;
}
ostream &operator<<(ostream &os, const num_sequ &ns) {
    return ns.print(os);
}


// 派生类的定义
class Fibonacci: public num_sequ {
public:
    Fibonacci(int len = 1, int beg_pos = 1)
        : _length(len), _beg_pos(beg_pos) { }
    virtual int elem(int pos) const;			// 返回 pos 位置上的元素
    virtual const char *what_am_i() const {
        return "Fibonacci";
    }
    virtual ostream &print(ostream &os = cout) const;	// 将所有元素写入 os
    int length() const {
        return _length;
    }
    int beg_pos() const {
        return _beg_pos;
    }
protected:
    virtual void gen_elems(int pos) const;	// 产生直到 pos 位置的所有元素
    int _length;
    int _beg_pos;
    static vector<int> _elems;
    bool check_integrity(int pos) const;        //////////////
};
vector<int> Fibonacci::_elems;      // 给出 non-const static member 的定义


int Fibonacci::elem(int pos) const {
    if (!check_integrity(pos))
        return 0;
    if (pos > _elems.size())
        Fibonacci::gen_elems(pos);	// 注意此操作必须加 scope, 写为 Fibonacci::gen_elems(pos)
    	// 此处指明 Fibonacci:: 希望跳过虚函数机制 (使得函数在编译时就完成解析)
    return _elems[pos - 1];
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

ostream &Fibonacci::print(ostream &os) const {
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;
    if (end_pos > _elems.size())	// 检查元素是否足够
        Fibonacci::gen_elems(end_pos);
    while (elem_pos < end_pos)
        os << _elems[elem_pos++] << ' ';
    return os;
}

inline bool Fibonacci::check_integrity(int pos) const {
    if (!num_sequ::check_integrity(pos))	// 不加 :: 则解析为派生类自生的 check_integrity()
        return false;
    if (pos > _elems.size())
        Fibonacci::gen_elems(pos);
    return true;
}





int main() {
    Fibonacci fib;
    cout << "fib: beginning at element 1 for 1 element: " << fib << endl;

    Fibonacci fib2(16);
    cout << "fib2: beginning at element 1 for 16 elements: " << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib3: beginning at element 12 for 8 elements: " << fib3 << endl;

    return 0;
}