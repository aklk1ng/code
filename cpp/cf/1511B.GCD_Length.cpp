#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << '1' + string(a - 1, '0') << ' ' << string(b - c + 1, '1') + string(c - 1, '0') << '\n';
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
