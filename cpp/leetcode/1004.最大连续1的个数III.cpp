#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0, l = 0, cnt0 = 0; // cnt0 is the count of zero in window
    for (int r = 0; r < n; r++) {
      cnt0 += 1 - nums[r];
      while (cnt0 > k)
        cnt0 -= nums[l++];
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
