#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 1e6 + 7;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

void solve() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> s(h);
  for (int i = 0; i < h; i++) {
    std::cin >> s[i];
  }

  std::vector<std::vector<int>> e(N);
  std::vector<int> vis(N, -1);
  int cnt = 0;
  auto check = [&](int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; };
  auto dfs = [&](auto self, int u, int v) -> void {
    if (vis[v] == u) {
      return;
    }
    vis[v] = u;
    cnt++;
    int sz = e[v].size();
    for (int i = 0; i < sz; i++) {
      self(self, u, e[v][i]);
    }
  };
  int ans = 0;
  bool ok = false;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      ok = true;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (check(nx, ny)) {
          e[i * w + j].push_back(nx * w + ny);
          if (s[nx][ny] == '#') {
            ok = false;
          }
        }
      }
      if (!ok) {
        e[i * w + j].clear();
        continue;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.' && (vis[i * w + j] < 0)) {
        cnt = 0;
        dfs(dfs, i * w + j, i * w + j);
        ans = std::max(ans, cnt);
      }
    }
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
