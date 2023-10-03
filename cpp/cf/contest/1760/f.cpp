#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int l = 0, r = d + 2;
  while (l + 1 != r) {
    int m = l + (r - l) / 2;
    ll tot = 0;
    for (int i = 0; i < d; i++) {
      if (i % m < n) {
        tot += a[i % m];
      }
    }
    if (tot >= c) {
      l = m;
    } else {
      r = m;
    }
  }
  if (l == d + 1) {
    cout << "Infinity\n";
  } else if (l == 0) {
    cout << "Impossible\n";
  } else {
    cout << l - 1 << '\n';
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
