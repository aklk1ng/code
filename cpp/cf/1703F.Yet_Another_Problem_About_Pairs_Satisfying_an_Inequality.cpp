#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) {
      continue;
    }
    ans += (ll)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
    v.push_back(i);
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
