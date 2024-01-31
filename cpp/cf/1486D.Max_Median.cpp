#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int l = 1, r = n + 1;
  while (l + 1 != r) {
    int m = (l + r) / 2;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
      if (a[i] >= m) {
        b[i] = 1;
      } else {
        b[i] = -1;
      }
    }
    for (int i = 1; i < n; i++) {
      b[i] += b[i - 1];
    }
    int mx = b[k - 1], mi = 0;
    for (int i = k; i < n; i++) {
      mi = std::min(mi, b[i - k]);
      mx = std::max(mx, b[i] - mi);
    }
    if (mx > 0) {
      l = m;
    } else {
      r = m;
    }
  }

  std::cout << l << '\n';
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
