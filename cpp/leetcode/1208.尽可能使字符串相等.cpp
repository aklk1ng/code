#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int res = 0;
    int left, right = 0;
    int cost = 0;

    while (right < s.size()) {
      cost += abs(s[right] - t[right]);

      while (cost > maxCost) {
        cost -= abs(s[left] - t[left]);
        left++;
      }

      res = max(res, right - left + 1);
      right++;
    }
    return res;
  }
};
