#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
    if (sum > target)
      return;
    if (sum == target) {
      res.push_back(path);
      return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates, target, sum, startIndex);
      sum -= candidates[i];
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    res.clear();
    path.clear();
    backtracking(candidates, target, 0, 0);
    return res;
  }
};
