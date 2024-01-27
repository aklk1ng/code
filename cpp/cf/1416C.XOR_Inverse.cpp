#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 5e6 + 5;

std::vector dp(2, std::vector<ll>(30));
std::vector t(2, std::vector<int>(N));
std::vector g(N, std::vector<int>());
int id = 1;

void add(int x, int pos) {
  int v = 0;
  for (int i = 29; i >= 0; i--) {
    int j = ((x >> i) & 1);
    if (!t[j][v]) {
      t[j][v] = id++;
    }
    v = t[j][v];
    g[v].push_back(pos);
  }
}

void go(int v, int b = 29) {
  int l = t[0][v], r = t[1][v];
  if (l) {
    go(l, b - 1);
  }
  if (r) {
    go(r, b - 1);
  }
  if (!l || !r) {
    return;
  }
  ll res = 0;
  int cur = 0;
  for (auto &x : g[l]) {
    while (cur < int(g[r].size()) && g[r][cur] < x) {
      cur++;
    }
    res += cur;
  }
  dp[0][b] += res;
  dp[1][b] += int(g[l].size()) * 1LL * int(g[r].size()) - res;
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    add(x, i);
  }
  go(0);

  ll inv = 0;
  int ans = 0;
  for (int i = 0; i <= 29; i++) {
    inv += std::min(dp[0][i], dp[1][i]);
    if (dp[1][i] < dp[0][i]) {
      ans += (1 << i);
    }
  }

  std::cout << inv << ' ' << ans << '\n';
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
