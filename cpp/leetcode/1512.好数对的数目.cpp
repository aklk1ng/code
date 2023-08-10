#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] == nums[j])
          ans++;
      }
    }
    return ans;
  }
};

class Solution2 {
public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> m;
    for (int num : nums)
      m[num]++;

    int ans = 0;
    for (const auto &[k, v] : m)
      ans += v * (v - 1) / 2;
    return ans;
  }
};
