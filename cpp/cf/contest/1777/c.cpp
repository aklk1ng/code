#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e5;

std::vector<std::vector<int>> fa(N + 5);

void init() {
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fa[j].push_back(i);
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    v.push_back({x, i});
  }

  std::sort(v.begin(), v.end());
  std::vector<int> cnt(m + 5);
  int cur = 0;
  int j = 0;
  ll ans = LONG_MAX;
  for (int i = 0; i < n; i++) {
    for (auto &x : fa[v[i].first]) {
      if (x > m) {
        break;
      }
      if (!cnt[x]++) {
        cur++;
      }
    }
    while (cur == m) {
      int tmp = v[i].first - v[j].first;
      if (tmp < ans) {
        ans = tmp;
      }
      for (auto &x : fa[v[j].first]) {
        if (x > m) {
          break;
        }
        if (--cnt[x] == 0) {
          cur--;
        }
      }
      j++;
    }
  }
  std::cout << (ans >= LONG_MAX ? -1 : ans) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  init();
  while (T--) {
    solve();
  }

  return 0;
}
