#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll x) {
  ll res = 1;
  while (res <= x) {
    res *= 2;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    cout << i << ' ' << f(x) - x << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
