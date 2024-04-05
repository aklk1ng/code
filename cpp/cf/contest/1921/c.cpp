#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll n, f, a, b;
  std::cin >> n >> f >> a >> b;
  std::vector<int> m(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> m[i];
  }

  for (int i = 1; i <= n; i++) {
    f -= std::min(a * (m[i] - m[i - 1]), b);
  }
  std::cout << (f > 0 ? "YES" : "NO") << '\n';
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
