#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k, s1, s2;
  std::cin >> n >> k >> s1 >> s2;
  std::vector<int> p(n), a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  auto score = [&](int s, int t) {
    ll res = 0, cur = 0;
    std::vector<bool> vis(n);
    while (!vis[s] && t > 0) {
      vis[s] = true;
      res = std::max(res, cur + 1LL * t * a[s]);
      cur += a[s];
      t--;
      s = p[s];
    }
    return res;
  };
  ll A = score(s1 - 1, k), B = score(s2 - 1, k);
  std::cout << (A > B ? "Bodya\n" : A < B ? "Sasha\n" : "Draw\n");
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
