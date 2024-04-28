#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;

  int i = 0;
  while (1 << (i + 1) <= k) {
    i++;
  }

  std::vector<int> ans{k - (1 << i), k + 1, k + 1 + (1 << i)};
  for (int j = 0; j < 20; j++) {
    if (i != j) {
      ans.push_back(1 << j);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &e : ans) {
    std::cout << e << " \n"[e == ans.back()];
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
