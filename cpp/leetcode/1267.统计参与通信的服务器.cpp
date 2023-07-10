#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int countServers(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> count_m(m), count_n(n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1) {
          count_m[i]++;
          count_n[j]++;
        }

    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1 && (count_m[i] > 1 || count_n[j] > 1))
          res++;

    return res;
  }
};
