#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<string>> res;
  vector<string> path;
  vector<int> pos;

  bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
      if (row == i || col == pos[i] || abs(row - i) == abs(col - pos[i]))
        return false;
    }
    return true;
  }
  void dfs(int n, int row) {
    if (row == n) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (check(row, i)) {
        pos[row] = i;
        path[row][i] = 'Q';
        dfs(n, row + 1);
        path[row][i] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueues(int n) {
    pos.resize(n);
    path.resize(n);
    for (int i = 0; i < n; i++) {
      path[i].resize(n);
      for (int j = 0; j < n; j++) {
        path[i][j] = '.';
      }
    }
    dfs(n, 0);
    return res;
  }
};
