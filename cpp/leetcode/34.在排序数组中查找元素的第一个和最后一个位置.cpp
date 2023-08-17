#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int binary_search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    int start = binary_search(nums, target);
    if (start == nums.size() || nums[start] != target)
      return {-1, -1};
    int end = binary_search(nums, target + 1) - 1;
    return {start, end};
  }
};
