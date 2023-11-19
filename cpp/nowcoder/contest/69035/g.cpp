#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;

  if (n > 1 && m == 1) {
    cout << -1 << '\n';
    return;
  }
  if (n == m) {
    cout << 1 << '\n';
    return;
  }
  ll ans = 0;
  n -= m;
  ans++;
  ans += (n / (m - 1)) * 2;
  ans += n % (m - 1) ? 2 : 0;
  cout << ans << '\n';
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
