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
  replace(v.begin(), v.end(), 5, 100);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  test();
  return 0;
}
