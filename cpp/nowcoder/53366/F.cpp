// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

const int N = 1e5 + 10;
std::vector<int> g[N];
std::bitset<N> need;

int n, m;
int dp[N][60]; // dp[x][i]表示在以x为根的子树中,删除i个点的最大贡献(减少的路程)
int s[N];      // s[x]表示以x为根的子树中的需求点的个数
int tot;       // 不删除点时的答案

void dfs(int x, int p) { // parent
  s[x] = need[x];
  for (auto &y : g[x]) {
    if (y == p)
      continue;
    dfs(y, x);
    if (s[y] == 0)
      continue;
    static int f[60];
    std::memset(f, 0, sizeof(f));

    for (int i = 0; i <= std::min(m, s[x] + s[y]); i++) { // s[x]表示从x中删除i个点(dp[x]不完整)
      for (int j = 0; j <= std::min(m, s[x]) && j <= i;
           j++) { // s[y]表示从t子树中删除j个点(dp[y]完整)
        f[i] = std::max(f[i], dp[x][j] + dp[y][i - j] + (i - j == s[y] ? 2 : 0));
      }
    }

    s[x] += s[y];
    tot += 2; // 加上x-y这条边
    std::memcpy(dp[x], f, sizeof(f));
  }
}

void solve() {
  std::cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int k;
  std::cin >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    need[x] = true;
  }
  dfs(1, -1);
  std::cout << tot - dp[1][m] << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
