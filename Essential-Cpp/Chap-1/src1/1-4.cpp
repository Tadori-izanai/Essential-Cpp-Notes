// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch;
//     int count = 0;

//     while (cin >> ch, ch != 'b')
//     {
//         switch (ch)
//         {
//         case 'a':
//         case 'A':
//         case 'e':
//         case 'E':
//             ++count;
//             cout << "count++" << endl;
//             break;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    const int min_size = 4;

    while (cin >> word, word.size() < min_size)     // .size()
        cout << "echo: " << word << endl;

    return 0;
}