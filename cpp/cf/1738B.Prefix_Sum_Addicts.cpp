#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> s(n + 1);
  for (int i = n - k + 1; i <= n; i++) {
    std::cin >> s[i];
  }
  if (k == 1) {
    std::cout << "YES\n";
    return;
  }
  std::vector<ll> a(n + 1);
  for (int i = n - k + 2; i <= n; i++) {
    a[i] = s[i] - s[i - 1];
  }
  if (!std::is_sorted(a.begin() + n - k + 2, a.end()) ||
      (s[n - k + 1] > a[n - k + 2] * (n - k + 1))) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "Yes\n";
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
