#include <iostream>
#include <vector>
using namespace std;

class LessThan {
public:
    LessThan(int val): _val(val) {
    }
    int comp_val() const {
        return _val;				// 基值的读取
    }
    void comp_val(int nval) {
        _val = nval;				// 基值的写入
    }
    bool operator()(int _value) const;
private:
    int _val;
};
// function call 运算符的实现
inline bool LessThan::operator()(int value) const {
    return (value < _val);
}


int count_less_than(const vector<int> &vec, int comp);
void print_less_than(const vector<int> &vec, int comp, ostream &os = cout);
int main()
{
    int ia[16] = {
        17, 12, 44, 9, 18, 45, 6, 14, 23, 67, 9, 0, 27, 55, 8, 16
    };
    vector<int> vec(ia, ia + 16);
    const int comp_val = 20;

    cout << "Number of elements less than " << comp_val << " are "
        << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);

    return 0;
}

int count_less_than(const vector<int> &vec, const int comp) {
    LessThan lt(comp);
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (lt(vec[i]))
            count++;
    }
    return count;
}

void print_less_than(const vector<int> &vec, const int comp, ostream &os) {
    LessThan lt(comp);
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();
    os << "elems less than " << lt.comp_val() << endl;
    while ((iter = find_if(iter, it_end, lt)) != it_end) {
        os << *iter << ' ';
        iter++;
    }
}