#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, vector<bool> &used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i])
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    res.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
  }
};
