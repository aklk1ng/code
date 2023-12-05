#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  int l = 1, r = n * n, t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (t) {
        a[i][j] = l++;
      } else {
        a[i][j] = r--;
      }
      t ^= 1;
    }
    if (i & 1) {
      reverse(a[i].begin(), a[i].end());
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " \n"[j == n - 1];
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
