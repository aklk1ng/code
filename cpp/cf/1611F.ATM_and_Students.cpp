#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll sum = s;
  int i = 0, ans = 0, x = 0, y = 0;
  for (int j = 0; j < n; j++) {
    sum += a[j];
    while (i < n && sum < 0) {
      sum -= a[i++];
    }
    if (sum >= 0) {
      if (ans < (j - i + 1)) {
        ans = j - i + 1;
        x = i + 1;
        y = j + 1;
      }
    }
  }
  if (!ans) {
    cout << -1 << '\n';
  } else {
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
