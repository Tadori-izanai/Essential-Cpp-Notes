// 使用 vector
#include <iostream>
#include  <vector>
using namespace std;

int main()
{
    vector<int> val;
    int number;

    cout << "Enter some integrates, q to quit: " << endl;
    while (cin >> number){
        val.push_back(number);
    }

    int sum = 0;
    for (int i = 0; i < val.size(); i++)
        sum += val[i];

    cout << "sum is " << sum << endl;
    cout << "average: " << sum / val.size() << endl;     

    return 0;
}