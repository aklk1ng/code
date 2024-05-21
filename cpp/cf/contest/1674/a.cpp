#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int x, y;
  cin >> x >> y;
  if (y % x != 0) {
    cout << 0 << ' ' << 0 << '\n';
  } else {
    cout << 1 << ' ' << y / x << '\n';
  }
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
