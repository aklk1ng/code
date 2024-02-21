#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int f = 0;
  for (int i = 1; i <= m; i++) {
    int a;
    std::cin >> a;
    if (a == (n + k - 1) / k) {
      f++;
    }
    if (a > (n + k - 1) / k) {
      f = 1 << 30;
    }
  }
  std::cout << (f <= (n - 1) % k + 1 ? "YES" : "NO") << '\n';
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
