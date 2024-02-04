#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(n, std::vector<int>(n)), dp(n + 1, std::vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  auto add = [&](int x, int y) {
    x += y;
    while (x >= mod) {
      x -= mod;
    }
    while (x < 0) {
      x += mod;
    }
    return x;
  };
  auto check = [&](int cnt, int lst) {
    for (int i = 0; i < cnt; i++) {
      if (a[i][cnt - 1] == 0) {
        continue;
      }
      if ((a[i][cnt - 1] == 1 && lst > i) || (a[i][cnt - 1] == 2 && lst <= i)) {
        return false;
      }
    }
    return true;
  };
  if (a[0][0] != 2) {
    dp[1][0] = 2;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int &k : std::vector<int>({j, i})) {
        if (check(i + 1, k)) {
          dp[i + 1][k] = add(dp[i + 1][k], dp[i][j]);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = add(ans, dp[n][i]);
  }
  std::cout << ans << '\n';
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
