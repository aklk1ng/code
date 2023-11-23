#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n + 1);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    a[i] = ((l - 1) / i + 1) * i;
    ok = ok && a[i] <= r;
  }
  if (ok) {
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " \n"[i == n];
    }
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
