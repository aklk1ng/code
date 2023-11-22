#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int m, sum = 0, x0, x1, x2, y0, y1, y2;
  cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;

  m = min(x0, y2);
  x0 -= m;
  y2 -= m;

  m = min(x1, y0);
  x1 -= m;
  y0 -= m;

  m = min(x2, y1);
  x2 -= m;
  y1 -= m;
  sum += 2 * m;

  sum -= 2 * min(x1, y2);
  cout << sum << '\n';
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
