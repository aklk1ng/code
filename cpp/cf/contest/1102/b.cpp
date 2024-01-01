#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  vector<vector<int>> t(k);
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    t[i % k].push_back(a[i].first);
    res[a[i].second] = i % k;
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < int(t[i].size()) - 1; ++j) {
      if (t[i][j] == t[i][j + 1]) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << res[i] + 1 << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
