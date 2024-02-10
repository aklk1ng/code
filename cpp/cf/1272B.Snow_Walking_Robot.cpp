#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  const std::string MOVE = "LRUD";
  int q;
  std::cin >> q;
  while (q--) {
    std::string s;
    std::cin >> s;
    std::map<char, int> cnt;
    for (auto &c : MOVE) {
      cnt[c] = 0;
    }
    for (auto &c : s) {
      cnt[c]++;
    }
    int v = std::min(cnt['U'], cnt['D']);
    int h = std::min(cnt['L'], cnt['R']);
    if (!v || !h) {
      if (!v) {
        h = std::min(h, 1);
        std::cout << 2 * h << '\n';
        std::cout << std::string(h, 'L') + std::string(h, 'R') << '\n';
      } else {
        v = std::min(v, 1);
        std::cout << 2 * v << '\n';
        std::cout << std::string(v, 'U') + std::string(v, 'D') << '\n';
      }
    } else {
      std::string res;
      res += std::string(h, 'L');
      res += std::string(v, 'U');
      res += std::string(h, 'R');
      res += std::string(v, 'D');
      std::cout << res.size() << '\n' << res << '\n';
    }
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
