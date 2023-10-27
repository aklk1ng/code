#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum0 = 0;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      sum0++;
    }
    if (x >= 2) {
      ok = true;
    }
  }

  if (sum0 <= (n + 1) / 2) {
    cout << 0 << '\n';
  } else if (ok || sum0 == n) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
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
