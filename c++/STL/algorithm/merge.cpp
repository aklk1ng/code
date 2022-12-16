#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
using namespace std;
// only works for ordered sequences
void test()
{
    vector<int>v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (vector<int>::iterator  it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    vector<int>v1; 
    for (int i = 10; i > 0; i--) {
        v1.push_back(i);
    }
    for (vector<int>::iterator  pos = v1.begin(); pos != v1.end(); pos++) {
        cout << *pos << " ";
    }
    cout << endl;
    vector<int>v2;
    v2.resize(v.size()+v1.size());
    merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
    for (vector<int>::iterator  cur = v2.begin(); cur != v2.end(); cur++) {
        cout << *cur << " ";
    }
    cout << endl;
}
int main (int argc, char *argv[])
{
    test(); 
    return 0;
}
