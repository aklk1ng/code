#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
const int INF = 1e9 + 7;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void solve() {
  int n;
  cin >> n;
  ordered_set s;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int less = s.order_of_key(pair<int, int>(x, 0)),
        greater = i - s.order_of_key(pair<int, int>(x, n));
    ans += min(less, greater);
    s.insert(pair<int, int>(x, i));
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
