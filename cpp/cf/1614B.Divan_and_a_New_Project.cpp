#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = {x, i};
  }
  sort(a.begin(), a.end());
  ll curx = 1, dis = 0;
  vector<ll> ans(n, 1e9);
  for (int i = n - 1; i >= 0; i--) {
    auto [x, y] = a[i];
    ans[y] = curx;
    dis += abs(curx) * 2 * x;
    if (curx > 0) {
      curx = -curx;
    } else {
      curx = -curx + 1;
    }
  }

  cout << dis << '\n';
  cout << 0;
  for (int i = 0; i < n; i++) {
    cout << ' ' << ans[i];
  }
  cout << '\n';
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
