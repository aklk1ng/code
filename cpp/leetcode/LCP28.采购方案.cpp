#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int purchasePlans(vector<int> &nums, int target) {
    long long res = 0;
    long long mod = 1000000007;
    int j = nums.size() - 1;
    for (int i = 0; i < j; j++) {
      while (j > i && nums[i] + nums[j] > target)
        j--;

      res += j - i;
    }
    return res % mod;
  }
};
