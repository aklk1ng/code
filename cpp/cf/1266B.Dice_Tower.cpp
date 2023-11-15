#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll x;
  cin >> x;
  int t = x % 14;
  if (x > 14 && t <= 6 && t >= 1) {
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
