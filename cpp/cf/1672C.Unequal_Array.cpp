#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mi = -1, mx = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      if (mi == -1) {
        mi = i;
      }
      mx = i;
    }
  }
  if (mi == mx) {
    cout << 0 << '\n';
  } else {
    cout << max(1, mx - mi - 1) << '\n';
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
