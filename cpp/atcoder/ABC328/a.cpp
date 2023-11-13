#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t <= x) {
      ans += t;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
