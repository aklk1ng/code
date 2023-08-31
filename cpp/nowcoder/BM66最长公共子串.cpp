#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string LCS(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    int max = 0, pos = 0;
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;

        if (dp[i][j] > max) {
          max = dp[i][j];
          pos = i - 1;
        }
      }
    }
    return str1.substr(pos - max + 1, max);
  }
};
