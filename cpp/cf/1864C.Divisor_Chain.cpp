#include <bits/stdc++.h>
typedef long long ll;

#define bit(mask, pos) ((mask >> pos) & 1)

void solve() {
  int x;
  std::cin >> x;
  int p;
  std::vector<int> ans;
  ans.push_back(x);
  for (int i = 0;; i++) {
    if (bit(x, i)) {
      if (x == (1 << i)) {
        p = i;
        break;
      }
      x -= (1 << i);
      ans.push_back(x);
    }
  }
  while (p > 0) {
    x -= (1 << (p - 1));
    ans.push_back(x);
    p--;
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
