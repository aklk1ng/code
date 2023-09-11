#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty())
      return {};
    int l = 0, t = 0, r = matrix[0].size() - 1, b = matrix.size();
    vector<int> res;
    while (true) {
      for (int i = l; i <= r; i++)
        res.push_back(matrix[t][i]);
      if (++t > b)
        break;
      for (int i = t; i <= b; i++)
        res.push_back(matrix[i][r]);
      if (l > --r)
        break;
      for (int i = r; i >= l; i--)
        res.push_back(matrix[b][i]);
      if (t > --b)
        break;
      for (int i = b; i >= t; i--)
        res.push_back(matrix[i][l]);
    }
    return res;
  }
};
