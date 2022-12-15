
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// for_each
void print01(int val)
{
    cout << val << " ";
}
class print02
{
    public:
        void operator() (int val) {
            cout << val << " ";
        }
};
void test()
{
    vector<int>v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;
}
int main (int argc, char *argv[])
{
    test();    
    return 0;
}
