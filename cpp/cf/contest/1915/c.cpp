#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  auto cal = [&](ll x) {
    ll l = 1, r = 1e9;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      if (mid * mid == x) {
        return true;
      } else if (mid * mid > x) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return false;
  };

  if (cal(sum)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
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
