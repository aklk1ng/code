#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  int l = 1, r = n;
  std::vector<int> ans(n);
  for (int i = 0; i < k; i++) {
    for (int j = i; j < n; j += k) {
      if (i % 2 == 0) {
        ans[j] = l++;
      } else {
        ans[j] = r--;
      }
    }
  }

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
