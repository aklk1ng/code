#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b;
  std::cin >> a >> b;
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::vector<int> dx = {-1, 1, -1, 1}, dy = {-1, -1, 1, 1};
  std::set<std::pair<int, int>> st1, st2;
  for (int i = 0; i < 4; i++) {
    st1.insert({x1 + dx[i] * a, y1 + dy[i] * b});
    st2.insert({x2 + dx[i] * a, y2 + dy[i] * b});
    st1.insert({x1 + dx[i] * b, y1 + dy[i] * a});
    st2.insert({x2 + dx[i] * b, y2 + dy[i] * a});
  }

  int ans = 0;
  for (auto &e : st1) {
    if (st2.find(e) != st2.end()) {
      ans++;
    }
  }

  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
