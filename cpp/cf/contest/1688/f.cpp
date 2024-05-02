#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<ll> a(n + 1);
  std::vector<int> deg(m, 2), b(n + 1), id(n + 1);
  std::vector<std::pair<int, int>> p(m);
  std::vector<std::vector<int>> e(n + 1);
  std::iota(id.begin(), id.end(), 0);
  std::set<int> s(id.begin(), id.end());
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    auto &[l, r] = p[i];
    std::cin >> l >> r;
    e[l - 1].push_back(i);
    e[r].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    a[i] -= b[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  std::queue<int> q;
  for (int i = 0; i <= n; i++) {
    if (!a[i]) {
      q.push(i);
      s.erase(i);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto &y : e[x]) {
      if (!--deg[y]) {
        auto [l, r] = p[y];
        auto lt = s.lower_bound(l), rt = s.upper_bound(r);
        for (auto it = lt; it != rt; it++) {
          q.push(*it);
        }
        s.erase(lt, rt);
      }
    }
  }
  std::cout << (s.empty() ? "YES" : "NO") << '\n';
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
