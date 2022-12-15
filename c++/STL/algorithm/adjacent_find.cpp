#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// find adjacent duplicate elements
void test()
{
    vector<int>v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.push_back(9);
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "find failed" << endl;
    } else cout << *it << endl;
}
int main (int argc, char *argv[])
{
    test();    
    return 0;
}
