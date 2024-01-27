#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

int distinct(std::string s) {
  std::sort(s.begin(), s.end());
  return std::unique(s.begin(), s.end()) - s.begin();
}

std::string filter(const std::string &s, char c) {
  std::string t;
  bool ok = false;
  for (auto &e : s) {
    if (e != c && ok) {
      t += e;
    } else if (e == c) {
      ok = true;
    }
  }
  return t;
}

void solve() {
  std::string s;
  std::cin >> s;
  int m = distinct(s);
  std::unordered_set<char> used(s.begin(), s.end());
  std::string t;
  while (m > 0) {
    char mx = -1;
    for (auto &c : used) {
      if (distinct(filter(s, c)) == m - 1){
        mx = std::max(mx, c);
      }
    }
    t += mx;
    s = filter(s, mx);
    used.erase(mx);
    m--;
  }
  std::cout << t << '\n';
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
