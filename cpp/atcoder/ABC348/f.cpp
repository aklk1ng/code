#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int n = 2000;

void solve() {
  int N, M;
  std::cin >> N >> M;
  std::vector A(N, std::vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> A[i][j];
    }
  }

  std::vector<std::bitset<n>> bt(N), bs(n);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      bs[A[j][i]].set(j);
    }
    for (int j = 0; j < N; j++) {
      bt[j] ^= bs[A[j][i]];
    }
    for (int j = 0; j < N; j++) {
      bs[A[j][i]].reset(j);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += bt[i].count();
  }
  if (M & 1) {
    ans -= N;
  }
  std::cout << ans / 2 << '\n';
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
