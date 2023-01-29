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
    vector<int> v1;
    for (int i = 10; i > 0; i--) {
        v1.push_back(i);
    }
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // only works for two same containers
    swap(v, v1);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
