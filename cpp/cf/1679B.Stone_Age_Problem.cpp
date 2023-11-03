#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }

  map<ll, ll> m;
  ll cur = -1;

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll pos, x;
      cin >> pos >> x;
      pos--;
      if (cur == -1) {
        ans -= a[pos];
        ans += x;
        a[pos] = x;
        cout << ans << '\n';
      } else {
        if (m[pos] == 0) {
          ans -= cur;
          ans += x;
          cout << ans << '\n';
          m[pos] = x;
        } else {
          ans -= m[pos];
          ans += x;
          m[pos] = x;
          cout << ans << '\n';
        }
      }
    } else {
      ll x;
      cin >> x;
      ans = n * x;
      cout << ans << '\n';
      m.clear();
      cur = x;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
