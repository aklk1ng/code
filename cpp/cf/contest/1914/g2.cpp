#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;

int add(int x, int y) { return ((x + y) % mod + mod) % mod; }

int mul(int x, int y) { return (x * 1ll * y) % mod; }

mt19937_64 rnd(98275314);

ll gen() {
  ll x = 0;
  while (x == 0) {
    x = rnd();
  }
  return x;
}

void solve() {
  int n;
  cin >> n;
  vector<int> c(2 * n), g(2 * n, -1);
  for (int i = 0; i < 2 * n; i++) {
    cin >> c[i];
    c[i]--;
  }
  vector<ll> val(n);
  for (int i = 0; i < n; i++) {
    val[i] = gen();
  }

  auto cal = [&](int l, int r) {
    int ans = 0;
    while (l < r) {
      if (g[l] != -1 && g[l] < r) {
        l = g[l];
      } else {
        ans++;
        l++;
      }
    }
    return ans;
  };
  map<ll, int> last;
  ll cur = 0;
  last[0] = 0;
  int size = 0, cnt = 1;
  for (int i = 0; i < 2 * n; i++) {
    cur ^= val[c[i]];
    if (cur == 0) {
      size++;
      cnt = mul(cnt, cal(last[0], i + 1));
      last.clear();
    } else if (last.count(cur)) {
      g[last[cur]] = i + 1;
    }
    last[cur] = i + 1;
  }
  cout << size << ' ' << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
