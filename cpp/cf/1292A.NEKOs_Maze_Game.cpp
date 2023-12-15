#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector lava(2, vector<int>(n));
  int ok = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int delta = lava[x][y] == 0 ? 1 : -1;
    lava[x][y] = 1 - lava[x][y];
    for (int i = -1; i <= 1; i++) {
      if (y + i < 0 || y + i >= n) {
        continue;
      }
      if (lava[1 - x][y + i] == 1) {
        ok += delta;
      }
    }
    cout << (ok == 0 ? "Yes" : "No") << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
