#include <iostream>
using namespace std;

class LibMat {
public:
    LibMat() {
        cout << "LibMat::LibMat() default constructor!\n";
    }
    virtual ~LibMat() {
        cout << "LibMat::~LibMat() destructor!\n";
    }	// 虚函数
    virtual void print() const {
        cout << "LibMat::print() -- I am a LibMat object!\n";
    }	// 虚函数
};

void print(const LibMat &mat) {
    cout << "in global print(): about to print mat.print()\n";
    mat.print();    // 依据 mat 实际所指对象, 解析该执行哪一个 print() member function.
}

int main() {
    cout << "\n" <<"Creating a LibMat object to print()\n";
    LibMat libmat;
    print(libmat);

    return 0;
}

/*  跟踪的结果
Creating a LibMat object to print()
LibMat::LibMat() default constructor!               // 构造 LibMat libmat
in global print(): about to print mat.print()       // 处理 print(libmat)
LibMat::print() -- I am a LibMat object!            
LibMat::~LibMat() destructor!                       // 析构 LibMat
*/