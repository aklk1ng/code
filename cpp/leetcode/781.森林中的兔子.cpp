#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numRabbits(vector<int> &answer) {
    unordered_map<int, int> map;
    for (auto y : answer)
      map[y]++;

    int ans = 0;
    for (auto &[y, x] : map)
      ans += (x + y) / (y + 1) * (y + 1);

    return ans;
  }
};
