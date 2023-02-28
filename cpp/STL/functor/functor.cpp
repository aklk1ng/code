#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MyAdd {
public:
  int operator()(int v1, int v2) { return v1 + v2; }
};
void test() {
  MyAdd myadd;
  cout << myadd(19, 19) << endl;
}
class MyPrint {
public:
  MyPrint() { this->count = 0; }
  void operator()(string test) {
    cout << test << endl;
    this->count++;
  }
  int count;
};
void test1() {
  MyPrint myprint;
  myprint("hello");
  cout << myprint.count << endl;
}

void doPrint(MyPrint &mp, string s) { mp(s); }
void test2() {
  MyPrint myprint;
  doPrint(myprint, "hello cpp");
}

// unary predicate
class GreaterFive {
public:
  bool operator()(int val) { return val > 5; }
};
void test3() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
  if (pos == v.end()) {
    cout << "find failed" << endl;
  } else
    cout << *pos << endl;
}

// binary predicate
class MyCompare {
public:
  bool operator()(int v1, int v2) { return v1 > v2; }
};
void test4() {
  vector<int> v;
  v.push_back(10);
  v.push_back(5);
  v.push_back(8);
  v.push_back(0);
  v.push_back(100);
  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }
  cout << "------------" << endl;
  sort(v.begin(), v.end(), MyCompare());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }
}

// arithmetic functor
void test5() {
  negate<int> n;
  cout << n(50) << endl;

  plus<int> p;
  cout << p(10, 20) << endl;
}

// relational functor
void test6() {
  vector<int> v;
  v.push_back(10);
  v.push_back(5);
  v.push_back(8);
  v.push_back(0);
  v.push_back(100);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "------------------" << endl;
  sort(v.begin(), v.end(), greater<int>());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void test7() {
  vector<bool> v;
  v.push_back(true);
  v.push_back(true);
  v.push_back(false);
  v.push_back(false);
  for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  vector<bool> v2;
  v2.resize(v.size());
  transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
  for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  /* test(); */
  /* test1(); */
  /* test2(); */
  /* test3(); */
  /* test4(); */
  /* test5(); */
  /* test6(); */
  test7();
  return 0;
}
