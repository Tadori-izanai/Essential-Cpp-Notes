#include <iostream>
#include <map>
#include <string>
// #include <cstdlib>   // _itoa()
using namespace std;

// gcc clang 无法 _itoa, 造一个
void my_itoa(int value, std::string& buf, int base){
	int i = 30;
	buf = "";
	for(; value && i ; --i, value /= base) 
        buf = "0123456789abcdef"[value % base] + buf;
}

class UserProfile {
public:
    enum uLevel {Beginner, Intermediate, Advanced, Guru};    // 给出 4 个等级
    // constructor
    UserProfile(string login, uLevel = Beginner);    // 第二个参数属于 uLevel 类, 有默认值 0
    UserProfile();
    // (default memberwise initializatoin 和 default memberwise copy 已足够)

    // 重载 operator
    bool operator==(const UserProfile &);
    bool operator!=(const UserProfile &rhs);

    // 数据读取
    string login() const {
        return _login;
    }
    string user_name() const {
        return _user_name;
    }
    int login_count() const {
        return _tiems_logged;
    }
    int guess_count() const {
        return _guesses;
    }
    int guess_correct() const {
        return _correct_guesses;
    }
    double guess_average() const;
    string level() const;           // 返回等级 (字符串)

    // 写入数据
    void reset_login(const string &val) {
        _login = val;
    }
    void user_name(const string &val) {
        _user_name = val;
    }
    void reset_level(const string &);       // 通过字符串来给等级
    void reset_level(uLevel newlevel) {
        _user_level = newlevel;             // 通过 int 值 (或 enum 值) 写入
    }

    void reset_login_count(int val) {
        _tiems_logged = val;
    }
    void reset_guess_count(int val) {
        _guesses = val;
    }
    void reset_guess_correct(int val) {
        _correct_guesses = val;
    }
    // 加次数
    void bump_login_count(int cnt = 1) {
        _tiems_logged += cnt;
    }
    void bump_guess_count(int cnt = 1) {
        _guesses += cnt;
    }
    void bump_guess_correct(int cnt = 1) {
        _correct_guesses +=cnt;
    }

private:
    string _login;          // 记录
    string _user_name;      // 实际姓名
    int _tiems_logged;      // 登入次数
    int _guesses;           // 猜过次数
    int _correct_guesses;   // 猜对次数
    uLevel _user_level;     // 等级
    // static member data
    static map<string, uLevel> _level_map;
    // static member function
    static void init_level_map();
    static string guest_login();
};

inline double UserProfile::guess_average() const {
    return (_guesses ? (double(_correct_guesses) / double(_guesses) * 100) : 0.);
}
// constructor
inline UserProfile::UserProfile(string login, uLevel level)
    : _login(login), _user_level(level), _tiems_logged(1), _guesses(0), _correct_guesses(0) {}
// constructor
inline UserProfile::UserProfile() 
    : _login("guest"), _user_level(Beginner), _tiems_logged(1), _guesses(0), _correct_guesses(0) 
{
    static int id = 0;
    // char buffer[16];
    string buffer;
    my_itoa(id++, buffer, 10);    // itoa 将整数转化为 ASCII 字符串, gcc 用不来
    _login += buffer;               // 添加登录记录 ()
}

inline string UserProfile::level() const {
    static string _level_table[] = {
        "Beginner", "Intermediate", "Advanced", "Guru"
    };
    return _level_table[_user_level];
}
// 重载 ==
inline bool UserProfile::operator==(const UserProfile &rhs) {
    if (_login == rhs._login && _user_name == rhs._user_name)
        return true;
    return false;
}
// 重载 !=
inline bool UserProfile::operator!=(const UserProfile &rhs) {
    return !(*this == rhs);
}

inline void UserProfile::reset_level(const string &level) {
    map<string, uLevel>::iterator it;
    if (_level_map.empty())
        init_level_map();
    // 确保 level 代表一个可识别的用户等级
    _user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
}
