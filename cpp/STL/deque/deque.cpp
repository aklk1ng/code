#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
using namespace std;

void PrintDeque(const deque<int> &d) {
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    // can't change the data
    cout << *it << " ";
  }
  cout << endl;
}
void test1() {
  deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }
  PrintDeque(d);

  deque<int> d1(d.begin(), d.end());
  PrintDeque(d1);

  deque<int> d2(10, 100);
  PrintDeque(d2);

  deque<int> d3(d2);
  PrintDeque(d3);
}

// deque assign operator
void test2() {
  deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }
  PrintDeque(d);
  deque<int> d1;
  d1 = d;
  PrintDeque(d1);

  deque<int> d2;
  d2.assign(d.begin(), d.end());
  PrintDeque(d2);

  deque<int> d3;
  d3.assign(10, 100);
  PrintDeque(d3);
}

// deque size
void test3() {
  deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }
  if (d.empty()) {
    cout << "empty" << endl;
  } else {
    cout << d.size() << " ";
    d.resize(20);
    cout << d.size() << " ";
  }
}

// deque insert and erase
void test4() {
  deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }
  PrintDeque(d);
  cout << d.front() << " " << endl;
  cout << d.back() << " " << endl;
  d.push_front(-1);
  d.pop_back();
  d.pop_front();
  PrintDeque(d);
  d.insert(d.begin(), 10);
  PrintDeque(d);
  d.insert(d.begin(), 2, 66);
  PrintDeque(d);
  d.insert(d.begin(), d.begin(), d.end());
  PrintDeque(d);
  d.erase(d.begin());
  PrintDeque(d);
  d.clear();
  PrintDeque(d);
}

// deque get the data
void test5() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  d.push_back(5);
  d.push_back(6);
  d.push_back(7);
  d.push_back(8);
  d.push_back(9);
  for (int i = 0; i < d.size(); i++) {
    cout << d[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < d.size(); i++) {
    cout << d.at(i) << " ";
  }
  cout << endl;
  cout << d.front() << endl;
  cout << d.back() << endl;
}

// deque sort
void test6() {
  deque<int> d;
  d.push_back(3);
  d.push_back(1);
  d.push_back(2);
  d.push_back(4);
  d.push_back(6);
  d.push_back(5);
  d.push_back(7);
  d.push_back(8);
  d.push_back(9);
  for (int i = 0; i < d.size(); i++) {
    cout << d.at(i) << " ";
  }
  cout << endl;

  // default is ascending
  sort(d.begin(), d.end());
  for (int i = 0; i < d.size(); i++) {
    cout << d.at(i) << " ";
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  /* test1(); */
  /* test2(); */
  /* test3(); */
  /* test4(); */
  /* test5(); */
  test6();
  return 0;
}
