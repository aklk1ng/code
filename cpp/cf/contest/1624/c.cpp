#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> vis(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  bool ok = true;
  for (auto &e : a) {
    int x = e;
    while (x > n || vis[x]) {
      x /= 2;
    }
    if (x > 0) {
      vis[x] = true;
    } else {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
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
