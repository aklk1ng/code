#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int M = 30;
const int N = 1e5 + 5;

std::vector pref(M, std::vector(N, std::vector<int>(2)));
std::vector suff(M, std::vector(N, std::vector<int>(2)));

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < M; i++) {
    suff[i][n + 1][0] = suff[i][n + 1][1] = 0;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 1; j <= n; j++) {
      int t = !!(a[j] & (1 << i));
      for (int k = 0; k < 2; k++) {
        pref[i][j][k] = (t == k) + pref[i][j - 1][k ^ t];
      }
    }
    for (int j = n; j >= 1; j--) {
      int t = !!(a[j] & (1 << i));
      for (int k = 0; k < 2; k++) {
        suff[i][j][k] = (t == k) + suff[i][j + 1][k ^ t];
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int t = 31 - __builtin_clz(a[i]);
    ans += 1LL * pref[t][i - 1][1] * (1 + suff[t][i + 1][0]);
    ans += 1LL * (1 + pref[t][i - 1][0]) * suff[t][i + 1][1];
  }
  std::cout << ans << '\n';
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
