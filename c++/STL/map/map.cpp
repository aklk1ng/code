#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

void Print(map<int, int>&m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,12));
    m.insert(pair<int, int>(3,8));
    m.insert(pair<int, int>(4,14));
    Print(m);

    map<int, int>m2(m);
    Print(m2);
}
int main (int argc, char *argv[])
{
    test(); 
    return 0;
}
