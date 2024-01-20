#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int INF = 1e9 + 7;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i].second;
  }
  sort(p.begin(), p.end());

  ordered_set s;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = s.order_of_key(make_pair(p[i].second + 1, -1));
    ans += 1LL * cnt * p[i].first;
    s.insert({p[i].second, i});
  }
  s.clear();
  for (int i = n - 1; i >= 0; i--) {
    int cnt = (int)s.size() - s.order_of_key(make_pair(p[i].second - 1, n));
    ans -= 1LL * cnt * p[i].first;
    s.insert({p[i].second, i});
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
