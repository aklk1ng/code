#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(2e5 + 5);
  set<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    q.insert({a[i], i});
  }
  vector<int> ans(2e5 + 5);
  int cnt = 0;
  while (!q.empty()) {
    cnt++;
    auto pos = q.begin()->second;
    ans[pos] = cnt;
    q.erase(q.begin());
    while (true) {
      auto it = q.lower_bound({a[pos] + k + 1, 0});
      if (it == q.end()) {
        break;
      }
      pos = it->second;
      q.erase(it);
      ans[pos] = cnt;
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
