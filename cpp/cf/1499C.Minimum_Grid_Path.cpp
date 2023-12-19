#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> mx(2, 1e9);
  vector<ll> rem(2, n);
  ll sum = 0;
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    mx[i % 2] = min(mx[i % 2], c[i]);
    rem[i % 2]--;
    sum += c[i];
    if (i > 0) {
      ans = min(ans, sum + rem[0] * mx[0] + rem[1] * mx[1]);
    }
  }
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
