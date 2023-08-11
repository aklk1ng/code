#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool Find(int target, vector<vector<int>> &array) {
    int n = array.size();
    int m = array[0].size();
    if (n == 0)
      return false;

    int row = n - 1, col = 0;

    while (row >= 0 && col < m) {
      int tmp = array[row][col];
      if (tmp < target)
        col++;
      else if (tmp > target)
        row--;
      else
        return true;
    }
    return false;
  }
};
