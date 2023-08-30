#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int res;
  bool check(int row, int col, vector<int> &pos) {
    for (int i = 0; i < row; i++) {
      if (row == i || col == pos[i] || abs(row - i) == abs(col - pos[i]))
        return false;
    }
    return true;
  }
  void dfs(int n, int row, vector<int> &pos) {
    if (row == n) {
      res++;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (check(row, i, pos)) {
        pos[row] = i;
        dfs(n, row + 1, pos);
      }
    }
  }
  int totalNQueues(int n) {
    vector<int> pos(n);
    dfs(n, 0, pos);
    return res;
  }
};
