#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int s = 0, l = 0;
    for (int r = 0; r < n; r++) {
      s += nums[r];
      while (s >= target) {
        s -= nums[l];
        ans = min(ans, r - l + 1);
        l++;
      }
    }
    return ans;
  }
};
