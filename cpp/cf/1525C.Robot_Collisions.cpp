#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

struct bot {
  int x, d;
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<bot> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x;
  }
  for (int i = 0; i < n; i++) {
    char c;
    std::cin >> c;
    a[i].d = c == 'L' ? -1 : 1;
  }
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(),
            [&](int x, int y) { return a[x].x < a[y].x; });
  std::vector<int> ans(n, -1);
  std::vector<std::vector<int>> par(2);
  for (auto &i : ord) {
    int p = a[i].x % 2;
    if (a[i].d == -1) {
      if (par[p].empty()) {
        par[p].push_back(i);
      } else {
        int j = par[p].back();
        par[p].pop_back();
        ans[i] = ans[j] = (a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
      }
    } else {
      par[p].push_back(i);
    }
  }
  for (int p = 0; p < 2; p++) {
    while ((int)par[p].size() > 1) {
      int i = par[p].back();
      par[p].pop_back();
      int j = par[p].back();
      par[p].pop_back();
      ans[i] = ans[j] = (2 * m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x)) / 2;
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
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
