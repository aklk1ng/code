#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  deque<pair<int, int>> d;
  for (int i = 1; i <= n; i++) {
    d.push_back({i, 0});
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      char c;
      cin >> c;
      auto [x, y] = d[0];
      if (c == 'R') {
        d.push_front({x + 1, y});
      } else if (c == 'L') {
        d.push_front({x - 1, y});
      } else if (c == 'U') {
        d.push_front({x, y + 1});
      } else if (c == 'D') {
        d.push_front({x, y - 1});
      }
      d.pop_back();
    } else {
      int x;
      cin >> x;
      x--;
      cout << d[x].first << ' ' << d[x].second << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
