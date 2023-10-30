#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> res(n);
  for (int i = 0; i < m - 1; i++) {
    res[0] += abs(a[i] - a[i + 1]);
  }

  vector<int> cnt(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m - 1; i++) {
    int l = a[i], r = a[i + 1];
    if (l != r) {
      adj[l].push_back(r);
      adj[r].push_back(l);
    }
    if (l > r) {
      swap(l, r);
    }
    if (r - l < 2) {
      continue;
    }
    cnt[l + 1]++;
    cnt[r]--;
  }

  for (int i = 0; i < n - 1; i++) {
    cnt[i + 1] += cnt[i];
  }
  for (int i = 0; i < n; i++) {
    res[i] = res[0] - cnt[i];
    for (auto &e : adj[i]) {
      res[i] -= abs(i - e);
      res[i] += e + (e < i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
