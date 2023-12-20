#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> w(n + 1), deg(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++, deg[v]++;
  }

  ll ans = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < deg[i]; j++) {
      v.push_back(w[i]);
    }
    ans += w[i];
  }
  sort(v.rbegin(), v.rend());
  for (auto &e : v) {
    cout << ans << ' ';
    ans += e;
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
