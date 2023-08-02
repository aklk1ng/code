#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int ans = 0;
    unordered_map<int, int> cnt;
    for (auto &&x : points) {
      cnt.clear();
      for (auto &&y : points) {
        ans += 2 * cnt[(x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])]++;
      }
    }
    return ans;
  }
};
