#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  int mx = -INF;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx = std::max(mx, a[i]);
  }
  std::vector adj(n + 1, std::vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) {
      x++;
    } else if (a[i] == mx - 1) {
      y++;
    }
  }

  int ans = mx + 2;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) {
      x--;
    } else if (a[i] == mx - 1) {
      y--;
    }
    for (int j = 0; j < (int)adj[i].size(); j++) {
      int pos = adj[i][j];
      if (a[pos] == mx) {
        x--, y++;
      } else if (a[pos] == mx - 1) {
        y--;
      }
    }

    if (!x) {
      ans = std::min(ans, mx + 1);
      if (!y) {
        ans = std::min(ans, mx);
      }
    }

    if (a[i] == mx) {
      x++;
    } else if (a[i] == mx - 1) {
      y++;
    }
    for (int j = 0; j < (int)adj[i].size(); j++) {
      int pos = adj[i][j];
      if (a[pos] == mx) {
        x++, y--;
      } else if (a[pos] == mx - 1) {
        y++;
      }
    }
  }

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
