#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }

    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
      path.push_back(i);
      backtracking(n, k, i + 1); // recursion
      path.pop_back();           // backtrack
    }
  }
  vector<vector<int>> combine(int n, int k) {
    res.clear();
    path.clear();
    backtracking(n, k, 1);
    return res;
  }
};
