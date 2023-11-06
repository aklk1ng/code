#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  bool ok = false;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == b[i] && a[i] == '0' && a[i + 1] == b[i + 1] && a[i + 1] == '1') {
      ok = true;
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
