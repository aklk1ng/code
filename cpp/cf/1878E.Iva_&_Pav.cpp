#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector pref(n + 1, vector<int>(30));
  auto prepare = [&]() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 30; j++) {
        if (a[i] & (1 << j)) {
          pref[i + 1][j] = pref[i][j] + 1;
        } else {
          pref[i + 1][j] = pref[i][j];
        }
      }
    }
  };

  prepare();
  int q;
  cin >> q;
  while (q--) {
    int l, k;
    cin >> l >> k;
    if (a[l - 1] < k) {
      cout << -1 << ' ';
      continue;
    }
    int lo = l, hi = n, ans = l;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int num = 0;
      for (int j = 0; j < 30; j++) {
        if (pref[mid][j] - pref[l - 1][j] == mid - l + 1) {
          num += (1 << j);
        }
      }
      if (num >= k) {
        lo = mid + 1;
        ans = max(ans, mid);
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
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
