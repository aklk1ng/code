#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    res[0] = accumulate(nums.begin(), nums.end(), 0) - nums[0] * n;
    for (int i = 1; i < n; i++) {
      int d = nums[i] - nums[i - 1];
      res[i] = res[i - 1] - (n - i * 2) * d;
    }
    return res;
  }
};
