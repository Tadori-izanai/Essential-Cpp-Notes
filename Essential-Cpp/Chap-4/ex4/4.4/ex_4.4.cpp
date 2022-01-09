#include <iostream>
#include "UserProfile.h"
using namespace std;

// 重载 <<
ostream &operator<<(ostream &os, const UserProfile &rhs) {
    os << rhs.login() << ' '
        << rhs.level() << ' '
        << rhs.login_count() << ' '
        << rhs.guess_count() << ' '
        << rhs.guess_correct() << ' '
        << rhs.guess_average() << endl;
    return os;
}

// static member data 定义
map<string, UserProfile::uLevel> UserProfile::_level_map;
// static member function 定义
void UserProfile::init_level_map() {
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}

// 重载 >>
istream &operator>>(istream &is, UserProfile &rhs) {
    string login, level;
    is >> login >> level;
    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;
    rhs.reset_login(login);
    rhs.reset_level(level);

    rhs.reset_login_count(lcount);
    rhs.reset_guess_count(gcount);
    rhs.reset_guess_correct(gcorrect);

    return is;
}


// 测试
int main() {
    UserProfile anon;
    cout << anon;   // 测试 operator<<

    UserProfile anna("AnnaL", UserProfile::Guru);   // 注意使用 enum 也要 class scope 界定
    cout << anna;
    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();
    cout << anna;

    cin >> anon;        // 测试 operator<<
    cout << anon;

    return 0;
}


/*
guest Beginner 1 0 0 0
AnnaL Guru 1 0 0 0
AnnaL Guru 2 27 25 92.5926
robin Intermediate 1 8 3
robin Intermediate 1 8 3 37.5
*/