#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  map<int, int> m;
  for (auto &[k, v] : cnt) {
    m[v]++;
  }

  int ans = n;
  int l = 0, r = n, len = cnt.size();
  for (auto &[k, v] : m) {
    ans = min(ans, l + r - len * k);
    l += k * v;
    r -= k * v;
    len -= v;
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
