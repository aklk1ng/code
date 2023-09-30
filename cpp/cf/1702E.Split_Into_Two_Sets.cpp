#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e5 + 5;

map<int, vector<int>> mp;
vector<bool> vis;

int go(int x) {
  vis[x] = true;
  for (auto &u : mp[x]) {
    if (!vis[u]) {
      return go(u) + 1;
    }
  }
  return 1;
}

void solve() {
  int n;
  cin >> n;
  mp.clear();
  vis.clear();
  vis.resize(n + 1, false);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    mp[u].push_back(v);
    mp[v].push_back(u);
    if (u == v || mp[u].size() > 2 || mp[v].size() > 2) {
      cout << "No\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i + 1]) {
      if (go(i + 1) % 2) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
