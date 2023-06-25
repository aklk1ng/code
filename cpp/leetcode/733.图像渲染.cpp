#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  const int dx[4] = {1, 0, 0, -1};
  const int dy[4] = {0, 1, -1, 0};
  void dfs(vector<vector<int>> &image, int x, int y, int curcolor, int color) {
    if (image[x][y] == curcolor) {
      image[x][y] = color;

      for (int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if (mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size())
          dfs(image, mx, my, curcolor, color);
      }
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    int curcolor = image[sr][sc];
    if (curcolor != color)
      dfs(image, sr, sc, curcolor, color);
    return image;
  }
};
