#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, x, y, s;
  std::cin >> n >> x >> y >> s;

  std::vector<int> dp(s + 1, INT_MAX);
  dp[0] = 0;
  for (int k = 1; k <= s; k++) {
    for (int l = 2; (l * (l - 1)) / 2 <= k; l++) {
      dp[k] = std::min(dp[k], dp[k - (l * (l - 1)) / 2] + l);
    }
  }
  for (int k = 0; k < n; k++) {
    ll pre = (k + 1) * x + (k * (k + 1)) / 2 * y;
    if (pre > s) {
      continue;
    }
    ll need = s - pre;
    need -= (n - k - 1) * (x % y);
    if (need < 0) {
      continue;
    }
    if (need % y) {
      continue;
    }
    need /= y;
    if (dp[need] <= n - k - 1) {
      std::vector<int> a(n);
      a[0] = x;
      for (int i = 1; i <= k; i++) {
        a[i] = a[i - 1] + y;
      }
      for (int i = k + 1; i <= k + (n - k - 1) - dp[need]; i++) {
        a[i] = x % y;
      }
      int i = k + (n - k - 1) - dp[need] + 1;
      std::vector<int> lens;
      while (need) {
        for (int l = 2; (l * (l - 1)) / 2 <= need; l++) {
          if (dp[need] == dp[need - (l * (l - 1)) / 2] + l) {
            lens.push_back(l);
            need -= (l * (l - 1)) / 2;
            break;
          }
        }
      }
      for (auto &e : lens) {
        for (int j = 0; j < e; j++) {
          a[i] = (x % y) + y * j;
          i++;
        }
      }
      std::cout << "YES\n";
      for (auto &e : a) {
        std::cout << e << " \n"[e == a.back()];
      }
      return;
    }
  }
  std::cout << "NO\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
