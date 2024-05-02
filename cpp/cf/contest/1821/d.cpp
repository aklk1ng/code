#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> r[i];
  }

  int ans = INT_MAX;
  int cnt = 0, len = 0;
  for (int i = 0; i < n; i++) {
    int cur = r[i] - l[i] + 1;
    if (cur > 1) {
      len += cur;
    } else {
      cnt++;
    }

    if (len < k) {
      if (len + cnt >= k) {
        ans = std::min(ans, r[i] + 2 * ((i + 1 - cnt) + (k - len)));
      }
    } else {
      ans = std::min(ans, r[i] - (len - k) + 2 * (i + 1 - cnt));
      break;
    }
  }
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
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
