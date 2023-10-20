#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  int x = -1;
  for (int i = 0; i <= n; i++) {
    if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k) {
      x = i;
    }
  }
  if (x == -1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      if (i < x) {
        cout << 1 << ' ';
      } else {
        cout << -1 << ' ';
      }
    }
    cout << '\n';
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
