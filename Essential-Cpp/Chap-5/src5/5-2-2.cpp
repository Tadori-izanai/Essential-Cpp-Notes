#include <iostream>
#include <string>
using namespace std;

class LibMat {
public:
    LibMat() {
        cout <<  "LibMat::LibMat() default constructor!\n";
    }
    virtual ~LibMat() {
        cout << "LibMat::~LibMat() destructor!\n";
    }	// 虚函数
    virtual void print() const {
        cout << "LibMat::print() -- I am a LibMat object!\n";
    }	// 虚函数
};

// 派生
class Book: public LibMat {
public:
    Book(const string &title, const string &author) : _title(title), _author(author) {
        cout << "Book::Book(" << _title << ", " << _author << ") constructor\n";
    }
    virtual ~Book() {
        cout << "Book::_Book() destructor!\n";
    }
    virtual void print() const {
        cout << "Book::print -- I am a Book object!\n"
            << "My title is: " << _title << "\n"
            << "My author is: " << _author << endl;
    }
    const string &title() const {
        return _title;
    }
    const string &author() const {
        return _author;
    }
protected:
    string _author;
    string _title;
};

// non-member function
void print(const LibMat &mat) {
    cout << "in global print(): about to print mat.print()\n";
    mat.print();    // 依据 mat 实际所指对象, 解析该执行哪一个 print() member function.
}

int main() {
    cout << "\n" << "Creating a Book object to print()\n";
    Book b("The Castle", "Franz Kafka");
    print(b);

    return 0;
}
    
/*
Creating a Book object to print()
LibMat::LibMat() default constructor!                   // 构造 Book b
Book::Book(The Castle, Franz Kafka) constructor         // 
in global print(): about to print mat.print()           // 处理 print(b)
Book::print -- I am a Book object!                      //
My title is: The Castle                                 //
My author is: Franz Kafka                               //
Book::_Book() destructor!                               // 析构 Book b
LibMat::~LibMat() destructor!                           //
*/