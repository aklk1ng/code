#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;
  std::vector<int> a(n + 1);
  int sum = 0;
  auto get = [&](int x) {
    int cur = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
      cur += x * a[i];
      mx = std::max(mx, cur);
      if (cur < 0) {
        cur = 0;
      }
    }
    return mx;
  };
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] != t[i - 1]) {
      if (s[i - 1] == '1') {
        a[i] = -1;
      } else {
        a[i] = 1;
      }
    }
    sum += a[i];
  }
  if (sum) {
    std::cout << -1 << '\n';
    return;
  }
  int ans = std::max(get(1), get(-1));
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
