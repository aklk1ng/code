#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int x = *std::min_element(a.begin(), a.end()),
      y = *std::max_element(a.begin(), a.end());
  std::vector<int> ans;

  while (x != y) {
    ans.push_back(x % 2);
    x = (x + ans.back()) / 2;
    y = (y + ans.back()) / 2;
  }

  std::cout << ans.size() << '\n';
  if ((int)ans.size() <= n) {
    for (auto &e : ans) {
      std::cout << e << " \n"[e == ans.back()];
    }
  }
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
