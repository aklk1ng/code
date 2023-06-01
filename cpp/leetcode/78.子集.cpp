#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, int startIndex) {
    res.push_back(path);
    if (startIndex >= nums.size())
      return;

    for (int i = startIndex; i < nums.size(); i++) {
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subset(vector<int> &nums) {
    res.clear();
    path.clear();
    backtracking(nums, 0);
    return res;
  }
};
