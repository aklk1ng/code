#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    int l;
    std::cin >> l;
    if (l < n) {
      cnt[l]++;
    } else {
      cnt[n] = 1e6;
    }
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > cnt[i - 1]) {
      ok = false;
      break;
    }
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
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
