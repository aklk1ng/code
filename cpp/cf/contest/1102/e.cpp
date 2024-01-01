#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> lst;
  vector<int> pos(n);
  for (int i = n - 1; i >= 0; i--) {
    if (!lst.count(a[i])) {
      lst[a[i]] = i;
    }
    pos[i] = lst[a[i]];
  }
  int ans = 1, mx = -1;
  for (int i = 0; i < n - 1; i++) {
    mx = max(mx, pos[i]);
    if (mx == i) {
      ans = (2 * ans) % mod;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
