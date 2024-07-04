#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  if (x > y) {
    swap(x, y);
  }
  if (x || !y || (n - 1) % y) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 2; i <= n; i += y) {
    for (int j = 1; j <= y; j++) {
      cout << i << ' ';
    }
  }
  cout << '\n';
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
