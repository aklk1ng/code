#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // dp[i][j] 表示以(i, j)为终点的路径的最小路径和
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = matrix[0][0];

    for (int i = 1; i < n; i++)
      dp[i][0] = matrix[i][0] + dp[i - 1][0];
    for (int j = 1; j < n; j++)
      dp[0][j] = matrix[0][j] + dp[0][j - 1];

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[n - 1][m - 1];
  }
};
