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
    } // Book 中的 print() 覆盖了 (override) LibMat 的 print()
    const string &title() const {
        return _title;
    }
    const string &author() const {
        return _author;
    }	// title() and author() are both non-virtual inline function
protected:
    string _author;
    string _title;
};

class AudioBook: public Book {
public:
    AudioBook(const string &title, const string &author, const string &narrator)
        : Book(title, author), _narrator(narrator)                  // 注意此处的写法
        // : _title(title), _author(author), _narrator(narrator)    // 此写法有误 !
    {
     	cout << "AudioBook::AudioBook(" << _title << ", " << _author
            << ", " << _narrator << ") constructor\n";
    }
    ~AudioBook() {
        cout << "AudioBook::~AudioBook() destructor!\n";
    }
    virtual void print() const {
        cout << "AudioBook::print() -- I am an AudioBook object!\n"
            << "My title is: " << _title << "\n"
            << "My authir is: " << _author << "\n"
            << "My narrator is: " << _narrator << endl;
    }
    const string &narrator() const {
        return _narrator;
    }
protected:
    string _narrator;
};

void print(const LibMat &mat) {
    cout << "in global print(): about to print mat.print()\n";
    mat.print();    // 依据 mat 实际所指对象, 解析该执行哪一个 print() member function.
}

int main() {
    cout << "Creating an AudioBook object to print()\n";
    AudioBook ab("Man Without Qualities", "Robert Musil", "Kenneth Meyer");
    print(ab);

    // 透明
    cout << endl;
    AudioBook ab2("Mason and Dixon", "Tomas Pynchon", "Edwin Leonard");
    cout << "The title is " << ab2.title() << '\n'
        << "The author is " << ab2.author() << '\n'
        << "The narrator is " << ab2.narrator() << endl;

    return 0;
}

/* 跟踪的结果
Creating an AudioBook object to print()
LibMat::LibMat() default constructor!                                                   // 构造 AudioBook ab
Book::Book(Man Without Qualities, Robert Musil) constructor                             //
AudioBook::AudioBook(Man Without Qualities, Robert Musil, Kenneth Meyer) constructor    // 
in global print(): about to print mat.print()                                   // print(ab) 的解析过程
AudioBook::print() -- I am an AudioBook object!                                 //
My title is: Man Without Qualities                                              //
My authir is: Robert Musil                                                      //
My narrator is: Kenneth Meyer                                                   //
AudioBook::~AudioBook() destructor!                                                 // 析构 AudioBook ab
Book::_Book() destructor!                                                           //
LibMat::~LibMat() destructor!                                                       //
*/