#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  for (auto &[x, y] : m) {
    pq.push({y, x});
  }

  int ans = n;
  while ((int)pq.size() > 1) {
    auto [x1, y1] = pq.top();
    pq.pop();
    auto [x2, y2] = pq.top();
    pq.pop();
    x1--, x2--;
    ans -= 2;
    if (x1) {
      pq.push({x1, y1});
    }
    if (x2) {
      pq.push({x2, y2});
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
