#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 2e9;

void solve() {
  int n, m, w;
  cin >> n >> m >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto check = [&](int x) {
    vector<ll> st(n);
    ll cur = 0;
    ll moves = 0;
    for (int i = 0; i < n; i++) {
      cur -= i - w >= 0 ? st[i - w] : 0;
      if (a[i] + cur < x) {
        st[i] = x - a[i] - cur;
        cur += st[i];
        moves += st[i];
      }
      if (moves > m) {
        return false;
      }
    }
    return moves <= m;
  };
  ll l = -1, r = INF;
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
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
