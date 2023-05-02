#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSLidingWindow(vector<int> &nums, int k) {
    MyQueue q;
    vector<int> res;
    for (int i = 0; i < k; i++) {
      q.push(nums[i]);
    }

    res.push_back(q.front());

    for (int i = k; i < nums.size(); i++) {
      q.pop(nums[i - k]);
      q.push(nums[i]);
      res.push_back(q.front());
    }

    return res;
  }

private:
  class MyQueue {
  public:
    deque<int> d;
    void pop(int value) {
      if (!d.empty() && value == d.front())
        d.pop_front();
    }

    void push(int value) {
      while (!d.empty() && value > d.back())
        d.pop_back();
      d.push_back(value);
    }

    int front() { return d.front(); }
  };
};
