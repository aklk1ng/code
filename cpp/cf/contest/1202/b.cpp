#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(4 * n);
  for (int i = 0; i < 4 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int area = a[0] * a.back();
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int l = 2 * i, r = 4 * n - (2 * i) - 1;
    if (a[l] != a[l + 1] || a[r] != a[r - 1] || a[l] * a[r] * 1LL != area) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
