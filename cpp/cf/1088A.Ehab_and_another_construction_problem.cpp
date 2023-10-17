#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int x;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= x; j++) {
      if (i % j == 0 && i * j > x && i / j < x) {
        cout << i << ' ' << j << '\n';
        return;
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
