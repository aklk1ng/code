#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::vector<int> pr(n + 1, 1e9);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = std::min(pr[i], a[i] - i);
  }
  ll sum = std::accumulate(a.begin(), a.end(), 0LL) - 1LL * n * (n - 1) / 2;
  std::vector<ll> ans;
  for (int i = 0; i < q; i++) {
    int k;
    std::cin >> k;
    if (k < n) {
      ans.push_back(std::min(pr[k] + k, a[k]));
      continue;
    }
    if (k % 2 == n % 2) {
      ll ns = sum - 1LL * pr[n] * n;
      ans.push_back(pr[n] + k - (std::max(0LL, (k - n) / 2 - ns) + 1LL * n - 1) / n);
    } else {
      ll mi = std::min(pr[n - 1], a[n - 1] - k);
      ll ns = (sum + (n - 1) - k) - mi * n;
      ans.push_back(mi + k -
                    (std::max(0LL, (k - (n - 1)) / 2 - ns) + 1LL * n - 1) / n);
    }
  }
  for (auto &e : ans) {
    std::cout << e << " \n"[e == ans.back()];
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
