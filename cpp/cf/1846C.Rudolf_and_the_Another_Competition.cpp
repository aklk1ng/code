#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::pair<int, ll> r;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    std::vector<int> cur(m);
    for (int j = 0; j < m; j++) {
      std::cin >> cur[j];
    }
    std::sort(cur.begin(), cur.end());
    int cnt = 0;
    ll p = 0, sum = 0;
    for (int j = 0; j < m; j++) {
      if (sum + cur[j] > h) {
        break;
      }
      sum += cur[j];
      p += sum;
      cnt++;
    }
    if (i) {
      if (std::make_pair(-cnt, p) < r) {
        ans++;
      }
    } else {
      r = {-cnt, p};
    }
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
