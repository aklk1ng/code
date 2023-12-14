#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int diff = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != a[n + 1 - i][n + 1 - j]) {
        diff++;
      }
    }
  }
  diff /= 2;
  if (diff > k) {
    cout << "No\n";
  } else {
    k -= diff;
    if (n & 1) {
      cout << "Yes\n";
    } else if (k & 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
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
