#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> L, R;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    L.push_back(v[i].first);
    R.push_back(v[i].second);
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  int ans = n - 1;
  for (auto &[l, r] : v) {
    int lf = lower_bound(R.begin(), R.end(), l) - R.begin();
    int rg = max(0, n - int(upper_bound(L.begin(), L.end(), r) - L.begin()));
    ans = min(ans, lf + rg);
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
