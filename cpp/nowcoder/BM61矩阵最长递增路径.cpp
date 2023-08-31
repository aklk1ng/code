#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int n, m;
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};
  int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y) {
    if (dp[x][y])
      return dp[x][y];
    dp[x][y]++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y])
        dp[x][y] = max(dp[x][y], dfs(matrix, dp, nx, ny) + 1);
    }
    return dp[x][y];
  }

  int solve(vector<vector<int>> &matrix) {
    int res = 0;
    n = matrix.size();
    m = matrix[0].size();
    if (n == 0 || m == 0)
      return 0;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res = max(res, dfs(matrix, dp, i, j));
      }
    }
    return res;
  }
};
