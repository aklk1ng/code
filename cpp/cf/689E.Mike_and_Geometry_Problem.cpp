#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> f(n + 1), c(n + 1);
  std::map<int, int> s;

  f[0] = c[0] = 1;
  auto pow = [&](int a, int b) {
    int res = 1;
    while (b) {
      if (b & 1) {
        res = (1LL * res * a) % mod;
      }
      a = (1LL * a * a) % mod;
      b /= 2;
    }
    return res;
  };
  auto cal = [&](int a, int b) {
    int res = (1LL * f[a] * c[b]) % mod;
    return (1LL * res * c[a - b]) % mod;
  };

  for (int i = 1; i <= n; i++) {
    f[i] = (1LL * f[i - 1] * i) % mod;
    c[i] = pow(f[i], mod - 2);
  }
  for (int i = 1; i <= n; i++) {
    int a, b;
    std::cin >> a >> b;
    s[a]++, s[b + 1]--;
  }
  int l = s.begin()->first;
  int ans = 0;
  int sum = 0;
  for (auto &[x, y] : s) {
    int dist = x - l;
    if (sum >= k) {
      ans += (1LL * cal(sum, k) * dist) % mod;
    }
    ans = (ans >= mod ? ans - mod : ans);
    sum += y;
    l = x;
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
