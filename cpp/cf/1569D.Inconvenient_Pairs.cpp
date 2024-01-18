#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n), y(m);
  vector<pair<int, int>> ps(k);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> ps[i].first >> ps[i].second;
  }

  ll ans = 0;
  for (int _ = 0; _ < 2; _++) {
    vector<int> cnty(m);
    sort(ps.begin(), ps.end());
    vector<pair<int, int>> bord(k);

    int u = 0;
    while (u < k) {
      int v = u;
      while (v < k && ps[v].first == ps[u].first) {
        v++;
      }
      for (int i = u; i < v; i++) {
        int r = lower_bound(y.begin(), y.end(), ps[i].second) - y.begin();
        int l = r;
        if (y[l] > ps[i].second) {
          l--;
        }
        bord[i] = {l, r};
      }
      for (int i = u; i < v; i++) {
        if (bord[i].first < bord[i].second) {
          ans += cnty[bord[i].first];
        }
      }
      for (int i = u; i < v; i++) {
        if (bord[i].first < bord[i].second) {
          cnty[bord[i].first]++;
        }
      }
      u = v;
    }
    for (int i = 0; i < k; i++) {
      swap(ps[i].first, ps[i].second);
    }
    swap(x, y);
    swap(n, m);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
