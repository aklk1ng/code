#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  map<pair<int, int>, set<ll>> m;
  ll tot = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
      int a = y1 - y2, b = x1 - x2;
      int d = __gcd(a, b);
      a /= d;
      b /= d;
      if (a < 0 || (a == 0 && b < 0)) {
        a = -a;
        b = -b;
      }

      pair<int, int> t(a, b);
      ll c = 1LL * a * x1 - 1LL * b * y1;
      if (!m[t].count(c)) {
        tot++;
        m[t].insert(c);
        ans += tot - m[t].size();
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
