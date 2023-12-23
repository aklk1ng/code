#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector g(n, vector<int>());
  vector<int> rem(n), layer(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
    rem[x]++;
    rem[y]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (rem[i] == 1) {
      q.push(i);
      layer[i] = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : g[u]) {
      if (rem[v] != 1) {
        rem[v]--;
        if (rem[v] == 1) {
          layer[v] = layer[u] + 1;
          q.push(v);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (layer[i] > k) {
      ans++;
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
