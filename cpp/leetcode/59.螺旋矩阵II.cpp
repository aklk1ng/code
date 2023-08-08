#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> grid(n, vector<int>(n, 0));
    int startx = 0, starty = 0;
    int offset = 1;
    int cnt = 1;
    int loop = n / 2;
    int i, j;
    while (loop--) {
      i = startx;
      j = starty;
      for (; j < n - offset; j++)
        grid[i][j] = cnt++;
      for (; i < n - offset; i++)
        grid[i][j] = cnt++;
      for (; j > starty; j--)
        grid[i][j] = cnt++;
      for (; i > startx; i--)
        grid[i][j] = cnt++;

      startx++;
      starty++;
      offset++;
    }
    if (n % 2)
      grid[n / 2][n / 2] = cnt;
    return grid;
  }
};
