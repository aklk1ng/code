#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> pre(N), suf(N);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre[1] = a[1];
  suf[n] = a[n];
  for (int i = 2; i <= n; i++) {
    pre[i] = __gcd(pre[i - 1], a[i]);
  }
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = __gcd(suf[i + 1], a[i]);
  }

  ll ans = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (i == 0) {
      ans = suf[2];
    } else if (i == n - 1) {
      ans = ans * pre[n - 1] / __gcd(pre[n - 1], ans);
    } else {
      ans = ans * __gcd(pre[i], suf[i + 2]) / __gcd(__gcd(pre[i], suf[i + 2]), ans);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
