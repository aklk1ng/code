#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s, t;
  std::cin >> s >> t;

  std::vector<int> p1, p2;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == 'a') {
        p1.push_back(i);
      } else {
        p2.push_back(i);
      }
    }
  }
  if (p1.size() % 2 != p2.size() % 2) {
    std::cout << "-1\n";
    return;
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < p1.size() - 1; i += 2) {
    ans.push_back({p1[i], p1[i + 1]});
  }
  for (int i = 0; i < p2.size() - 1; i += 2) {
    ans.push_back({p2[i], p2[i + 1]});
  }
  if (p1.size() % 2) {
    int x = p1.back(), y = p2.back();
    ans.push_back({x, x});
    ans.push_back({x, y});
  }
  std::cout << ans.size() << '\n';
  for (auto &[x, y] : ans) {
    std::cout << x + 1 << ' ' << y + 1 << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
