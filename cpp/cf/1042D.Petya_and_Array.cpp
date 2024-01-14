#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
  int n;
  ll t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> sum(1);
  ll pr = 0;
  for (int i = 0; i < n; i++) {
    pr += a[i];
    sum.push_back(pr);
  }
  sort(sum.begin(), sum.end());
  sum.resize(unique(sum.begin(), sum.end()) - sum.begin());

  ll ans = 0;
  pr = 0;
  vector<int> f(N);
  auto upd = [&](int x) {
    for (int i = x; i < N; i |= i + 1) {
      f[i]++;
    }
  };
  auto get = [&](int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
      res += f[i];
    }
    return res;
  };
  upd(lower_bound(sum.begin(), sum.end(), 0LL) - sum.begin());

  for (int i = 0; i < n; i++) {
    pr += a[i];
    int pos = upper_bound(sum.begin(), sum.end(), pr - t) - sum.begin();
    ans += (i + 1 - get(pos - 1));
    upd(lower_bound(sum.begin(), sum.end(), pr) - sum.begin());
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
