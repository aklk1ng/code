#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
const int INF = 1e9 + 7;

void solve() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<int> xs(q), ys(q);
  for (int i = 0; i < q; i++) {
    cin >> xs[i] >> ys[i];
  }

  int ans = 1;
  set<int> ux, uy;
  for (int i = q - 1; i >= 0; i--) {
    bool ok = false;
    if (!ux.count(xs[i])) {
      ux.insert(xs[i]);
      ok = true;
    }
    if (!uy.count(ys[i])) {
      uy.insert(ys[i]);
      ok = true;
    }
    if (ok) {
      ans = ans * 1LL * k % mod;
    }
    if ((int)ux.size() == n || (int)uy.size() == m) {
      break;
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
  while (tt--) {
    solve();
  }

  return 0;
}
