#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  std::set<std::string> s1;
  std::set<std::string> s2;
  std::vector<bool> u(2);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    if (s[i][0] == '0' && s[i].back() == '1') {
      s1.insert(s[i]);
    }
    if (s[i][0] == '1' && s[i].back() == '0') {
      s2.insert(s[i]);
    }
    u[s[i][0] - '0'] = u[s[i].back() - '0'] = true;
  }
  if (u[0] && u[1] && s1.empty() && s2.empty()) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<int> rev;
  if (s1.size() > s2.size() + 1) {
    for (int i = 0; i < n; i++) {
      if (s[i][0] == '0' && s[i].back() == '1') {
        std::string t(s[i]);
        reverse(t.begin(), t.end());
        if (!s2.count(t)) {
          rev.push_back(i);
        }
      }
    }
  } else if (s2.size() > s1.size() + 1) {
    for (int i = 0; i < n; i++) {
      if (s[i][0] == '1' && s[i].back() == '0') {
        std::string t(s[i]);
        reverse(t.begin(), t.end());
        if (!s1.count(t)) {
          rev.push_back(i);
        }
      }
    }
  }

  int ans = std::max(0, (std::max((int)s1.size(), (int)s2.size()) -
                         std::min((int)s1.size(), (int)s2.size())) /
                            2);
  std::cout << ans << '\n';
  for (int i = 0; i < ans; i++) {
    std::cout << rev[i] + 1 << ' ';
  }
  std::cout << '\n';
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
