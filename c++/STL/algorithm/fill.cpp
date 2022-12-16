#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void test()
{
    vector<int>v; 
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }
    fill(v.begin(), v.end(), 6);
    for (vector<int>::iterator  it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main (int argc, char *argv[])
{
    test(); 
    return 0;
}
