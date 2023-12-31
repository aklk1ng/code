#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    ans ^= x;
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
