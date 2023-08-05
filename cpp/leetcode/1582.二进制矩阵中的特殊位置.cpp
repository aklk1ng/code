#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int res = 0;
    vector<int> rowcnt(m);
    vector<int> colcnt(n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rowcnt[i] += mat[i][j];
        colcnt[j] += mat[i][j];
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1 && rowcnt[i] == 1 && colcnt[j] == 1)
          res++;
      }
    }
    return res;
  }
};
