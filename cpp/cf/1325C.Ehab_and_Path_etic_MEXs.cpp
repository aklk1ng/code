#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans(n, -1);
  std::vector v(n + 1, std::vector<int>());
  for (int i = 1; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    v[a].push_back(i);
    v[b].push_back(i);
  }

  std::pair<int, int> mx{0, 0};
  for (int i = 1; i <= n; i++) {
    mx = std::max(mx, {(int)v[i].size(), i});
  }
  int cur = 0;
  for (auto &e : v[mx.second]) {
    ans[e] = cur++;
  }
  for (int i = 1; i < n; i++) {
    if (ans[i] == -1) {
      ans[i] = cur++;
    }
    std::cout << ans[i] << '\n';
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
