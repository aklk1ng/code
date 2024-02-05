#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector a(n, std::vector<int>(m, 1));
  ll ans = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (!x) {
        for (int k = 1;; k++) {
          int nx = x + k / 2, ny = y + (k + 1) / 2;
          if (nx == n || ny == m) {
            break;
          }
          ans += k;
        }
      }
      if (!y) {
        for (int k = 1;; k++) {
          int nx = x + (k + 1) / 2, ny = y + k / 2;
          if (nx == n || ny == m) {
            break;
          }
          ans += k;
        }
      }
    }
  }
  ans += n * m;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    for (int c = 0; c < 2; c++) {
      int l = 1, r = 1;
      while (true) {
        int nx = x + (l + c) / 2, ny = y + (l + !c) / 2;
        if (nx == n || ny == m || a[nx][ny] == 0) {
          break;
        }
        l++;
      }
      while (true) {
        int nx = x - (r + !c) / 2, ny = y - (r + c) / 2;
        if (nx < 0 || ny < 0 || a[nx][ny] == 0) {
          break;
        }
        r++;
      }
      if (!a[x][y]) {
        ans += l * r;
      } else {
        ans -= l * r;
      }
    }
    ans += a[x][y];
    a[x][y] ^= 1;
    ans -= a[x][y];
    std::cout << ans << '\n';
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
