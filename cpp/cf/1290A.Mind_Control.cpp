#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  k = min(k, m - 1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < m; i++) {
    b.push_back(max(a[i], a[i + n - m]));
  }
  int sz = m - k;
  int ans = 0;
  deque<int> d;
  for (int i = 0, j = 0; i + sz - 1 < m; i++) {
    while (d.size() && d.front() < i) {
      d.pop_front();
    }
    while (j < i + sz) {
      while (d.size() && b[d.back()] >= b[j]) {
        d.pop_back();
      }
      d.push_back(j++);
    }
    ans = max(ans, b[d.front()]);
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
