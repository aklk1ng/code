#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 2e5 + 5;

ll a[N], dp[N], st[N], top;

void solve() {
  int n = 0;
  while (cin >> a[++n])
    ;
  n--;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int pos =
        upper_bound(st + 1, st + 1 + top, a[i], [](const int &u, const int &v) { return u > v; }) -
        st;
    if (pos == top + 1) {
      top++;
    }
    st[pos] = a[i];
    ans = max(ans, top);
  }
  cout << ans << ' ';

  top = 0;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(st + 1, st + 1 + top, a[i]) - st;
    if (pos == top + 1) {
      top++;
    }
    st[pos] = a[i];
    ans = max(ans, top);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
