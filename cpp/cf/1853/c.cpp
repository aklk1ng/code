#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll j = 0, x = 1;
  while (k--) {
    while (j < n && a[j] <= x + j) {
      j++;
    }
    x += j;
  }
  std::cout << x << '\n';
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
