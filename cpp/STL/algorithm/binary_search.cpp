#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// only works for ordered sequences
void test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  sort(v.begin(), v.end());
  bool pos = binary_search(v.begin(), v.end(), 100);
  if (pos) {
    cout << "find successful" << endl;
  } else
    cout << "find failed" << endl;
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
