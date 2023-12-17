#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> pr;
  ll ans = 1LL * n * n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }
    reverse(v.begin(), v.end());
    if (is_sorted(v.begin(), v.end())) {
      pr.emplace_back(v[0], v.back());
    }
  }
  sort(pr.begin(), pr.end());
  for (int i = 0; i < (int)pr.size(); i++) {
    ans -= pr.end() - lower_bound(pr.begin(), pr.end(), pair<int, int>(pr[i].second, -1));
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
