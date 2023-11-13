#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      a[i + 1] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    b[i] = b[i - 1] + a[i];
  }

  int l, r;
  while (q--) {
    cin >> l >> r;
    cout << b[r - 1] - b[l - 1] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
