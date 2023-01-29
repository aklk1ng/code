#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
