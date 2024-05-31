#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (ll i = 1; i <= n; i = i * 10 + 1) {
    for (int j = 1; j <= 9; j++) {
      if (i * j <= n) {
        ans++;
      }
    } 
  }
  cout << ans << '\n';
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
