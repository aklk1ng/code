#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  pair<int, int> a = {-1, -1}, b = {-1, -1}, c = {-1, -1}, d = {-1, -1};
  int n, m;
  cin >> n >> m;
  vector grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'B') {
        if (a.first == -1 || i + j > a.first + a.second) {
          a = {i, j};
        }
        if (b.first == -1 || i + j < b.first + b.second) {
          b = {i, j};
        }
        if (c.first == -1 || i - j > c.first - c.second) {
          c = {i, j};
        }
        if (d.first == -1 || i - j < d.first - d.second) {
          d = {i, j};
        }
      }
    }
  }
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);

  int ans = INF;
  pair<int, int> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int dist = 0;
      for (auto &e : v) {
        dist = max(dist, abs(i - e.first) + abs(j - e.second));
      }
      if (dist < ans) {
        ans = dist;
        t = {i, j};
      }
    }
  }
  cout << t.first + 1 << ' ' << t.second + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
