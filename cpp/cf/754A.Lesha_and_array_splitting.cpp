#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  ll sum = std::accumulate(a.begin(), a.end(), 0);
  if (sum) {
    std::cout << "YES\n";
    std::cout << "1\n";
    std::cout << 1 << ' ' << n << '\n';
    return;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum) {
      std::cout << "YES\n";
      std::cout << "2\n";
      std::cout << 1 << ' ' << i + 1 << '\n';
      std::cout << i + 2 << ' ' << n << '\n';
      return;
    }
  }
  std::cout << "NO\n";
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
