#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, x;
  cin >> n >> x;
  int sum = 0, l = -1, r = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % x) {
      if (l == -1) {
        l = i;
      }
      r = i;
    }
    sum += a;
  }

  if (sum % x) {
    cout << n << '\n';
  } else if (l == -1) {
    cout << -1 << '\n';
  } else {
    cout << n - min(l + 1, n - r) << '\n';
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
