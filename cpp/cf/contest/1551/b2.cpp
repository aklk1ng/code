#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> indices;
  vector<int> ans(2e5 + 5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if ((int)indices[x].size() < k) {
      indices[x].push_back(i);
    }
  }
  int m = 0;
  for (auto &e : indices) {
    m += e.second.size();
  }
  m -= m % k;
  int color = 0;
  for (auto &e : indices) {
    for (auto &i : e.second) {
      ans[i] = ++color;
      color %= k;
      if (--m == 0) {
        goto output;
      }
    }
  }
output:
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
