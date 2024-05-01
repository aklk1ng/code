#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n + 1, std::vector<int>());
  std::vector<int> occ(n + 1);
  occ[1] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    adj[b].push_back(a);
  }

  std::queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < adj[t].size(); i++) {
      if (occ[adj[t][i]] == 0) {
        occ[adj[t][i]] = occ[t] + 1;
        q.push(adj[t][i]);
      }
    }
  }
  std::vector v(n + 1, std::vector<int>());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!occ[i]) {
      std::cout << "INFINITE\n";
      return;
    }
    v[occ[i]].push_back(i);
    ans += occ[i];
  }
  std::cout << "FINITE\n" << ans << '\n';
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= i; j--) {
      if (i % 2 != j % 2) {
        continue;
      }
      for (int k = 0; k < v[j].size(); k++) {
        std::cout << v[j][k] << ' ';
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = n; j >= i; j--) {
      if (i % 2 != j % 2) {
        continue;
      }
      for (int k = 0; k < v[j].size(); k++) {
        std::cout << v[j][k] << ' ';
      }
    }
  }
  std::cout << '\n';
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
