#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int k, g, m;
  cin >> k >> g >> m;
  int glass = g, mug = m;
  while (k--) {
    if (glass == g) {
      glass = 0;
    } else if (mug == 0) {
      mug = m;
    } else {
      int diff = min(mug, g - glass);
      glass += diff;
      mug -= diff;
    }
  }
  cout << glass << ' ' << mug << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
