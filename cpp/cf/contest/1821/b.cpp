#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), a1(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a1[i];
  }

  int diffl = -1, diffr = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != a1[i]) {
      diffr = i;
      if (diffl == -1) {
        diffl = i;
      }
    }
  }
  while (diffl > 0 && a1[diffl - 1] <= a1[diffl]) {
    diffl--;
  }
  while (diffr < n - 1 && a1[diffr + 1] >= a1[diffr]) {
    diffr++;
  }
  std::cout << diffl + 1 << ' '<< diffr + 1 << '\n';
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
