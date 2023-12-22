#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int q;
  cin >> q;
  unordered_map<ll, ll> m;
  auto cal = [&](ll v, ll u, ll w = -1) {
    ll ans = 0;
    while (v != u) {
      if (v < u) {
        swap(v, u);
      }
      if (m.find(v) != m.end()) {
        ans += m[v];
      }
      if (~w) {
        m[v] += w;
      }
      v >>= 1;
    }
    return ans;
  };
  while (q--) {
    int op;
    ll v, u;
    cin >> op >> v >> u;
    if (op == 1) {
      ll w;
      cin >> w;
      cal(v, u, w);
    } else {
      cout << cal(v, u) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
