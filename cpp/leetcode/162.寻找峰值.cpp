#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < nums[mid + 1])
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};

class Solution2 {
public:
  int findPeakElement(vector<int> &nums) {
    return max_element(nums.begin(), nums.end()) - nums.begin();
  }
};
