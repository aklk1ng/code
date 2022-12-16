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
    vector<int>v1; 
    for (int i = 0; i <= 10; i++) {
        v1.push_back(i);
    }
    vector<int>target;
    target.resize(v.size() >= v1.size() ? v1.size() : v.size());
    vector<int>::iterator pos = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), target.begin());
    for (vector<int>::iterator  it = target.begin(); it != pos; it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main (int argc, char *argv[])
{
    test(); 
    return 0;
}
