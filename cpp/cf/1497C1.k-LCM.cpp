#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  if (n % 2) {
    cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
  } else if (n % 2 == 0 && n % 4) {
    cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2 - 1 << '\n';
  } else {
    cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
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
