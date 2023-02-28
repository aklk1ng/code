
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void TemplatePrint(vector<int> &v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// transform
class Transform {
public:
  int operator()(int v) { return v + 1; }
};
void test1() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  TemplatePrint(v);
  vector<int> v1;
  v1.resize(v.size());
  transform(v.begin(), v.end(), v1.begin(), Transform());
  TemplatePrint(v1);
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
