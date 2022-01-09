#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int main()
// {
//     string f_name, l_name;

//     cout << "Enter your first name: ";
//     cin >> f_name;
//     cout << "Enter your last name: ";
//     cin >> l_name;

//     cout << "Hello, "
//     << f_name
//     << " "
//     << l_name
//     << " ... and goodbye!\n";

//     return 0;
// }

// 使用 vector
int main()
{
    vector<string> name_vec(2);

    cout << "Enter your first and last name: ";
    cin >> name_vec[0] >> name_vec[1];

    cout << "Hello, "
    << name_vec[0] << ' '
    << name_vec[1]
    << " ... and goodbye!" << endl;

    return 0;
}