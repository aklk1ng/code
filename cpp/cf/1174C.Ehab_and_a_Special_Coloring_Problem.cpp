#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int c = 0;
  std::vector<int> ans(n + 1);
  for (int i = 2; i <= n; i++) {
    if (!ans[i]) {
      ans[i] = ++c;
      for (int j = i; j <= n; j += i) {
        ans[j] = ans[i];
      }
    }
    std::cout << ans[i] << " \n"[i == n];
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
