#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << "No\n";
    return;
  }
  string a, b;
  cin >> a >> b;
  bool ok = true;
  for (int i = 1; i < (int)b.size(); i++) {
    if (a[i + n - m] != b[i]) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << "No\n";
  } else {
    for (int i = 0; i < n - m + 1; i++) {
      if (a[i] == b[0]) {
        ok = false;
      }
    }
    if (ok) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
