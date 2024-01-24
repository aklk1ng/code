#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, w, h;
  std::cin >> n >> w >> h;
  std::vector<int> g(n), p(n), t(n);
  std::vector s(2 * N, std::vector<int>());
  for (int i = 0; i < n; i++) {
    std::cin >> g[i] >> p[i] >> t[i];
    s[p[i] - t[i] + N].push_back(i);
  }

  std::vector<int> xs, ys, ans_x(N), ans_y(N);
  for (int i = 0; i < 2 * N; i++) {
    if (!s[i].empty()) {
      for (auto &u : s[i]) {
        if (g[u] == 1) {
          xs.push_back(p[u]);
        } else {
          ys.push_back(p[u]);
        }
      }
      std::sort(xs.begin(), xs.end());
      std::sort(ys.begin(), ys.end());
      std::sort(s[i].begin(), s[i].end(), [&](int u, int v) {
        if (g[u] != g[v]) {
          return (g[u] == 2);
        } else {
          return (g[u] == 2 ? p[u] > p[v] : p[u] < p[v]);
        }
      });
      for (int j = 0; j < (int)xs.size(); j++) {
        ans_x[s[i][j]] = xs[j];
        ans_y[s[i][j]] = h;
      }
      for (int j = 0; j < (int)ys.size(); j++) {
        ans_x[s[i][j + xs.size()]] = w;
        ans_y[s[i][j + xs.size()]] = ys[ys.size() - j - 1];
      }
      xs.clear();
      ys.clear();
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << ans_x[i] << ' ' << ans_y[i] << '\n';
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
