#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, int startIndex) {
    res.push_back(path);

    unordered_set<int> uset;
    for (int i = startIndex; i < nums.size(); i++) {
      if (uset.find(nums[i]) != uset.end())
        continue;

      uset.insert(nums[i]);
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subsetWithdup(vector<int> &nums) {
    res.clear();
    path.clear();
    sort(nums.begin(), nums.end());
    backtracking(nums, 0);
    return res;
  }
};
