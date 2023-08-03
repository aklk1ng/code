#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans(n, -1);
    if (2 * k + 1 <= n) {
      long long sum = accumulate(nums.begin(), nums.begin() + 2 * k + 1, 0LL);
      for (int i = k; i + k < n; i++) {
        if (i != k)
          sum += nums[i + k] - nums[i - k - 1];
        ans[i] = sum / (2 * k + 1);
      }
    }
    return ans;
  }
};
