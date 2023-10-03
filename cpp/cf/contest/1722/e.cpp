#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  ll n, q;
  cin >> n >> q;
  vector<vector<ll>> a(1005, vector<ll>(1005));
  vector<vector<ll>> pre(1005, vector<ll>(1005));

  for (int i = 0; i < n; i++) {
    ll h, w;
    cin >> h >> w;
    a[h][w] += h * w;
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    }
  }
  while (q--) {
    ll hs, ws, hb, wb;
    cin >> hs >> ws >> hb >> wb;
    cout << pre[hb - 1][wb - 1] - pre[hb - 1][ws] - pre[hs][wb - 1] + pre[hs][ws] << '\n';
  }
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
