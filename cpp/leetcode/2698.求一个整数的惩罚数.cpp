#include <bits/stdc++.h>

using namespace std;

int pre_sum[1001];
int init = []() {
  for (int i = 1; i <= 1000; i++) {
    auto s = to_string(i * i);
    int n = s.size();
    function<bool(int, int)> dfs = [&](int p, int sum) -> bool {
      if (p == n)
        return sum == i;
      int x = 0;
      for (int j = p; j < n; j++) {
        x = x * 10 + int(s[j] - '0');
        if (dfs(j + 1, sum + x))
          return true;
      }
      return false;
    };
    pre_sum[i] = pre_sum[i - 1] + (dfs(0, 0) ? i * i : 0);
  }
  return 0;
}();

class Solution {
public:
  int punishmentNumber(int n) { return pre_sum[n]; }
};
