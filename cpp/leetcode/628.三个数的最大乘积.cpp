#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    int n = nums.size();
    if (n < 3)
      return INT_MIN;
    return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
  }
};
