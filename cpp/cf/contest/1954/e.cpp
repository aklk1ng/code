#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int mx = *std::max_element(a.begin(), a.end());
  std::vector<ll> pr(mx + 1);
  for (int i = 0; i < n; i++) {
    int c = 0;
    if (!i || a[i] > a[i - 1]) {
      c++;
    }
    if (i + 1 < n && a[i] < a[i + 1]) {
      c--;
    }
    pr[a[i]] += c;
  }
  for (int i = 0; i < mx; i++) {
    pr[i + 1] += pr[i];
  }
  for (int i = 1; i <= mx; i++) {
    ll ans = 0;
    for (int j = 1, val = 1; j <= mx; j += i, val++) {
      ans += val * 1LL * (pr[std::min(mx, j + i - 1)] - pr[j - 1]);
    }
    std::cout << ans << " \n"[i == mx];
  }
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
