#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int maximizeGreatness(vector<int> &nums) {
    int mx = 0;
    unordered_map<int, int> cnt;
    for (int x : nums) {
      mx = max(mx, ++cnt[x]);
    }
    return nums.size() - mx;
  }
};
