#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

std::vector<ll> fact(N);
void init() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> x(m);
  for (int i = 0; i < n; i++) {
    int s;
    std::cin >> s;
    for (int j = 0; j < s; j++) {
      int t;
      std::cin >> t;
      x[t - 1].push_back(i);
    }
  }
  for (int i = 0; i < m; i++) {
    sort(x[i].begin(), x[i].end());
  }
  sort(x.begin(), x.end());

  ll ans = 1, sm = 1;
  for (int i = 1; i < m; i++) {
    if (x[i] == x[i - 1]) {
      sm++;
    } else {
      ans = (ans * fact[sm]) % mod;
      sm = 1;
    }
  }
  ans = (ans * fact[sm]) % mod;
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
  init();
  while (T--) {
    solve();
  }

  return 0;
}
