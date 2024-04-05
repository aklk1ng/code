#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  k++;
  std::vector a(n, std::vector<int>(m));
  std::vector st(n, std::vector<bool>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      std::cin >> c;
      st[i][j] = c == '#';
      a[i][j] = st[i][j];
    }
  }

  auto prov = [&](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
  auto cal = [&]() {
    int cnt = 0;
    std::vector dp(n, std::vector<int>(m)), pref(n, std::vector<int>(m)),
        up(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        up[i][j] = a[i][j];
        if (prov(i - 1, j)) {
          up[i][j] += up[i - 1][j];
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j >= 0; j--) {
        pref[i][j] = a[i][j];
        if (prov(i - 1, j + 1)) {
          pref[i][j] += pref[i - 1][j + 1];
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = up[i][j];
        if (prov(i - k, j)) {
          dp[i][j] -= up[i - k][j];
        }
        if (prov(i, j - 1)) {
          dp[i][j] += dp[i][j - 1];
        }
        if (j < k) {
          int p = j - k + i;
          if (p >= 0) {
            dp[i][j] -= pref[p][0];
          }
        } else {
          dp[i][j] -= pref[i][j - k];
        }
        if (prov(i - k, j)) {
          dp[i][j] += pref[i - k][j];
        }
        cnt = std::max(cnt, dp[i][j]);
      }
    }

    return cnt;
  };

  int mx = cal();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = st[n - i - 1][j];
    }
  }
  mx = std::max(mx, cal());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = st[i][m - j - 1];
    }
  }
  mx = std::max(mx, cal());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = st[n - i - 1][m - j - 1];
    }
  }
  std::cout <<  std::max(mx, cal()) << '\n';
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
