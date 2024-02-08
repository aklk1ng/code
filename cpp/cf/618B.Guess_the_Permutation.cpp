#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(n + 1, std::vector<int>(n + 1));
  std::vector<bool> done(n + 1);
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= n; i++) {
      if (done[i]) {
        continue;
      }
      bool good = true;
      for (int j = 1; j <= n; j++) {
        good = good && (a[i][j] <= x);
      }
      if (good) {
        ans[i] = x;
        done[i] = true;
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
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
