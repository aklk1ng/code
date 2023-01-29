#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Compare {
public:
    bool operator()(int v1, int v2) { return v1 > v2; }
};
void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.push_back(5);
    v.push_back(3);
    v.push_back(5);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), Compare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
