#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = nums.size();
    int ans = 0, sum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      sum += nums[i] ? 1 : -1;
      if (mp.find(sum) == mp.end())
        mp[sum] = i;
      else
        ans = max(ans, i - mp[sum]);
    }
    return ans;
  }
};
