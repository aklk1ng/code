#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, l;
  std::cin >> n >> l;
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].second >> v[i].first;
  }

  std::sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    std::multiset<int> s;
    int cur = 0;
    for (int j = i; j < n; j++) {
      s.insert(v[j].second);
      cur += v[j].second;
      while (!s.empty() && v[j].first - v[i].first + cur > l) {
        int mx = *s.rbegin();
        cur -= mx;
        s.extract(mx);
      }
      ans = std::max(ans, (int)s.size());
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
