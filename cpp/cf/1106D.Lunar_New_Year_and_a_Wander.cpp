#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector e(3e5 + 5, vector<int>());
  vector<int> seq;
  vector<bool> vis(3e5 + 5);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vis[1] = true;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(1);

  while (!pq.empty()) {
    int t = pq.top();
    pq.pop();
    seq.push_back(t);
    for (auto &p : e[t]) {
      if (!vis[p]) {
        pq.push(p);
        vis[p] = true;
      }
    }
  }

  for (auto &i : seq) {
    cout << i << " \n"[i == seq.back()];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
