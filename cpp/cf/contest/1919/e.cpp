#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

vector<ll> fact(N * 2), ifact(N * 2);
vector<int> f(N * 2), d(N * 2);
int n;
void init() {
  fact[0] = 1;
  for (int i = 1; i < N * 2; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  ifact[0] = ifact[1] = 1;
  for (int i = 2; i < N * 2; i++) {
    ifact[i] = mod - mod / i * ifact[mod % i] % mod;
  }
  for (int i = 2; i < N * 2; i++) {
    ifact[i] = ifact[i - 1] * ifact[i] % mod;
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n * 2 + 5; i++) {
    f[i] = 0;
  }
  n++;
  for (int i = 1; i < n; i++) {
    int s;
    cin >> s;
    f[s + n]++;
  }
  f[n]++;
  int mi = INF, mx = -INF;
  for (int i = 0; i <= 2 * n; i++) {
    if (f[i]) {
      mi = min(mi, i);
      mx = max(mx, i);
    }
  }
  bool bad = false;
  for (int i = mi; i <= mx; i++) {
    if (!f[i]) {
      bad = false;
      break;
    }
  }
  if (bad || mi == mx) {
    cout << 0 << '\n';
    return;
  }

  auto ncr = [&](int t, int r) -> ll {
    if (r < 0 || t < r) {
      return 0;
    }
    return fact[t] * ifact[r] % mod * ifact[t - r] % mod;
  };
  auto cal = [&](int t, int x) -> ll {
    if (t == 0 && x == 0) {
      return 1;
    }
    return ncr(x + t - 1, x);
  };
  ll ans = 0;
  for (int x = mx; x >= mi; x--) {
    d[mx - 1] = f[mx] + (mx > n) - (mx == x);
    for (int i = mx - 2; i >= mi - 1; i--) {
      d[i] = f[i + 1] - d[i + 1] + (i >= x) + (i >= n);
    }
    if (d[mi - 1]) {
      continue;
    }
    ll res = 1;
    for (int i = mx - 1; i >= mi; i--) {
      res = res * cal(d[i], f[i] - d[i]) % mod;
    }
    ans += res;
    if (ans >= mod) {
      ans -= mod;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  init();
  while (tt--) {
    solve();
  }

  return 0;
}
