#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void test() {
    vector<int> v;
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }
    // the third parameter is the starting accumulative value
    int total = accumulate(v.begin(), v.end(), 0);
    cout << total << endl;
}
int main(int argc, char *argv[]) {
    test();
    return 0;
}
