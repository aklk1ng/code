#include <iostream>
#include <queue>
using namespace std;

void test1()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    if (!q.empty()) {
        cout << q.back() << endl;
        cout << q.front() << endl;
        cout << q.size() << endl;
        q.pop();
        cout << q.front() << endl;
        cout << q.size() << endl;
    }
}
int main (int argc, char *argv[])
{
    test1();    
    return 0;
}
