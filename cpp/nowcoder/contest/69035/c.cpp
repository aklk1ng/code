#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll tot = 0;
int ans = 0;
int n, p;
vector<ll> a(n), b(n);

void dfs(ll sum, int x) {
  if (x == n) {
    return;
  }
  for (int i = x; i < n; i++) {
    ll diff = a[i] * (ll)pow(p, b[i]);
    sum -= diff;
    if (sum % (p - 1) == tot % (p - 1)) {
      ans++;
    }
    dfs(sum, x + 1);
    sum += diff;
  }
}

void solve() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    tot += a[i] * (ll)pow(p, b[i]);
  }
  dfs(tot, 0);
  cout << ans % mod << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
