#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> T(N, 1);
  for (int i = 0; i < Q; i++) {
    int t;
    std::cin >> t;
    T[t - 1] ^= 1;
  }

  std::cout << std::accumulate(T.begin(), T.end(), 0) << '\n';
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
