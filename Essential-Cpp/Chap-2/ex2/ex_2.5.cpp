#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int max(int, int);
inline float max(float, float);
inline string max(const string &, const string &);
inline int max(const vector<int> &);
inline float max(const vector<float> &);
inline string max(const vector<string> &);
inline int max(int[], int);
inline float max(float[], int);
inline string max(string[], int);

int main()
{
    string sarray[] = {
        "we", "were", "her", "pride", "of", "tem"};
    vector<string> svec(sarray, sarray + 6);

    int iarray[] = {
        12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(iarray, iarray + 7);

    float farray[] = {
        2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(farray, farray + 5);

    int imax = max(max(ivec), max(iarray, 7));
    float fmax = max(max(fvec), max(farray, 5));
    string smax = max(max(svec), max(sarray, 6));

    cout << "imax should be 169 --- found: " << imax << endl;
    cout << "fmax should be 24.8 -- found: " << fmax << endl;
    cout << "smax should be were -- found: " << smax << endl;

    return 0;
}

inline int max(int x, int y)
{
    return ((x > y) ? x : y);
}
inline float max(float x, float y)
{
    return ((x > y) ? x : y);
}
inline string max(const string &s, const string &t)
{
    return ((s > t) ? s : t);
}
inline int max(const vector<int> &vec)
{
    return *max_element(vec.begin(), vec.end());
}
inline float max(const vector<float> &vec)
{
    return *max_element(vec.begin(), vec.end());
}
inline string max(const vector<string> &vec)
{
    return *max_element(vec.begin(), vec.end());
}
inline int max(int a[], int n)
{
    return *max_element(a, a + n);
}
inline float max(float a[], int n)
{
    return *max_element(a, a + n);
}
inline string max(string a[], int n)
{
    return *max_element(a, a + n);
}