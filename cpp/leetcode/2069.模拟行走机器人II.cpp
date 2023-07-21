#include <bits/stdc++.h>

using namespace std;

class Robot {
public:
  Robot(int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
      pos.emplace_back(i, 0);
      dir.emplace_back(0);
    }
    for (j = 1; j < height; j++) {
      pos.emplace_back(width - 1, j);
      dir.emplace_back(1);
    }
    for (i = width - 2; i >= 0; i--) {
      pos.emplace_back(i, height - 1);
      dir.emplace_back(2);
    }
    for (j = height - 2; j > 0; j--) {
      pos.emplace_back(0, j);
      dir.emplace_back(3);
    }
    dir[0] = 3;
  }
  void step(int num) {
    move = true;
    index = (index + num) % pos.size();
  }
  vector<int> getpos() { return {pos[index].first, pos[index].second}; }
  string getDir() {
    if (!move)
      return "East";
    return dirs[dir[index]];
  }

private:
  vector<pair<int, int>> pos;
  vector<int> dir;
  bool move = false;
  int index = 0;
  unordered_map<int, string> dirs = {
      {0, "East"},
      {1, "North"},
      {2, "West"},
      {3, "South"},
  };
};
