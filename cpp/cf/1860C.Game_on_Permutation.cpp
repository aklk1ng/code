#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  int mi = n + 1, mx = n + 1;
  while (n--) {
    int x;
    cin >> x;
    if (mi < x && x < mx) {
      ans += 1;
      mx = x;
    }
    mi = min(mi, x);
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
