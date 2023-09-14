#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumDeletions(vector<int> &nums) {
    int n = nums.size();
    int mi_idx = min_element(nums.begin(), nums.end()) - nums.begin();
    int mx_idx = max_element(nums.begin(), nums.end()) - nums.begin();

    int l = min(mi_idx, mx_idx);
    int r = max(mi_idx, mx_idx);
    return min({r + 1, n - l, l + 1 + n - r});
  }
};
