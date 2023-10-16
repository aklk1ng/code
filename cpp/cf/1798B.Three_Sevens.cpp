#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int m;
  cin >> m;
  vector<vector<int>> a(m);
  map<int, int> last;
  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;
    a[i].resize(n);
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      last[x] = i;
      a[i][j] = x;
    }
  }
  vector<int> ans(m, -1);
  for (int i = 0; i < m; i++) {
    for (auto &e : a[i]) {
      if (last[e] == i) {
        ans[i] = e;
      }
    }
    if (ans[i] == -1) {
      cout << -1 << '\n';
      return;
    }
  }
  for (auto &i : ans) {
    cout << i << " \n"[i == ans.back()];
  }
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
