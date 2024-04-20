#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int N;
  std::cin >> N;
  std::map<int, int> m;
  for (int i = 0; i < N; i++) {
    int A, C;
    std::cin >> A >> C;
    if (m.count(C)) {
      m[C] = std::min(m[C], A);
    } else {
      m[C] = A;
    }
  }

  int ans = -1;
  for (auto &[x, y] : m) {
    ans = std::max(ans, y);
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
