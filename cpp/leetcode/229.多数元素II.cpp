#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> majorityElements(vector<int> &nums) {
    map<int, int> cnt;
    vector<int> res;
    int n = nums.size();
    for (auto &num : nums) {
      cnt[num]++;
    }
    for (auto &[k, v] : cnt) {
      if (v > n / 3) {
        res.push_back(k);
      }
    }
    return res;
  }
};
