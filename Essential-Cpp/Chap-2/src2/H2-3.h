// #define MY_DEBUG
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// void display(vector<int>);
void display(const vector<int> &, ostream & = cout);
// void swap(int, int);
void swap(int &, int &);            // 改为传址 (pass by reference)
// void bubble_sort(vector<int>);
// void bubble_sort(vector<int> &);    // 改为传址
void bubble_sort(vector<int> &, ofstream *ofil = 0);    // 改为传址