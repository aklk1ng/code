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
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int l = a.size();
  if (l > 3) {
    cout << -1 << '\n';
  } else if (l == 3) {
    if (a[2] - a[1] == a[1] - a[0]) {
      cout << a[2] - a[1];
    } else {
      cout << -1 << '\n';
    }
  } else if (l == 2) {
    if ((a[1] - a[0]) & 1) {
      cout << a[1] - a[0] << '\n';
    } else {
      cout << (a[1] - a[0]) / 2 << '\n';
    }
  } else if (l == 1) {
    cout << 0 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
