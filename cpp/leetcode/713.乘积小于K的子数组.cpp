#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numSubArrayProductLessThank(vector<int> &nums, int k) {
    if (k <= 1)
      return 0;
    int n = nums.size();
    int ans = 0;
    int s = 1, l = 0;
    for (int r = 0; r < n; r++) {
      s *= nums[r];
      while (s >= k) {
        s /= nums[l];
        l++;
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
