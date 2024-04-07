#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end());
  std::vector<int> nxt(n + 1), ans(n + 1);
  std::vector<ll> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    if (nxt[i - 1] >= i) {
      nxt[i] = nxt[i - 1];
      sum[i] = sum[i - 1];
    } else {
      sum[i] = sum[i - 1] + a[i].first;
      nxt[i] = i;
      while (nxt[i] + 1 <= n && sum[i] >= a[nxt[i] + 1].first) {
        nxt[i]++;
        sum[i] += a[nxt[i]].first;
      }
    }
    ans[a[i].second] = nxt[i];
  }

  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] - 1 << " \n"[i == n];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t = 1;
  if (true) {
    std::cin >> t;
  }
  while (t--) {
    solve();
  }

  return 0;
}
