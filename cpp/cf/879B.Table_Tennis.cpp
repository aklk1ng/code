#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  int mx = -1;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i].first = x;
    a[i].second = 0;
    mx = max(mx, a[i].first);
  }
  int ans = -1;
  if (k >= n - 1) {
    cout << mx << '\n';
  } else {
    while (1) {
      if (a[0] > a[1]) {
        a[0].second++;
        ans = a[0].first;
        if (a[0].second >= k) {
          cout << ans << '\n';
          return;
        }
        rotate(a.begin() + 1, a.begin() + 2, a.end());
      } else {
        a[1].second++;
        ans = a[1].first;
        if (a[1].second >= k) {
          cout << ans << '\n';
          return;
        }
        rotate(a.begin(), a.begin() + 1, a.end());
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
