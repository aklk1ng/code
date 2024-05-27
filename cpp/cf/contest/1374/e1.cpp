#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> t(4), sums(4);
  for (int i = 0; i < n; i++) {
    int x, a, b;
    cin >> x >> a >> b;
    t[2 * a + b].push_back(x);
  }
  for (int i = 0; i < 4; i++) {
    sort(t[i].begin(), t[i].end());
    sums[i].push_back(0);
    for (auto &e : t[i]) {
      sums[i].push_back(sums[i].back() + e);
    }
  }

  int ans = 2e9 + 5;
  for (int i = 0; i < min(k + 1, int(sums[3].size())); i++) {
    if (k - i < (int)sums[1].size() && k - i < (int)sums[2].size()) {
      ans = min(ans, sums[3][i] + sums[1][k - i] + sums[2][k - i]);
    }
  }
  cout << (ans == 2e9 + 5 ? -1 : ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
