#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1; // 应对nums[0] = k这种情况
    int cnt = 0, pre = 0;
    for (auto &num : nums) {
      if (mp.find(pre - k) != mp.end())
        cnt += mp[pre - k];
      mp[pre]++;
    }
    return cnt;
  }
};
