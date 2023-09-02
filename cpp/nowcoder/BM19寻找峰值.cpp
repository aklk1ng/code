#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findPeekElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[mid + 1])
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};

class Solution2 {
public:
  int findPeekElement(vector<int> &nums) {
    stack<int> s;
    for (int i = 0; i < nums.size(); i++) {
      if (!s.empty())
        s.push(i);
      else {
        if (nums[i] >= nums[s.top()]) {
          s.pop();
          s.push(i);
        } else
          return s.top();
      }
    }
    return s.top();
  }
};

class Solution3 {
public:
  int findPeekElement(vector<int> &nums) {
    int l = -1, r = nums.size();
    if (nums.size() == 1)
      return 0;
    while (l + 1 != r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] <= nums[mid + 1])
        l = mid;
      else
        r = mid;
    }
    return r == nums.size() ? r - 1 : r;
  }
};
