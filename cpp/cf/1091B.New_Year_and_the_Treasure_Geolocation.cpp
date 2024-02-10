#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> o(n), t(n);
  for (int i = 0; i < n; i++) {
    std::cin >> o[i].first >> o[i].second;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> t[i].first >> t[i].second;
  }
  std::sort(o.begin(), o.end());
  std::sort(t.begin(), t.end());
  std::reverse(t.begin(), t.end());

  std::vector<std::pair<int, int>> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = {o[i].first + t[i].first, o[i].second + t[i].second};
  }
  std::sort(ans.begin(), ans.end());
  std::cout << ans[0].first << ' ' << ans[0].second << '\n';
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
