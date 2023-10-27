#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n & 1) {
    cout << 4 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << n - 1 << ' ' << n << '\n';
    cout << n - 1 << ' ' << n << '\n';
  } else {
    cout << 2 << '\n';
    cout << 1 << ' ' << n << '\n';
    cout << 1 << ' ' << n << '\n';
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
