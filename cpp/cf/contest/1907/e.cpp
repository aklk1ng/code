#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  ll ans = 1;
  while (n > 0) {
    int d = n % 10;
    n /= 10;
    ll mul = 0;
    for (int i = 0; i <= d; i++) {
      for (int j = 0; j <= d; j++) {
        if (d - i - j >= 0) {
          mul += 1;
        }
      }
    }
    ans *= mul;
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
