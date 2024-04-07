#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::reverse(b.begin(), b.end());

  ll sum = 0, pref = 0;
  for (int i = 0; i < n - k; i++) {
    if (a[i] < b[i]) {
      pref += sum;
      pref += a[i];
      sum = 0;
    } else {
      sum += b[i];
    }
  }

  ll ans = 1e18;
  for (int i = n - k; i < n; i++) {
    ans = std::min(ans, pref + sum + a[i]);
    sum += b[i];
  }
  std::cout << ans << '\n';
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
