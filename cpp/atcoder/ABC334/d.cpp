#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  sort(r.begin(), r.end());
  vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + r[i];
  }
  while (q--) {
    ll x;
    cin >> x;
    cout << upper_bound(s.begin(), s.end(), x) - s.begin() - 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
