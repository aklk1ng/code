#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  auto check = [&](int x, int y) {
    if ((x == 1 || x == n) && (y == 1 || y == m)) {
      return 2;
    } else if (x == 1 || x == n || y == 1 || y == m) {
      return 3;
    } else {
      return 4;
    }

  };

  cout << min(check(x1, y1), check(x2, y2)) << '\n';
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
