#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 5e5 + 5;
const int k = 750;

void solve() {
  int q;
  std::cin >> q;
  std::vector<int> a(N);
  std::vector sum(k, std::vector<int>(k));
  while (q--) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i < k; i++) {
        sum[i][x % i] += y;
      }
    } else {
      if (x >= k) {
        int ans = 0;
        for (int i = y; i <= 5e5; i += x) {
          ans += a[i];
        }
        std::cout << ans << '\n';
      } else {
        std::cout << sum[x][y] << '\n';
      }
    }
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
