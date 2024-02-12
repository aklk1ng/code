#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int k = 0;
  int m = 1e9;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    m = std::min(m, a[i]);
  }
  std::vector<int> b(a);
  std::sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i] && a[i] % m > 0) {
      k = 1;
    }
  }
  std::cout << (k ? "NO" : "YES") << '\n';
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
