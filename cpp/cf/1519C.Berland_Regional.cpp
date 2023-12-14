#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> s(n), u(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> u[i];
  }

  vector<vector<int>> bst(n);
  for (int i = 0; i < n; i++) {
    bst[s[i]].push_back(u[i]);
  }
  for (int i = 0; i < n; i++) {
    sort(bst[i].begin(), bst[i].end(), greater<int>());
  }

  vector pr(n, vector<ll>(1, 0));
  for (int i = 0; i < n; i++) {
    for (auto &e : bst[i]) {
      pr[i].push_back(pr[i].back() + e);
    }
  }

  vector<ll> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= int(bst[i].size()); j++) {
      ans[j - 1] += pr[i][bst[i].size() / j * j];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
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
