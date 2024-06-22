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

  int g = a[0];
  for (int i = 1; i < n; i++) {
    g = __gcd(g, a[i]);
  }

  if (g == 1) {
    cout << 0 << '\n';
  } else if (__gcd(g, n) == 1) {
    cout << 1 << '\n';
  } else if (__gcd(g, n - 1) == 1) {
    cout << 2 << '\n';
  } else {
    cout << 3 << '\n';
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
