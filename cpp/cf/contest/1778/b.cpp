#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<int> pos(n + 1), p(n + 1), a(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    pos[p[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }

  int ans = INT_MAX;
  for (int i = 1; i < m; i++) {
    if (pos[a[i + 1]] <= pos[a[i]] || pos[a[i + 1]] - pos[a[i]] > d) {
      ans = 0;
      break;
    }
    ans = std::min(ans, pos[a[i + 1]] - pos[a[i]]);
    int dist = pos[a[i + 1]] - pos[a[i]];
    int tmp = d - dist + 1;
    if (pos[a[i]] - 1 + (n - pos[a[i + 1]]) >= tmp) {
      ans = std::min(ans, tmp);
    }
  }
  std::cout << ans << '\n';
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
