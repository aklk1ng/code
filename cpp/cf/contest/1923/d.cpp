#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> ans(n, n);
  for (int _ = 0; _ < 2; _++) {
    std::vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + a[i];
    }
    std::vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
      int j = (_ ? n - i - 1 : i);
      int l = 1, r = i;
      while (l <= r) {
        int m = (l + r) / 2;
        if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
          ans[j] = std::min(ans[j], m);
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      if (a[i - 1] > a[i]) {
        ans[j] = 1;
      }
      p[i] = (a[i] == a[i - 1] ? p[i - 1] : i - 1);
    }
    std::reverse(a.begin(), a.end());
  }

  for (int i = 0; i < n; i++) {
    std::cout << (ans[i] == n ? -1 : ans[i]) << " \n"[i == n - 1];
  }
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
