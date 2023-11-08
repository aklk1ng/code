#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n;
  cin >> n;
  int cnt2 = 0, cnt3 = 0, cnt5 = 0;
  while (n % 2 == 0) {
    n /= 2;
    cnt2++;
  }
  while (n % 3 == 0) {
    n /= 3;
    cnt3++;
  }
  while (n % 5 == 0) {
    n /= 5;
    cnt5++;
  }
  if (n != 1) {
    cout << -1 << '\n';
  } else {
    cout << cnt2 + 2 * cnt3 + 3 * cnt5 << '\n';
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
