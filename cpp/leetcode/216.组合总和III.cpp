#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(int targetSum, int k, int sum, int startIndex) {
    if (path.size() == k) {
      if (sum == targetSum)
        res.push_back(path);
      return;
    }

    for (int i = startIndex; i <= 9; i++) {
      sum += i;
      path.push_back(i);
      backtracking(targetSum, k, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
  }
  vector<vector<int>> combineationSum3(int k, int n) {
    res.clear();
    path.clear();
    backtracking(k, n, 0, 1);
    return res;
  }
};
