#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end());
  std::vector<int> ans(n + 1);
  int l = 0, r = n - 1, sz = n;
  while (l <= r) {
    if ((a[r].first == n - l) ^ (a[l].first == n - 1 - r)) {
      if (a[r].first == n - l) {
        ans[a[r--].second] = sz--;
      } else {
        ans[a[l++].second] = -(sz--);
      }
    } else {
      std::cout << "NO\n";
      return;
    }
  }

  std::cout << "YES\n";
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
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
