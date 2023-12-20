#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n - 1);
  for (int i = 1; i < n - 1; i++) {
    p[i] = p[i - 1] + (a[i - 1] >= a[i] && a[i] >= a[i + 1]);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l == r) {
      cout << 1 << '\n';
    } else {
      cout << (r - l + 1) - p[r - 1] + p[l] << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
