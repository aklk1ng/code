#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          ok = true;
        }
      }
    }
  }
  if (ok) {
    cout << 2 << '\n';
  } else {
    cout << 4 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
