#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pre[i + 1] = pre[i] + x;
  }
  int l = 0, r = 0;
  ll ans = 0;
  set<ll> s = {0};
  while (l < n) {
    while (r < n && !s.count(pre[r + 1])) {
      r++;
      s.insert(pre[r]);
    }
    ans += r - l;
    s.erase(pre[l]);
    l++;
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
