#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if (l1 == r2) {
    cout << r1 << ' ' << l2 << '\n';
  } else {
    cout << l1 << ' ' << r2 << '\n';
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
