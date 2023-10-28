#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  ll k, n, a, b;
  cin >> k >> n >> a >> b;
  k -= n * a;
  if (k > 0) {
    cout << n << '\n';
  } else {
    k = -k;
    ll diff = a - b;
    ll turns = (k + diff) / diff;
    if (turns > n) {
      cout << -1 << '\n';
    } else {
      cout << n - turns << '\n';
    }
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
