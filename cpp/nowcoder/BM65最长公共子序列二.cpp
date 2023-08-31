#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string x;
  string y;
  string ans(int i, int j, vector<vector<int>> &b) {
    string res = "";
    if (i == 0 || j == 0)
      return res;
    if (b[i][j] == 1) {
      res += ans(i - 1, j - 1, b);
      res += x[i - 1];
    } else if (b[i][j] == 2) {
      res += ans(i - 1, j, b);
    } else if (b[i][j] == 3) {
      res += ans(i, j - 1, b);
    }
    return res;
  }
  string LCS(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    if (len1 == 0 || len2 == 0)
      return "-1";
    x = s1, y = s2;
    // dp[i][j] 表示第一个字符串选到第i位,第二个字符串选到第j个为止的最长公共子序列长度
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    // 动态规划数组相加的方向
    vector<vector<int>> b(len1 + 1, vector<int>(len2 + 1));

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          b[i][j] = 1;
        } else {
          if (dp[i - 1][j] > dp[i][j - 1]) {
            dp[i][j] = dp[i - 1][j];
            b[i][j] = 2;
          } else {
            dp[i][j] = dp[i][j - 1];
            b[i][j] = 3;
          }
        }
      }
    }
    string res = ans(len1, len2, b);
    return res != "" ? res : "-1";
  }
};
