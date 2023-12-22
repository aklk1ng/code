#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), c(n + 1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    pq.push(make_pair(c[i], i));
  }

  for (int i = 0; i < m; i++) {
    int t, d;
    cin >> t >> d;
    if (d <= a[t]) {
      a[t] -= d;
      cout << 1LL * d * c[t] << '\n';
    } else {
      bool ok = false;
      ll ans = 1LL * a[t] * c[t];
      d -= a[t];
      a[t] = 0;
      while (!pq.empty()) {
        while (!pq.empty() && a[pq.top().second] == 0) {
          pq.pop();
        }
        if (pq.empty()) {
          break;
        }
        auto now = pq.top();
        if (d <= a[now.second]) {
          a[now.second] -= d;
          ans += 1LL * d * now.first;
          ok = true;
          cout << ans << '\n';
          break;
        } else {
          ans += 1LL * a[now.second] * now.first;
          d -= a[now.second];
          a[now.second] = 0;
          pq.pop();
        }
      }

      if (!ok) {
        cout << 0 << '\n';
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
