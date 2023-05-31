#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
    if (sum == target) {
      res.push_back(path);
      return;
    }

    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
      // deduplication
      if (i > startIndex && candidates[i] == candidates[i - 1])
        continue;

      sum += candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates, target, sum, i + 1);
      sum -= candidates[i];
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    res.clear();
    path.clear();

    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return res;
  }
};
