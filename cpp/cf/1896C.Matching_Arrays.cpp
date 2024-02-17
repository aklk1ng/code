#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n), b(n), v(n), ans(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::iota(v.begin(), v.end(), 0);
  std::sort(v.begin(), v.end(), [&](int l, int r) { return a[l] < a[r]; });
  std::sort(b.begin(), b.end());
  for (int i = 0; i < x; i++) {
    ans[v[n - x + i]] = b[i];
  }
  for (int i = x; i < n; i++) {
    ans[v[i - x]] = b[i];
  }
  for (int i = 0; i < n; i++) {
    x -= a[i] > ans[i];
  }
  if (!x) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << " \n"[i == n - 1];
    }
  } else {
    std::cout << "NO\n";
  }
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
