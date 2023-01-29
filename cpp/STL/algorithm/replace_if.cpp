#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Replace {
  public:
    bool operator()(int val) { return val > 5; }
};
void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    replace_if(v.begin(), v.end(), Replace(), 100);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
