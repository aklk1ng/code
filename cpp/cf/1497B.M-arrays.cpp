#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cnt[x % m]++;
  }
  int ans = 0;
  for (auto &[k, v] : cnt) {
    if (!k || 2 * k == m) {
      ans++;
    } else if (2 * k < m || cnt.find(m - k) == cnt.end()) {
      int x = cnt[m - k];
      ans += 1 + std::max(0, std::abs(v - x) - 1);
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
