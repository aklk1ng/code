#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void test() {
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
