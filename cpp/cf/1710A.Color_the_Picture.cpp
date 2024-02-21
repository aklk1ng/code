#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i];
  }

  bool ok = false;
  ll tot = 0;
  for (int i = 1; i <= k; i++) {
    if (a[i] / n > 2) {
      ok = true;
    }
    if (a[i] / n >= 2) {
      tot += a[i] / n;
    }
  }
  if (tot >= m && (ok || m % 2 == 0)) {
    std::cout << "YES\n";
    return;
  }
  ok = false;
  tot = 0;
  for (int i = 1; i <= k; i++) {
    if (a[i] / m > 2) {
      ok = true;
    }
    if (a[i] / m >= 2) {
      tot += a[i] / m;
    }
  }
  if (tot >= n && (ok || n % 2 == 0)) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
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
