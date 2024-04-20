#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int N;
  std::cin >> N;
  std::vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    std::cin >> X[i] >> Y[i];
  }

  for (int i = 0; i < N; i++) {
    int mx = 0, idx = -1;
    for (int j = 0; j < N; j++) {
      int d = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
      if (d > mx) {
        mx = d;
        idx = j;
      }
    }
    std::cout << idx + 1 << '\n';
  }
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
