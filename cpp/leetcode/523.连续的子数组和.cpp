#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2)
      return false;

    int sum[n + 1];
    memset(sum, 0, sizeof(sum));

    unordered_set<int> set;
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + nums[i - 1]; // sum[0] = 0

    for (int i = 2; i <= n; i++) {
      set.insert(sum[i - 2] % k);
      if (set.count(sum[i] % k))
        return true;
    }
    return false;
  }
};
