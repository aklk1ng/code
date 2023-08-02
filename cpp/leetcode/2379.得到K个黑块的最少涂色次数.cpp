#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int l, r, cnt = 0, n = blocks.size();
    while (r < k) {
      cnt += blocks[r] == 'W' ? 1 : 0;
      r++;
    }
    int res = cnt;
    while (r < n) {
      cnt += blocks[r] == 'W' ? 1 : 0;
      cnt -= blocks[l] == 'W' ? 1 : 0;
      res = min(res, cnt);
      l++;
      r++;
    }
    return res;
  }
};
