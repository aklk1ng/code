#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
  stack<int> stIn;
  stack<int> stOut;

  MyQueue() {}

  void push(int x) { stIn.push(x); }

  int pop() {
    // when the stOut is empty
    // move all the elements from stIn to stOut
    if (stOut.empty()) {
      while (!stIn.empty()) {
        stOut.push(stIn.top());
        stIn.pop();
      }
    }
    int res = stOut.top();
    stOut.pop();
    return res;
  }

  int peek() {
    int res = this->pop();
    stOut.push(res);
    return res;
  }

  bool empty() { return stIn.empty() && stOut.empty(); }
};
