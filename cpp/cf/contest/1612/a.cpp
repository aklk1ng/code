#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int x, y;
  cin >> x >> y;
  int ansx = -1, ansy = -1;
  for (int i = 0; i < 51; i++) {
    for (int j = 0; j < 51; j++) {
      if (2 * (i + j) == x + y && 2 * (abs(x - i) + abs(y - j)) == x + y) {
        ansx = i;
        ansy = j;
      }
    }
  }
  cout << ansx << ' ' << ansy << '\n';
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
