#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  int k = n / m;
  vector<int> a(n);
  vector<vector<int>> val(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    val[a[i] % m].push_back(i);
  }

  ll ans = 0;
  vector<pair<int, int>> t;
  for (int i = 0; i < 2 * m; i++) {
    int cur = i % m;
    while ((int)val[cur].size() > k) {
      int elem = val[cur].back();
      val[cur].pop_back();
      t.push_back({elem, i});
    }
    while ((int)val[cur].size() < k && !t.empty()) {
      auto [x, y] = t.back();
      t.pop_back();
      val[cur].push_back(x);
      a[x] += i - y;
      ans += i - y;
    }
  }

  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
