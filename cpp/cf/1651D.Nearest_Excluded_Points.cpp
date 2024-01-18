#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

vector<int> dx{0, 0, -1, 1};
vector<int> dy{1, -1, 0, 0};

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  set<pair<int, int>> st(a.begin(), a.end());
  map<pair<int, int>, pair<int, int>> ans;
  queue<pair<int, int>> q;
  for (auto &[x, y] : a) {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (st.count({nx, ny})) {
        continue;
      }
      ans[{x, y}] = {nx, ny};
      q.push({x, y});
      break;
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!st.count({nx, ny}) || ans.count({nx, ny})) {
        continue;
      }
      ans[{nx, ny}] = ans[{x, y}];
      q.push({nx, ny});
    }
  }

  for (auto &[x, y] : a) {
    auto e = ans[{x, y}];
    cout << e.first << ' ' << e.second << '\n';
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
