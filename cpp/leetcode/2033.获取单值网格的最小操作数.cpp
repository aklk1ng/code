#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    int m = grid.size(), n = grid[0].size();
    vector<int> buf;
    for (auto &line : grid)
      for (auto &i : line)
        buf.push_back(i);

    for (auto &i : buf)
      if ((i - buf[0]) % x)
        return -1;

    int mid = m * n / 2;
    int ans = 0;
    for (auto &i : buf)
      ans += abs(i - buf[mid]) % x;
    return ans;
  }
};
