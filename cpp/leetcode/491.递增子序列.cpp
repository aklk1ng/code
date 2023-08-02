#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, int startIndex) {
    if (path.size() > 1)
      res.push_back(path);

    int uset[201] = {0};

    for (int i = startIndex; i < nums.size(); i++) {
      if (uset[nums[i] + 100] != 0 || (!path.empty() && nums[i] < path.back()))
        continue;

      uset[nums[i] + 100] = 1;
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    res.clear();
    path.clear();
    backtracking(nums, 0);
    return res;
  }
};
