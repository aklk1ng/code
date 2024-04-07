#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int l = 0, r = 0;
  while (l < n && a[l] == a[0]) {
    l++;
  }
  while (r < n && a[n - r - 1] == a[n - 1]) {
    r++;
  }

  int ans = n;
  if (a[0] == a[n - 1]) {
    ans -= l;
    ans -= r;
  } else {
    ans -= std::max(l, r);
  }

  std::cout << std::max(0, ans) << '\n';
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
