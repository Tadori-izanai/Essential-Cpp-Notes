#include <iostream>
using namespace std;

class num_sequ {
public:
    virtual const char *what_am_i() const {
        return "num_sequ\n";
    }
};
class Fibonacci: public num_sequ {
public:
    virtual const char *what_am_i() {
        return "Fibonacci\n";
    }
};

int main()
{
    Fibonacci b;
    num_sequ p;

    // 想要输出的是: 两个 Fibonacci
    num_sequ *pp = &b;
    cout << pp->what_am_i();    
    cout << b.what_am_i();

    int *pi = new int(1024);
    cout << *pi << endl;


    return 0;
}

/*
实际输出:
num_sequ
Fibonacci
*/