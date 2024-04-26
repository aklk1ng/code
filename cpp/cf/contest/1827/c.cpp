#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector<int> pa(n + 1);
  for (int i = 0, l = 0, r = 0; i < n; i++) {
    pa[i] = i >= r ? 0 : std::min(pa[l + r - i], r - i);
    while (i + pa[i] < n && i - pa[i] - 1 >= 0 &&
           s[i + pa[i]] == s[i - pa[i] - 1]) {
      pa[i]++;
    }
    if (i + pa[i] > r) {
      l = i - pa[i];
      r = i + pa[i];
    }
  }
  std::vector rm(19, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    rm[0][i] = i - pa[i];
  }
  for (int k = 1; k < 19; k++) {
    for (int i = 0; i + (1 << k) <= n; i++) {
      rm[k][i] = std::min(rm[k - 1][i], rm[k - 1][i + (1 << (k - 1))]);
    }
  }
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    for (int k = 18; k >= 0; k--) {
      if (j + (1 << k) <= n && rm[k][j] > i) {
        j += 1 << k;
      }
    }
    if (2 * j - i <= n) {
      cnt[2 * j - i] += cnt[i] + 1;
    }
  }
  std::cout << std::accumulate(cnt.begin() + 1, cnt.end(), 0LL) << '\n';
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
