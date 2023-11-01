#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0, r = n - 1;
  int mi = 1, mx = n;
  while (l <= r) {
    if (a[l] == mi) {
      l++;
      mi++;
    } else if (a[l] == mx) {
      l++;
      mx--;
    } else if (a[r] == mi) {
      r--;
      mi++;
    } else if (a[r] == mx) {
      r--;
      mx--;
    } else {
      break;
    }
  }

  if (l <= r) {
    cout << l + 1 << ' ' << r + 1 << '\n';
  } else {
    cout << -1 << '\n';
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
