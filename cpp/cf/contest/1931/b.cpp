#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int k = std::accumulate(a.begin(), a.end(), 0) / n;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < k) {
      std::cout << "NO\n";
      return;
    }
    a[i + 1] += a[i] - k;
    a[i] = k;
  }
  std::cout << "YES\n";
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
