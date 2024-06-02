#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> k(n), h(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<pair<ll, ll>> st;
  for (int i = 0; i < n; i++) {
    st.push_back({k[i] - h[i], k[i]});
  }
  sort(st.begin(), st.end());
  ll l = -1, r = -1;
  ll ans = 0;
  for (auto &e : st) {
    if (e.first >= r) {
      ans += (r - l) * (r - l + 1) / 2;
      l = e.first;
      r = e.second;
    } else {
      r = max(r, e.second);
    }
  }
  ans += (r - l) * (r - l + 1) / 2;
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
