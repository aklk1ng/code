#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  ll ans = 0, sum = 0;
  set<pair<int, int>> s;
  for (int i = n - 1; i >= 0; i--) {
    s.insert({a[i].second, i});
    sum += a[i].second;
    while ((int)s.size() > k) {
      auto it = s.begin();
      sum -= it->first;
      s.erase(it);
    }
    ans = max(ans, sum * a[i].first);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
