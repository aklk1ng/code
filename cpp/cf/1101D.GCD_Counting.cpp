#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

int n;
std::vector<int> a;
std::vector<std::vector<int>> g;
std::vector<std::vector<std::pair<int, int>>> dp(N);
int ans;

void cal(int v, int p = -1) {
  std::vector<std::pair<int, int>> ch;
  for (auto &u : g[v]) {
    if (u != p) {
      cal(u, v);
      for (auto &it : dp[u]) {
        ch.push_back(it);
      }
    }
  }
  std::sort(ch.begin(), ch.end());
  for (int i = 0; i < (int)ch.size(); i++) {
    int j = i - 1;
    int mx1 = 0, mx2 = 0;
    while (j + 1 < (int)ch.size() && ch[j + 1].first == ch[i].first) {
      j++;
      if (ch[j].second >= mx1) {
        mx2 = mx1;
        mx1 = ch[j].second;
      } else if (ch[j].second > mx2) {
        mx2 = ch[j].second;
      }
    }
    if (a[v] % ch[i].first == 0) {
      ans = std::max(ans, mx1 + mx2 + 1);
      dp[v].push_back({ch[i].first, mx1 + 1});
      while (a[v] % ch[i].first == 0) {
        a[v] /= ch[i].first;
      }
    } else {
      ans = std::max(ans, mx1);
    }
    i = j;
  }

  for (int i = 2; i * i <= a[v]; i++) {
    if (a[v] % i == 0) {
      dp[v].push_back({i, 1});
      ans = std::max(ans, 1);
      while (a[v] % i == 0) {
        a[v] /= i;
      }
    }
  }

  if (a[v] > 1) {
    dp[v].push_back({a[v], 1});
    ans = std::max(ans, 1);
  }
}

void solve() {
  std::cin >> n;
  a.resize(n);
  g.resize(n + 1, std::vector<int>());
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  ans = 0;
  cal(0);
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
