#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> vis(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '*') {
        vis[i][j] = 1;
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        continue;
      }
      int len = 0;
      while (j > len && j + len + 1 < m && i > len) {
        if (!vis[i - len - 1][j - len - 1] || !vis[i - len - 1][j + len + 1]) {
          break;
        }
        len++;
      }
      if (len >= k) {
        for (int d = 0; d <= len; d++) {
          vis[i - d][j - d] = 2;
          vis[i - d][j + d] = 2;
        }
      }
    }
  }

  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 1) {
        ok = false;
      }
    }
  }

  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
