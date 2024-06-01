#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n + 1), p(n + 1), dist(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  if (b[p[1]] != p[1]) {
    std::cout << "-1\n";
    return;
  }
  dist[p[1]] = 0;
  for (int i = 2; i <= n; i++) {
    if (dist[b[p[i]]] == -1) {
      std::cout << "-1\n";
      return;
    }
    dist[p[i]] = dist[p[i - 1]] + 1;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << dist[i] - dist[b[i]] << " \n"[i == n];
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
