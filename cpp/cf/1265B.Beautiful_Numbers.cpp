#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> p(2e5 + 5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p[x - 1] = i;
  }

  int l = n, r = 0;
  string ans = "";
  for (int i = 0; i < n; i++) {
    l = min(l, p[i]);
    r = max(r, p[i]);
    if (r - l == i) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  cout << ans << '\n';
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
